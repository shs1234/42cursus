import json
from channels.generic.websocket import AsyncWebsocketConsumer
from room.models import Room
from room.serializers import RoomSerializer
from channels.db import database_sync_to_async
from django.core.exceptions import ValidationError
import random
import string
import aiohttp
from urllib.parse import parse_qs

class ChatConsumer(AsyncWebsocketConsumer):
    async def connect(self):
        self.room_name = self.scope["url_route"]["kwargs"]["room_name"]
        self.room_group_name = f"chat_{self.room_name}"
        
        username = self.get_username()

        # 방 존재 여부 확인, 인원 수 확인

        try:
            await self.can_connect(self.room_name)
        except ValidationError as e:
            await self.close()
            return
        
        # 방 그룹에 연결
        await self.channel_layer.group_add(self.room_group_name, self.channel_name)

        # 방 참가(DB 업데이트)
        await self.action_join(self.room_name, username)

        room_data = await self.get_room_data(self.room_name)
        # 방 참가 메시지 전송
        message = self.create_message("join", f"{username} has joined the room.", room_data)
        await self.channel_layer.group_send(self.room_group_name, {"type": "chat.message", "message": message})

        # WebSocket 연결 수락
        await self.accept()

    async def disconnect(self, close_code):
        # 방 그룹에서 나가기(DB 업데이트)
        username = self.get_username()
        await self.action_leave(self.room_name, username)

        # 방 나가기 메시지 전송
        room_data = await self.get_room_data(self.room_name)
        if room_data is not None:
            return
        message = self.create_message("leave", f"{username} has left the room.", room_data)
        await self.channel_layer.group_send(self.room_group_name, {"type": "chat.message", "message": message})

        # 방 그룹에서 연결 해제
        await self.channel_layer.group_discard(self.room_group_name, self.channel_name)

    # WebSocket으로부터 메시지 받기
    async def receive(self, text_data):
        text_data_json = json.loads(text_data)
        action = text_data_json["action"]

        username = self.get_username()

        # 방 그룹에 단순 메시지 보내기
        if action == "message":
            message = text_data_json["text"]
            message = self.create_message(action, f"{username}: {message}", None)

        # start 버튼 클릭 시
        elif action == "start":
            try:
                room_data = await self.action_start(self.room_name)

                players = await self.get_players(self.room_name)

                query_string = self.scope["query_string"].decode()
                query_params = parse_qs(query_string)
                token = query_params.get("token", None)
                headers = {
                    'accept': 'application/json',
                    'Authorization': 'Bearer ' + token[0],
                    'Players': ', '.join(players),
                    'Host': 'localhost',
                }
                session = await get_session(headers)
                room_data["session"] = session
                message = self.create_message(action, f"{username} has started the game.", room_data)
            except ValidationError as e:
                message = self.create_message("error", e.message, None)

        # ready 버튼 클릭 시
        elif action == "ready":
            try:
                room_data = await self.action_ready(self.room_name)
                message = self.create_message(action, f"{username} is ready.", room_data)
            except ValidationError as e:
                message = self.create_message("error", e.message, None)

        await self.channel_layer.group_send(self.room_group_name, {"type": "chat.message", "message": message})

    # 방 그룹으로부터 메시지 받기
    async def chat_message(self, event):
        message = event["message"]

        # WebSocket으로 메시지 보내기
        await self.send(text_data=json.dumps({"message": message}))







    @database_sync_to_async
    def can_connect(self, room_name):
        try:
            room = Room.objects.get(pk=room_name)
            if room.isPlaying:
                raise ValidationError("Game is already started")
            if room.ready_participants >= room.max_participants:
                raise ValidationError("Ready is full")
            if room.current_participants >= room.max_participants:
                raise ValidationError("Room is full")
        except Room.DoesNotExist:
            raise ValidationError("Room does not exist")


    @database_sync_to_async
    def get_room_data(self, room_name):
        try:
            room = Room.objects.get(pk=room_name)
            serializer = RoomSerializer(room)
            return serializer.data
        except Room.DoesNotExist:
            return None
        
    @database_sync_to_async
    def action_join(self, room_name, username):
        room = Room.objects.get(pk=room_name)
        room.join(username)

    @database_sync_to_async
    def action_leave(self, room_name, username):
        room = Room.objects.get(pk=room_name)
        room.leave(username)

    @database_sync_to_async
    def action_start(self, room_name):
        try:
            room = Room.objects.get(pk=room_name)
            if room.isPlaying:
                raise ValidationError("Game is already started")
            if room.ready_participants < room.max_participants:
                raise ValidationError("Not enough ready")
            if room.current_participants < room.max_participants:
                raise ValidationError("Not enough players")
        except Room.DoesNotExist:
            raise ValidationError("Room does not exist")
        room.start()
        serializer = RoomSerializer(room)
        return serializer.data

    @database_sync_to_async
    def action_ready(self, room_name):
        try:
            room = Room.objects.get(pk=room_name)
            if room.isPlaying:
                raise ValidationError("Game is already started")
            if room.ready_participants >= room.max_participants:
                raise ValidationError("Ready is full")
        except Room.DoesNotExist:
            raise ValidationError("Room does not exist")
        room.ready()
        serializer = RoomSerializer(room)
        return serializer.data

    @database_sync_to_async
    def action_ready_reset(self, room_name):
        room = Room.objects.get(pk=room_name)
        room.ready_reset()

    @database_sync_to_async
    def action_delete_empty_room(self, room_name):
        room = Room.objects.get(pk=room_name)
        room.delete_empty_room()

    @database_sync_to_async
    def get_players(self, room_name):
        room = Room.objects.get(pk=room_name)
        return room.players


    def create_message(self, action, text, room_data):
        return json.dumps({
            "action": action,
            "text": text,
            "room_data": room_data,
        })

    def get_username(self):
        user = self.scope["user"]
        return user.username


async def get_session(headers):
    async with aiohttp.ClientSession() as session:
        async with session.get('http://ft_games:8002/transcendence/api/check-session/', \
        headers=headers) as response:
            return await response.text()
