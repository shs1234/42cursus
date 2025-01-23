from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from django.shortcuts import get_object_or_404
from django.contrib.auth import get_user_model
from django.contrib.sessions.models import Session
from rest_framework.permissions import IsAuthenticated
from rest_framework.parsers import MultiPartParser, FormParser
from django.utils import timezone
from .models import Friendship
from .serializers import UserSerializer, FriendSerializer, FriendRequestSerializer, AvatarUploadSerializer, UserUpdateSerializer
from authentication.serializers import OAuthUserSerializer
from authentication.utils import TokenProvider
from drf_yasg.utils import swagger_auto_schema
from drf_yasg import openapi
from rest_framework.exceptions import APIException

User = get_user_model()


class UserProfileView(APIView):
    permission_classes = [IsAuthenticated]

    @swagger_auto_schema(
        tags=["프로필"],
        operation_description='유저 프로필 조회 (자신 또는 다른 사용자)',
        responses={200: UserSerializer}
    )
    def get(self, request, user_id=None, *args, **kwargs):
        if user_id:
            # 다른 사용자의 정보를 가져오기 위해 user_id를 사용하여 User 인스턴스를 가져옴
            user = get_object_or_404(User, pk=user_id)
        else:
            # user_id가 제공되지 않은 경우 현재 사용자의 정보를 가져옴
            user = request.user

        serializer = UserSerializer(instance=user, context={'request': request})
        return Response(serializer.data, status=status.HTTP_200_OK)

    @swagger_auto_schema(
        tags=["프로필"],
        operation_description='유저 프로필 업데이트',
        request_body=UserUpdateSerializer,
        responses={200: OAuthUserSerializer}
    )
    def patch(self, request, *args, **kwargs):
        user = request.user
        serializer = UserUpdateSerializer(data=request.data)
        try:
            if serializer.is_valid():
                username = serializer.validated_data.get('username')
                user.username = username
                user.save()
                jwt_token = TokenProvider.generate_jwt_token(user)
                serializer = OAuthUserSerializer({
                    'jwt_token': jwt_token,
                    'user_id': user.id,
                    'user_email': user.email,
                    'username': user.username,
                    'avatar': request.build_absolute_uri(user.avatar.url) if user.avatar else None,
                })
                return Response(serializer.data, status=status.HTTP_200_OK)
            else:
                return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
        except APIException as e:
            return Response({'detail': str(e)}, status=e.status_code)





class FriendRequest(APIView):
    permission_classes = [IsAuthenticated]

    @swagger_auto_schema(
        tags=["친구 관리 기능"],
        operation_description='친구 목록 조회',
        responses={200: FriendSerializer(many=True)},
    )
    def get(self, request, *args, **kwargs):
        user = request.user

        # 사용자가 보낸 친구 요청을 가져오기
        friendships = Friendship.objects.filter(from_user=user)

        friend_list = []
        for friendship in friendships:
            friend_list.append(friendship.to_user)

        # Serializer를 사용하여 데이터 직렬화
        serializer = FriendSerializer(friend_list, many=True, context={'request': request})
        return Response(serializer.data, status=status.HTTP_200_OK)

    @swagger_auto_schema(tags=["친구 관리 기능"], operatio_description='친구 추가', request_body=FriendRequestSerializer, responses={201: openapi.Response("Friend request sent successfully")})
    def post(self, request, *args, **kwargs):
        serializer = FriendRequestSerializer(data=request.data, context={'request': request})
        if serializer.is_valid():
            try:
                from_user = request.user
                to_user_name = serializer.validated_data['username']

                to_user = get_object_or_404(User, username=to_user_name)
                Friendship.add_friend(from_user, to_user)
                return Response({'message': 'Friend request sent successfully'}, status=status.HTTP_201_CREATED)
            except ValueError as e:
                return Response({'error': str(e)}, status=status.HTTP_400_BAD_REQUEST)
            except User.DoesNotExist as e:
                return Response({'error': str(e)}, status=status.HTTP_404_NOT_FOUND)
        else:
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    @swagger_auto_schema(tags=["친구 관리 기능"], operation_description='친구 삭제', request_body=FriendRequestSerializer, responses={204: openapi.Response("Friend request canceled successfully")})
    def delete(self, request, *args, **kwargs):
        serializer = FriendRequestSerializer(data=request.data, context={'request': request})
        if serializer.is_valid():
            try:
                from_user = request.user

                to_user_name = serializer.validated_data['username']
                to_user = get_object_or_404(User, username=to_user_name)

                friendship = Friendship.objects.get(from_user=from_user, to_user=to_user)
                friendship.delete()
            except User.DoesNotExist:
                return Response({'error': 'Friend User does not exist'}, status=status.HTTP_404_NOT_FOUND)
            except Friendship.DoesNotExist:
                return Response({'error': 'Friendship does not exist'}, status=status.HTTP_404_NOT_FOUND)
        else:
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

        return Response({'message': 'Friendship deleted successfully'}, status=status.HTTP_200_OK)


class AvatarUploadView(APIView):
    permission_classes = [IsAuthenticated]
    parser_classes = [MultiPartParser, FormParser]

    @swagger_auto_schema(
        tags=["프로필"],
        operation_description='아바타 업로드',
        request_body=AvatarUploadSerializer,
        responses={200: UserSerializer}
    )
    def patch(self, request, *args, **kwargs):
        user = request.user

        serializer = AvatarUploadSerializer(data=request.data)
        if serializer.is_valid():
            avatar_file = serializer.validated_data['avatar']

            # Delete existing avatar if it exists
            if user.avatar:
                user.avatar.delete()

            # Update avatar with new file
            user.avatar = avatar_file
            user.save()

            serializer = UserSerializer(instance=user, context={'request': request})
            return Response(serializer.data, status=status.HTTP_200_OK)
        else:
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)