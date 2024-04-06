#!/bin/bash

# Wordpress 서비스가 준비될 때까지 대기
until curl -sSf http://wordpress:80 >/dev/null; do
    echo "Waiting for Wordpress service to be ready..."
    sleep 5
done

# Wordpress 서비스가 준비되면 nginx 서버 시작
echo "Wordpress service is ready. Starting nginx server..."
nginx -g 'daemon off;'
