from queue import Queue
from threading import Lock
from .models import Match, Player, SessionHistory
import threading
from django.contrib.auth import get_user_model

User = get_user_model()

class DBWorker:
	def __init__(self):
		# python의 Queue는 thread-safe하다. 즉, mutex가 필요 없다.ㄷㄷ
		self.match_history = Queue()
		self.event = threading.Event()
		self.postgres = None
		self.initialize()

	def initialize(self):
		threading.Thread(target=self.run).start()
	
	def save_match_history(self):
		print("Saving match history")
		if not self.match_history.empty():
			# match_history Queue에 데이터가 있으면 DB에 저장
			matches = self.match_history.get()
			if isinstance(matches, list):
				# DB에 저장하는 함수 호출
				self.save_to_db(matches)
			else:
				print("No Matches to save")

	def run(self):
		# Producer-Consumer 패턴을 사용하여 DB에 데이터를 저장
		while True:
			self.event.wait()
			self.save_match_history()
			self.event.clear()

	def save_to_db(self, match):
		# DB에 저장하는 코드
		History = SessionHistory.objects.create()
		for m in match:
			try:
				player1_ = User.objects.get(username=m.player[0])
				player2_ = User.objects.get(username=m.player[1])
				winner_ = User.objects.get(username=m.winner)

				# Match 생성 및 저장
				match_history = Match.objects.create(
					player1=player1_,
					player2=player2_,
					winner=winner_
				)
				History.match.add(match_history)
				History.save()
				print(f"Match {match_history} saved to DB")
			except User.DoesNotExist as e:
				print(f"User does not exist: {e}")
