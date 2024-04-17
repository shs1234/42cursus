FROM debian:bullseye

RUN apt-get update && apt-get install -y nginx && apt-get install -y openssl

COPY ./conf/nginx.conf /
COPY ./conf/default /

COPY ./tools/script.sh /

CMD [ "sh", "/script.sh" ]