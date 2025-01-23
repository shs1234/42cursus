import json
import asyncio
from asgiref.sync import sync_to_async
from channels.generic.websocket import AsyncWebsocketConsumer
from django.conf import settings
from .models import GameSession, Player
from .service import GameServiceSingleton
import time
from threading import Lock

io_mutex = Lock()
game_consumers = {}

game_consumer_test = None
session_timers = {}
dx = {}


class GameConsumer(AsyncWebsocketConsumer):
    latency_start_time = None
    username = None
    session_id = None

    def __del__(self):
        # 객체가 소멸될 때 호출되는 메서드
        print(f"Cleaning up GameConsumer for session {getattr(self, 'session_id', 'Unknown')} and user {getattr(self, 'username', 'Unknown')}")
        
        # 필요한 정리 작업 수행
        if hasattr(self, 'ping_task') and self.ping_task:
            self.ping_task.cancel()
        if game_consumers.get(self.username):
            with io_mutex:
                del game_consumers[self.username]
        if dx.get(self.username):
            del dx[self.username]
        if self.session_id in session_timers:
            session_timers[self.session_id].cancel()
            del session_timers[self.session_id]

    async def send_message(self, message):
        await self.send(text_data=json.dumps({"message": message}))

    # async def measure_latency(self):
    #     while True:
    #         self.latency_start_time = time.time()

    #         await self.send(text_data=json.dumps({"type": "ping"}))
    #         await asyncio.sleep(2)
    
    @sync_to_async
    def get_session(self):
        return GameSession.objects.filter(session_id=self.session_id).first()

    @sync_to_async
    def get_player(self, username):
        return Player.objects.filter(username=username).first()

    @sync_to_async
    def create_player(self, username):
        return Player.objects.create(username=username)

    @sync_to_async
    def session_player_exists(self, session, username):
        return session.players.filter(username=username).exists()

    @sync_to_async
    def add_player_to_session(self, session, player):
        # session.players.add(player)
        session.players_connected.add(player)
        session.is_active = True
        session.save()

    async def IsSessionFull(self):
        session = await self.get_session()
        if session:
            if await sync_to_async(session.players.count)() == 4:
                return True
            else:
                return False
        else:
            return False

    async def IsUserInSession(self, user):
        session = await self.get_session()
        player = await self.get_player(user.username)
        
        if session and player:
            if await self.session_player_exists(session, user.username):
                await self.add_player_to_session(session, player)
                return True
        return False

    async def remove_user_from_session(self, user):
        session = await self.get_session()
        if session:
            player = await self.get_player(user.username)
            print(f"Removing User {player.username}")
            if player:
                player_exists = await sync_to_async(session.players_connected.filter(username=user.username).exists)()
                if player_exists:
                    print("Removing player from session players_connected")
                    await sync_to_async(session.players_connected.remove)(player)
                    await sync_to_async(session.save)()
                else:
                    print(f"Player {player.username} not found in session players_connected")
            else:
                print(f"Player {user.username} does not exist")
        else:
            print("Session does not exist")

    async def connect(self):
        user = self.scope["user"]
        if user.is_anonymous:
            await self.close()
            print("User is anonymous")
            return
        
        self.session_id = self.scope["url_route"]["kwargs"]["session_id"]
        self.roomGroupName = f"game_{self.session_id}"
        self.username = user.username
        self.user_channel_name = f"user_{self.session_id}_{self.username}"

        print(f"User {self.username} connected to session {self.session_id}")

        from .service import game_mutex
        if game_mutex is None:
            print("Global game_mutex not found")
            await self.close()
            return
        else:
            self.game_mutex = game_mutex[self.session_id]

        from .service import session_queues

        if session_queues:
            self.queue = session_queues.get(self.session_id)
        else:
            self.queue = None

        if self.queue is None:
            print(f"Session {self.session_id} does not exist")
            await self.close()
            return

        if await self.IsUserInSession(user):
            with io_mutex:
                game_consumers[self.username] = self

            await self.channel_layer.group_add(
                self.roomGroupName,
                self.channel_name
            )
            await self.channel_layer.group_add(
                self.user_channel_name,
                self.channel_name
            )
            await self.accept()

            bIsFull = await self.IsSessionFull()
            if bIsFull:
                print(f"Session {self.session_id} is full. Starting game...")
                await self.start_game(self.session_id)
                if self.session_id in session_timers:
                    session_timers[self.session_id].cancel()
                    del session_timers[self.session_id]
            else:
                if self.session_id not in session_timers:
                    timer_task = asyncio.create_task(self.start_game_after_timeout())
                    session_timers[self.session_id] = timer_task
        else:
            await self.close()

    async def disconnect(self, close_code):
        if hasattr(self, 'ping_task') and self.ping_task:
            self.ping_task.cancel()
        if game_consumers.get(self.username):
            with io_mutex:
                del game_consumers[self.username]
        if dx.get(self.username):
            del dx[self.username]

        user = self.scope["user"]
        if user and not user.is_anonymous:
            await self.remove_user_from_session(user)
        await self.channel_layer.group_discard(
            self.roomGroupName,
            self.channel_name
        )
        await self.channel_layer.group_discard(
            self.user_channel_name,
            self.channel_name
        )

    async def receive(self, text_data):
        text_data_json = json.loads(text_data)
        
        if "type" in text_data_json and text_data_json["type"] == "pong":
            if self.latency_start_time:
                latency = (time.time() - self.latency_start_time)

                Service = GameServiceSingleton()
                Service.set_latency(self.session_id, self.username, latency)

                print(f"Latency: {latency}")
                self.latency_start_time = None
            return json.dumps({"type": "pong"})
        else:
            username = text_data_json.get("username")
            action = text_data_json.get("action")

            if username and action:
                if action == "l":
                    dx[self.username] = -5
                elif action == "r":
                    dx[self.username] = 5

    async def sendMessage(self, event):
        message = event["message"]
        await self.send(text_data=json.dumps({"message": message}))

    async def start_game(self, session_id):
        GameServiceSingleton().start_game(session_id)
        print(f"Game started for session {session_id}")

    async def start_game_after_timeout(self):
        try:
            await asyncio.sleep(5)
            print(f"Session {self.session_id} did not fill up in time. Starting game...")
            await self.start_game(self.session_id)
        except asyncio.CancelledError:
            print(f"Session {self.session_id} was filled in time. Timer cancelled.")
        finally:
            if self.session_id in session_timers:
                del session_timers[self.session_id]

    async def disconnect_message(self, event):
        print(f"Disconnect message received for user {self.username}")
        # self.close()
