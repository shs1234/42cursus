FROM debian:bullseye

RUN apt-get update && apt-get install -y curl php-fpm php-mysql

COPY ./tools/script.sh /

CMD [ "sh", "/script.sh" ]