import atexit
from django.apps import AppConfig
from django.db.models.signals import post_migrate
import time
import threading
import sys

class TranscendenceConfig(AppConfig):
    default_auto_field = 'django.db.models.BigAutoField'
    name = 'transcendence'

    def ready(self):
        if 'runserver' in sys.argv: # 'runserver' 명령어로 시작될 때만 실행
            atexit.register(self.cleanup_db)
            from .startup import start_game_service
            start_game_service()


    def cleanup_db(self):
        # 데이터베이스 정리
        try:
            from transcendence.models import GameSession, Player
            print("Cleaning up database...")
            GameSession.objects.all().delete()
            Player.objects.filter(game_sessions__isnull=True).delete()
            print("Clean Done")
        except Exception as e:
            print(f"Error during cleanup: {e}")
