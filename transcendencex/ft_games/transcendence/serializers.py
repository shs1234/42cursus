from rest_framework import serializers
from .models import Match, SessionHistory

class MatchSerializer(serializers.ModelSerializer):
    player1 = serializers.CharField(source='player1.username')
    player2 = serializers.CharField(source='player2.username')
    winner = serializers.CharField(source='winner.username')
    
    class Meta:
        model = Match
        fields = '__all__'

class SessionHistorySerializer(serializers.ModelSerializer):
    match = MatchSerializer(many=True, read_only=True)

    class Meta:
        model = SessionHistory
        fields = '__all__'
