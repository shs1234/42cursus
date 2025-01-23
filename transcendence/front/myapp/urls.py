from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('main/', views.index),
    path('login/', views.index),
    path('auth/', views.index),
    path('list/', views.index),
    path('gamelist/', views.index),
    path('local-2p/', views.index),
    path('local-4p/', views.index),
    path('chat/<int:room_id>/', views.index, name='chat'),
	path('game/<int:room_id>/', views.index, name='game'),
    path('main-content/', views.main_content),
    path('login-content/', views.login_content),
    path('list-content/', views.list_content),
    path('local-2p-content/', views.local_2p),
    path('local-4p-content/', views.local_4p),
]