from rest_framework import serializers
from django.contrib.auth import get_user_model
from django.utils import timezone
from datetime import timedelta
from .exceptions import EmptyUsernameException, NonAlphanumericUsernameException, UsernameAlreadyExistsException

User = get_user_model()


class UserSerializer(serializers.ModelSerializer):
    avatar = serializers.SerializerMethodField()

    class Meta:
        model = User
        fields = ['id', 'username', 'email', 'avatar']

    def get_avatar(self, obj):
        if obj.avatar and hasattr(obj.avatar, 'url'):
            return self.context['request'].build_absolute_uri(obj.avatar.url)
        return None

    def to_representation(self, instance):
        ret = super().to_representation(instance)
        if ret['avatar'] is None:
            ret['avatar'] = None  # Ensure that if avatar is None, it is explicitly set to None
        return ret


class FriendSerializer(UserSerializer):
    online_status = serializers.SerializerMethodField()

    class Meta:
        model = User
        fields = ['id', 'username', 'email', 'avatar', 'online_status']

    def get_online_status(self, obj):
        # 현재 시간 가져오기
        current_time = timezone.now()
        # last_request가 설정되어 있지 않다면 False 반환
        if not obj.last_request:
            return False
        # last_request로부터 3분 이내면 온라인으로 간주
        if current_time - obj.last_request <= timedelta(minutes=3):
            return True
        return False

    def to_representation(self, instance):
        ret = super().to_representation(instance)
        ret['online_status'] = self.get_online_status(instance)
        return ret


class FriendRequestSerializer(serializers.Serializer):
    username = serializers.CharField()

    def validate_username(self, value):
        if not value:
            raise EmptyUsernameException()
        if not value.isalnum():
            raise NonAlphanumericUsernameException()
        if value == self.context['request'].user.username:
            raise serializers.ValidationError('You cannot send a friend request to yourself')
        return value


class AvatarUploadSerializer(serializers.Serializer):
    avatar = serializers.FileField()


class UserUpdateSerializer(serializers.Serializer):
    username = serializers.CharField()

    def validate_username(self, value):
        if not value:
            raise EmptyUsernameException()
        if not value.isalnum():
            raise NonAlphanumericUsernameException()
        if User.objects.filter(username=value).exists():
            raise UsernameAlreadyExistsException()
        return value