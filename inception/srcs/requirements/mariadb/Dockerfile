FROM debian:bullseye

RUN apt-get update && apt-get install -y mariadb-server mariadb-client

COPY ./tools/script.sh /
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

CMD ["sh", "/script.sh"]