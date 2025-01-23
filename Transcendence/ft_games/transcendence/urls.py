from django.urls import path, include
from transcendence import views as transcendence_views

app_name = "pingpong"
urlpatterns = [
	path("api/check-session/", transcendence_views.check_session, name="check-session"),
	path("api/user-session-history/<str:username>/", transcendence_views.MatchHistoryView.as_view(), name="user-session-history"),

	path("match/", transcendence_views.match, name="match"),
	path("pingpong/", transcendence_views.pingpong, name="pingpong"),
]
