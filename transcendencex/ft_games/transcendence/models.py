from django.db import models
from django.contrib.auth import get_user_model

User = get_user_model()

# Create your models here.
class GameSession(models.Model):
	session_id = models.CharField(max_length=100, unique=True)
	websocket_url = models.URLField()
	websocket_port = models.IntegerField()
	is_active = models.BooleanField(default=False)
	players = models.ManyToManyField('Player', related_name='game_sessions')
	players_connected = models.ManyToManyField('Player', related_name='game_sessions_connected')

	def __str__(self):
		return f"Session {self.session_id} - Active: {self.is_active} - Players: {self.players.all()}"

class Player(models.Model):
	username = models.CharField(max_length=100, unique=True)
	score = models.IntegerField(default=0)

	def __str__(self):
		return f"Player {self.username} - Score: {self.score}"

class Match(models.Model):
	player1 = models.ForeignKey(User, related_name='player1_matches', on_delete=models.SET_NULL, null=True)
	player2 = models.ForeignKey(User, related_name='player2_matches', on_delete=models.SET_NULL, null=True)
	winner = models.ForeignKey(User, related_name='won_matches', on_delete=models.SET_NULL, null=True)

	def __str__(self):
		return f"Match {self.id}: {self.player1.username if self.player1 else 'Unknown'} vs {self.player2.username if self.player2 else 'Unknown'}"


class SessionHistory(models.Model):
	match = models.ManyToManyField(Match, related_name='match_history')
	created_at = models.DateTimeField(auto_now_add=True)

	def __str__(self):
		return f"SessionHistory {self.id} - Matches: {self.match.count()}"
