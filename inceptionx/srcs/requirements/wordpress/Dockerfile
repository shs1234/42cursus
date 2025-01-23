FROM debian:bullseye

RUN apt-get update && apt-get install -y curl php7.4-fpm php-mysql

COPY ./tools/script.sh /

CMD [ "sh", "/script.sh" ]