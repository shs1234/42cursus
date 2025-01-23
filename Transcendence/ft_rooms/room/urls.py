from django.urls import path
from .views import RoomList, RoomCreate, RoomDetail, RoomDelete

urlpatterns = [
    path('room/', RoomList.as_view(), name='room-list'),
    path('room/create/', RoomCreate.as_view(), name='room-create'),
    path('room/<int:pk>/detail/', RoomDetail.as_view(), name='room-detail'),
    path('room/<int:pk>/delete/', RoomDelete.as_view(), name='room-delete'),
]
