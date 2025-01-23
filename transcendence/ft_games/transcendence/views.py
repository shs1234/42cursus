from rest_framework.decorators import api_view
from rest_framework.permissions import AllowAny
from rest_framework.response import Response
from rest_framework.views import APIView
from rest_framework import status
from .models import GameSession, Match, SessionHistory, Player
from .serializers import SessionHistorySerializer
from django.shortcuts import render
from drf_yasg.utils import swagger_auto_schema
from drf_yasg import openapi
from django.contrib.auth import get_user_model
import re

User = get_user_model()

@swagger_auto_schema(
    method='get',
    operation_description="Check for available game session",
    responses={200: openapi.Response('Available session details', openapi.Schema(
        type=openapi.TYPE_OBJECT,
        properties={
            'session_id': openapi.Schema(type=openapi.TYPE_STRING, description='Session ID'),
            'websocket_url': openapi.Schema(type=openapi.TYPE_STRING, description='WebSocket URL'),
            'websocket_port': openapi.Schema(type=openapi.TYPE_INTEGER, description='WebSocket Port'),
        }
    ))}
    )
@api_view(['GET'])
def check_session(request):
    players_header = request.headers.get('Players', '')
    if not players_header:
        return Response({"error": "Players header is required"}, status=status.HTTP_400_BAD_REQUEST)

    # 콤마를 기준으로 분리하여 배열로 변환
    players = [player.strip() for player in players_header.split(',') if player.strip()]

    session_available = check_for_available_session(players)
    if session_available:
        response_data = {
            "session_id": session_available['session_id'],
            "websocket_url": session_available['websocket_url'],
            "websocket_port": session_available['websocket_port'],
            "players": players
        }
    else:
        response_data = {
            "session_id": None,
            "websocket_url": None,
            "websocket_port": None
        }
    return Response(response_data)

def check_for_available_session(player_usernames):
    # 현재 활성화된 게임 세션을 찾는다
    available_session = GameSession.objects.filter(is_active=False).first()
    if available_session:
        # 세션이 있을 경우
        available_session.is_active = True
        players = []
        for username in player_usernames:
            player, created = Player.objects.get_or_create(username=username)
            players.append(player)
        
        available_session.players.set(players)
        available_session.save()

        return {
            "session_id": available_session.session_id,
            "websocket_url": available_session.websocket_url,
            "websocket_port": available_session.websocket_port
        }
    else:
        # 세션이 없을 경우
        return None

def match(request):
    return render(request, 'transcendence/match.html')

def pingpong(request):
    return render(request, 'transcendence/pingpong.html')

class MatchHistoryView(APIView):
    @swagger_auto_schema(
        operation_description="Retrieve match history for a given username",
        responses={200: SessionHistorySerializer(many=True)}
    )
    def get(self, request, username):
        try:
            if not re.match(r'^[A-Za-z0-9]+$', username):
                return Response({"error": "Invalid username format"}, status=status.HTTP_400_BAD_REQUEST)

            # 주어진 username으로 User 검색
            user = User.objects.get(username=username)

            # 해당 유저가 player1 또는 player2로 참여한 모든 매치 조회
            player_matches = Match.objects.filter(player1=user) | Match.objects.filter(player2=user)

            # 해당 매치들이 포함된 모든 SessionHistory 조회
            session_history = SessionHistory.objects.filter(match__in=player_matches).distinct()

            # 직렬화하여 JSON 응답으로 반환
            serializer = SessionHistorySerializer(session_history, many=True)
            return Response(serializer.data, status=status.HTTP_200_OK)

        except User.DoesNotExist:
            return Response({"error": "User not found"}, status=status.HTTP_404_NOT_FOUND)

