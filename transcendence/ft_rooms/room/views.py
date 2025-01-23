from rest_framework import generics
from .models import Room
from .serializers import RoomSerializer, RoomCreateSerializer
from rest_framework.exceptions import ValidationError
from rest_framework.response import Response
from rest_framework.decorators import api_view
from rest_framework import status

import random
import string

def get_username(request, length=8):
    return request.user.username

class RoomList(generics.ListAPIView):
    queryset = Room.objects.all()
    serializer_class = RoomSerializer

    # players가 0인 방 삭제 후 반환
    def get_queryset(self):
        rooms = Room.objects.all()
        for room in rooms:
            if len(room.players) == 0:
                room.delete()
        return Room.objects.all()
        

class RoomCreate(generics.CreateAPIView):
    queryset = Room.objects.all()
    serializer_class = RoomCreateSerializer

    def post(self, request, *args, **kwargs):
        username = get_username(self.request)
        if Room.objects.filter(players__contains=[username]).exists():
            room = Room.objects.get(players__contains=[username])
            room.leave(username)
        return self.create(request, *args, **kwargs)

    def perform_create(self, serializer):
        username = get_username(self.request)
        room = serializer.save()
        # room.join(username)

class RoomDetail(generics.RetrieveAPIView):
    queryset = Room.objects.all()
    serializer_class = RoomSerializer

class RoomDelete(generics.DestroyAPIView):
    queryset = Room.objects.all()
    serializer_class = RoomSerializer

