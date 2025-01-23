from rest_framework import serializers
from django.shortcuts import get_object_or_404
from .models import EmailVerify
from django.core.validators import validate_email
from django.core.exceptions import ValidationError as DjangoValidationError
from rest_framework.exceptions import ValidationError as DRFValidationError


class OAuthCallbackQuerySerializer(serializers.Serializer):
    code = serializers.CharField()


class OAuthUserSerializer(serializers.Serializer):
    jwt_token = serializers.CharField()
    user_id = serializers.IntegerField()
    user_email = serializers.EmailField()
    username = serializers.CharField()
    avatar = serializers.CharField()


class VerificationCodeSerializer(serializers.Serializer):
    email = serializers.EmailField()
    code = serializers.CharField(max_length=6)

    def validate(self, data):
        email = data.get('email')
        # 이메일 형식 검증
        try:
            validate_email(email)
        except DjangoValidationError:
            raise DRFValidationError("Invalid email format")

        code = data.get('code')
        # 코드 형식 검증 (예: 숫자만 허용)
        if not code.isalnum():
            raise DRFValidationError("Code must be alphanumeric")

        verify = get_object_or_404(EmailVerify, email=email)
        if code == verify.code:  # 인증코드 일치 여부 확인
            verify.delete()  # 인증코드 삭제
            return data
        else:
            raise serializers.ValidationError("Invalid verification code")