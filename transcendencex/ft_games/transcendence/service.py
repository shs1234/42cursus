import asyncio
import json
import queue
import time
import copy
from concurrent.futures import ThreadPoolExecutor
from django.conf import settings
from queue import Queue
from django.apps import apps  # Django 앱을 지연 초기화하는데 사용
from .logics import GameLogic
from threading import Event
from threading import Lock
import threading
from channels.layers import get_channel_layer
from asgiref.sync import async_to_sync
from .models import GameSession, Player
from .db_worker import DBWorker
from collections import deque

session_queues = {}
game_mutex = {}

class MatchMetaData:
    def __init__(self):
        self.id = None
        self.player = []
        self.GameLogic = None
        self.winner = None
    
        def __str__(self):
            players_str = " vs ".join(self.player) if self.player else "Unknown players"
            winner_str = f"Winner: {self.winner}" if self.winner else "No winner yet"

            return (
                f"Match ID: {self.id or 'Unknown ID'}\n"
                f"Players: {players_str}\n"
                f"{winner_str}\n"
            )

        def __repr__(self):
            return self.__str__()

class GameService:
    def __init__(self):
        self.matches = {}
        self.player_controller = {}
        self.match_num = 0
        self.match_done = 0
        self.winner_queue = Queue()
        self.history = []
        self.average_latency = 0
        self.session_done = False
        self.session_id = None
        self.apply_count = 0
    

    def calculate_latency(self, latency):
        if not latency:  # latency 리스트가 비어있는지 확인
            self.average_latency = 0
            print("No latency data available to calculate.")
            return

        total_latency = 0
        for pair in latency:
            total_latency += pair["latency"]

        self.average_latency = total_latency / len(latency)
        if self.average_latency >= 0.1:
            self.average_latency = 0.1
        elif self.average_latency < 0.05:
            self.average_latency = 0.05

    # def run(self, session_id, double_queue, mutex, db_worker, latency):
    def run(self, session_id, double_queue, mutex, db_worker):
        self.session_id = session_id
        while not self.session_done:
            # self.calculate_latency(latency)
            # print("Average Latency: ", self.average_latency)
            if not self.matches:
                print("Setting match")
                self.set_match(session_id)
            else:
                self.update_match(session_id, double_queue, mutex)
                # time.sleep(self.average_latency)
                time.sleep(0.02)
        print("Session ended")
        # 세션 종료 후에는 모든 게임 정보를 DB에 저장함
        self.send_session_end_message(session_id)
        self.close_all_connections(session_id)
        self.save_game_history(db_worker)
        self.session_db_flush(session_id)

    def close_all_connections(self, session_id):
        from .consumer import game_consumers 
        from .consumer import io_mutex

        session = GameSession.objects.get(session_id=self.session_id)
        players = session.players.all()
        players_username = [player.username for player in players]
        # connected_players = session.players_connected.all()
        # connected_player_usernames = [player.username for player in connected_players]

        for player in players_username:
            with io_mutex:
                if player in game_consumers:
                    print(f"Closing connection for {player}")
                    consumer_instance = game_consumers[player]
                    async_to_sync(consumer_instance.disconnect_message)({
                        "type": "disconnect_message",  # 메시지 타입 정의
                        "message": f"Session {session_id} ended"
                    })
        time.sleep(5)

    def session_db_flush(self, session_id):
        try:
            session = GameSession.objects.filter(session_id=session_id).first()
            if session:
                print("Flushing session")
                session.is_active = False
                # players = session.players.all()
                # for player in players:
                #     player.delete()
                session.players.clear()
                session.players_connected.clear()
                session.save()
        except Exception as e:
            print(f"Error occurred1: {e}")

    def make_match(self, matchId, player1, player2=None):
        match = MatchMetaData()
        match.id = matchId
        match.GameLogic = GameLogic()
        match.GameLogic.matchId = matchId
        match.player.append(player1)
        self.player_controller[player1] = match.GameLogic.player[0]
        if player2:
            match.player.append(player2)
            self.player_controller[player2] = match.GameLogic.player[1]
        else:
            match.GameLogic.isComputer = True
            match.player.append("Computer")
        match.GameLogic.attach(self)
        self.send_start_message(match)
        return match

    def set_match(self, session_id):
        try:
            GameSession = apps.get_model('transcendence', 'GameSession')

            session = GameSession.objects.get(session_id=session_id)

            # Version : Test
            # players = session.players.all()
            # Version : Real
            players = session.players_connected.all()

            if len(players) < 2:
                match = self.make_match('A', players[0].username)
                self.matches['A'] = match
                self.match_num += 1
            if len(players) >= 2:
                match = self.make_match('A', players[0].username, players[1].username)
                self.matches['A'] = match
                self.match_num += 1
            if len(players) == 3:
                match = self.make_match('B', players[2].username)
                self.matches['B'] = match
                self.match_num += 1
            if len(players) == 4:
                match = self.make_match('B', players[2].username, players[3].username)
                self.matches['B'] = match
                self.match_num += 1
        except Exception as e:
            print(f"Error occurred2: {e}")

    def update_match(self, session_id, double_queue, mutex):
        # 0 -> read, 1 -> write
        # with mutex:
        # current_queue = double_queue[0]
        # double_queue[0] = double_queue[1]
        # double_queue[1] = current_queue

        # # 0번 큐에서 메시지를 모두 읽어 들이기
        # # 큐에서 메시지를 읽어들이고 처리
        # while current_queue:
        #     data = current_queue.popleft()  # deque에서 데이터 꺼냄
            
        #     # 데이터를 JSON으로 파싱
        #     data_json = json.loads(data)

        #     # username과 action을 추출
        #     username = data_json.get("username")
        #     action = data_json.get("action")

        #     if username and action:
        #         if username in self.player_controller:
        #             player = self.player_controller[username]
        #             if action == "l":
        #                 player.dx = -5
        #             elif action == "r":
        #                 player.dx = 5

        from .consumer import dx

        

        for username, player in self.player_controller.items():
            # dx에서 해당 username에 대한 값을 가져옴
            player_dx = dx.get(username, 0)  # dx에 해당 username이 없으면 기본값으로 0을 반환

            # player_dx를 사용하여 필요한 작업 수행
            # 예를 들어, 플레이어의 dx 값을 업데이트할 수 있습니다.
            player.dx = player_dx

            self.apply_count += 1

            if self.apply_count == 5:
                # dx[username] = 0  # dx를 0으로 초기화
                self.apply_count = 0
        
        # 게임 로직 업데이트
        try:
            for game in self.matches.values():
                self.send_update_message(session_id, game)
                game.GameLogic.update()
        except Exception as e:
            print(f"Error occurred3: {e}")

    def send_session_end_message(self, session_id):
        # 세션이 끝났음을 클라이언트에게 알리는 로직
        channel_layer = get_channel_layer()

        message = json.dumps({
            "event": "session_end"
        })

        async_to_sync(channel_layer.group_send) (
            f"game_{session_id}",
            {
                "type": "sendMessage",
                "message": message
            }
        )

    def send_start_message(self, match):
        # 게임이 시작되었다는 메시지를 클라이언트에게 전송하는 로직
        channel_layer = get_channel_layer()

        players = match.player
        player1_info = {
            "username": players[0],
            "paddle_pos": {
                "x": match.GameLogic.player[0].x,
                "y": match.GameLogic.player[0].y
            },
            "score": match.GameLogic.player_score[0]
        }

        player2_info = {
            "username": players[1],
            "paddle_pos": {
                "x": match.GameLogic.player[1].x,
                "y": match.GameLogic.player[1].y
            },
            "score": match.GameLogic.player_score[1]
        }

        game_state = {
            "matchId": match.id,
            "player1": player1_info,
            "player2": player2_info,
            "event": "start"
        }

        message = json.dumps(game_state)

        session = GameSession.objects.get(session_id=self.session_id)
        connected_players = session.players_connected.all()
        connected_player_usernames = [player.username for player in connected_players]

        for (i, player) in enumerate(match.player):
            if player == "Computer":
                continue
            if not player in connected_player_usernames:
                continue
            user_channel_name = f"user_{self.session_id}_{player}"

            async_to_sync(channel_layer.group_send) (
                user_channel_name,
                {
                    "type": "sendMessage",
                    "message": message
                }    
            )


    def send_update_message(self, session_id, match):
        # 게임 상태를 클라이언트에게 전송하는 로직
        channel_layer = get_channel_layer()

        players = match.player
        player1_info = {
            "username": players[0],
            "paddle_pos": {
                "x": match.GameLogic.player[0].x,
                "y": match.GameLogic.player[0].y
            },
            "score": match.GameLogic.player_score[0]
        }

        player2_info = {
            "username": players[1],
            "paddle_pos": {
                "x": match.GameLogic.player[1].x,
                "y": match.GameLogic.player[1].y
            },
            "score": match.GameLogic.player_score[1]
        }

        ball_info = {
            "pos": {
                "x": match.GameLogic.ball.x,
                "y": match.GameLogic.ball.y
            }
        }

        game_state = {
            "matchId": match.id,
            "player1": player1_info,
            "player2": player2_info,
            "ball": ball_info
        }

        message = json.dumps(game_state)

        from .consumer import game_consumers 
        from .consumer import io_mutex
        # from .consumer import game_consumer_test

        session = GameSession.objects.get(session_id=self.session_id)
        connected_players = session.players_connected.all()
        connected_player_usernames = [player.username for player in connected_players]

        for (i, player) in enumerate(match.player):
            if player == "Computer":
                continue
            if not player in connected_player_usernames:
                continue
            with io_mutex:
                if player in game_consumers:
                    consumer_instance = game_consumers[player]
                    async_to_sync(consumer_instance.send_message)(message)

        # if game_consumer_test:
        #     async_to_sync(game_consumer_test.send_message)(message)
            
            # user_channel_name = f"user_{self.session_id}_{player}"

            # async_to_sync(channel_layer.group_send) (
            #     user_channel_name,
            #     {
            #         "type": "sendMessage",
            #         "message": message
            #     }    
            # )

    def send_finish_message(self, match, winner):
        # 게임이 끝났다는 메시지를 클라이언트에게 전송하는 로직
        channel_layer = get_channel_layer()

        players = match.player

        winner_info = {
            "matchId": match.id,
            "winner": players[winner]
        }

        message = json.dumps(winner_info)

        session = GameSession.objects.get(session_id=self.session_id)
        connected_players = session.players_connected.all()
        connected_player_usernames = [player.username for player in connected_players]

        for (i, player) in enumerate(match.player):
            if player == "Computer":
                continue
            if not player in connected_player_usernames:
                continue
            user_channel_name = f"user_{self.session_id}_{player}"
            print(f"Sending finish message to {user_channel_name}")
            async_to_sync(channel_layer.group_send) (
                user_channel_name,
                {
                    "type": "sendMessage",
                    "message": message
                }    
            )

    # 게임이 끝났을 때 호출되는 함수
    def update(self, matchId, winner):
        print(f"Match {matchId} ended")
        finished_match = self.matches.pop(matchId)
        self.match_done += 1
        self.winner_queue.put(finished_match.player[winner])
        # 게임이 끝났다는 것을 클라이언트에게 알리는 로직 필요함
        self.send_finish_message(finished_match, winner)
        
        # 게임의 정보를 기록하는 로직
        finished_match.GameLogic.detach(self)
        finished_match.GameLogic = None
        finished_match.winner = finished_match.player[winner]
        print(f"Winner: {finished_match.winner}")
        self.history.append(finished_match)
        
        # 결승전을 세팅함
        if self.match_done == self.match_num and self.match_num == 2:
            match = self.make_match('F', self.winner_queue.get(), self.winner_queue.get())
            self.matches['F'] = match
        elif self.match_done == self.match_num and self.match_num == 1:
            # 애초에 매치가 1개밖에 없었을 경우
            print("Only one match")
            self.match_done = 0
            self.match_num = 0
            self.session_done = True
        # 결승전이 끝났을 경우의 로직을 작성함
        if (matchId == 'F'):
            self.session_done = True
    
    def save_game_history(self, db_worker):
        # 게임의 히스토리를 DB에 저장하는 로직
        # TODO: GameHistory 모델을 만들어야 함
        copied_history = copy.deepcopy(self.history)
        db_worker.match_history.put(copied_history)
        db_worker.event.set()  # DB에 저장하라고 알림


class GameServiceSingleton:
    _instance = None
    _initialized = False
    _service_started = False

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(GameServiceSingleton, cls).__new__(cls)
        return cls._instance

    def __init__(self):
        if not self._initialized:
            self.bGameStarted = {}
            self.events = {}
            self.mutex = {}
            self.session_queues = {}
            self.latency = {}
            self.db_worker = DBWorker()
            self._initialized = True

    def start_service(self):
        # Django 앱이 완전히 로드된 후에 모델을 가져오기 위해 apps.get_model 사용
        print("Starting game service...")

        try:
            GameSession = apps.get_model('transcendence', 'GameSession')
            num_sessions = 8
            websocket_url = "127.0.0.1"
            websocket_port = 8002

            # 기존 세션 삭제
            GameSession.objects.all().delete()

            executor = ThreadPoolExecutor(max_workers=num_sessions)
            # session_queues = {}

            for i in range(num_sessions):
                session_id = f"session_{i+1}"
                GameSession.objects.create(
                    session_id=session_id,
                    websocket_url=websocket_url,
                    websocket_port=websocket_port,
                    is_active=False
                )

                queue_read = deque(maxlen=100)
                queue_write = deque(maxlen=100)

                self.bGameStarted[session_id] = False

                session_queues[session_id] = [queue_read, queue_write]
                
                self.events[session_id] = Event()

                game_mutex[session_id] = Lock()
                executor.submit(self.session_thread, session_id, session_queues[session_id], game_mutex[session_id])

            return session_queues
        
        except Exception as e:
            print(f"Error starting game service: {e}")
         # Django 앱이 완전히 로드된 후에 모델을 가져오기 위해 apps.get_model 사용
        # print("Starting game service...")

        # try:
        #     GameSession = apps.get_model('transcendence', 'GameSession')
        #     num_sessions = 8
        #     websocket_url = "127.0.0.1"
        #     websocket_port = 8002

        #     # 기존 세션 삭제
        #     GameSession.objects.all().delete()

        #     # 스레드 리스트 생성
        #     threads = []

        #     for i in range(num_sessions):
        #         session_id = f"session_{i+1}"
        #         GameSession.objects.create(
        #             session_id=session_id,
        #             websocket_url=websocket_url,
        #             websocket_port=websocket_port,
        #             is_active=False
        #         )

        #         queue_read = deque(maxlen=100)
        #         queue_write = deque(maxlen=100)

        #         self.bGameStarted[session_id] = False

        #         session_queues[session_id] = [queue_read, queue_write]
        #         self.events[session_id] = Event()
        #         game_mutex[session_id] = Lock()

        #         # 스레드 생성 및 시작
        #         thread = threading.Thread(
        #             target=self.session_thread, 
        #             args=(session_id, session_queues[session_id], game_mutex[session_id])
        #         )
        #         thread.start()

        #         # 스레드 리스트에 추가
        #         threads.append(thread)

        #     # 모든 스레드가 끝날 때까지 대기
        #     for thread in threads:
        #         thread.join()

        #     return session_queues
        
        except Exception as e:
            print(f"Error starting game service: {e}")

    def session_thread(self, session_id, double_queue, mutex):
        while True:
            self.events[session_id].wait()
            print("Game started")
            start_time = time.time()
            Service = GameService()
            # Service.run(session_id, double_queue, mutex, self.db_worker, self.latency[session_id])
            Service.run(session_id, double_queue, mutex, self.db_worker)
            end_time = time.time()
            print(f"Session {session_id} ended in {end_time - start_time} seconds")
            self.events[session_id].clear()

    def get_session_queues(self):
        return self.session_queues

    def start_game(self, session_id):
        # if session_id in self.session_queues:
        if session_id in session_queues:
            self.bGameStarted[session_id] = True
            self.events[session_id].set()
            print(f"Starting game in session {session_id}")
        else:
            print(f"Session {session_id} not found")
    
    def set_max_match(self, max_match):
        self.max_match = max_match

    def set_latency(self, session_id, username, latency):
        if session_id not in self.latency:
            self.latency[session_id] = []

        updated = False
        for pair in self.latency[session_id]:
            if pair["username"] == username:
                pair["latency"] = latency  # 기존 값 업데이트
                updated = True
                break

        # username이 기존 리스트에 없으면 새로 추가
        if not updated:
            self.latency[session_id].append({"username": username, "latency": latency})

        print(f"Updated Latency for Session {session_id}: {self.latency[session_id]}")
