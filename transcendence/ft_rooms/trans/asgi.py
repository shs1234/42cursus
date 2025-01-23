"""
ASGI config for trans project.

It exposes the ASGI callable as a module-level variable named ``application``.

For more information on this file, see
https://docs.djangoproject.com/en/5.1/howto/deployment/asgi/
"""

import os

from channels.auth import AuthMiddlewareStack
from channels.routing import ProtocolTypeRouter, URLRouter
from channels.security.websocket import AllowedHostsOriginValidator
from django.core.asgi import get_asgi_application
from chat.routing import websocket_urlpatterns
from accounts.middleware import JWTAuthMiddleware  # JWTAuthMiddleware import

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'trans.settings')

django_asgi_app = get_asgi_application()

application = ProtocolTypeRouter({
    "http": django_asgi_app,
    # "websocket": AllowedHostsOriginValidator(
    #         AuthMiddlewareStack(
    #             JWTAuthMiddleware(
    #                 URLRouter(websocket_urlpatterns)))
    #     ),
    "websocket": AuthMiddlewareStack(  # AuthMiddlewareStack을 사용하여 기본 인증 처리
            JWTAuthMiddleware(  # JWTAuthMiddleware를 추가하여 JWT 인증 처리
                URLRouter(
                    websocket_urlpatterns
                )
            )
        ),
    # Just HTTP for now. (We can add other protocols later.)
})