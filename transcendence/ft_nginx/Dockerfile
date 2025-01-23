# Dockerfile
FROM nginx:latest

RUN apt-get update && apt-get install -y openssl

COPY . /etc/nginx/

RUN openssl req -new -newkey rsa:2048 -nodes -keyout server.key -out server.csr -subj "/C=KR/L=SEOUL/O=42seoul"
RUN openssl x509 -req -days 365 -in server.csr -signkey server.key -out server.crt
RUN mv server.crt /etc/ssl/certs/
RUN mv server.key /etc/ssl/private/