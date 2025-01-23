from transcendence.service import GameServiceSingleton
from django.conf import settings
import threading
import time

def start_game_service():
	threading.Thread(target=delayed_start_service).start()

def delayed_start_service():
	time.sleep(1)
	try:
		service_instance = GameServiceSingleton()
		session_queues = service_instance.start_service()

		settings.SESSION_QUEUES = session_queues
		print("Service started successfully")
	except Exception as e:
		print(f"Error starting game service: {e}")
