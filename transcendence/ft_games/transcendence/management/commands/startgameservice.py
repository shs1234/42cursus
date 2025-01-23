from django.core.management.base import BaseCommand
import time

class Command(BaseCommand):
    help = 'Starts the game service with a delay'

    def handle(self, *args, **kwargs):
        self.stdout.write('Starting the game service...')

        # 1초 대기
        time.sleep(1)

        try:
            from transcendence.service import GameServiceSingleton
            service_instance = GameServiceSingleton()
            session_queues = service_instance.start_service()

            from django.conf import settings
            settings.SESSION_QUEUES = session_queues

            self.stdout.write(self.style.SUCCESS('Service started successfully after 1 second'))
        except Exception as e:
            self.stdout.write(self.style.ERROR(f"Error starting game service: {e}"))
