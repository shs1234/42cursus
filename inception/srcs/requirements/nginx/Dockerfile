FROM debian:bullseye

RUN apt-get update && apt-get install -y nginx && apt-get install -y openssl

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./conf/default.conf /etc/nginx/conf.d/default.conf

COPY ./tools/script.sh /

CMD [ "/script.sh" ]