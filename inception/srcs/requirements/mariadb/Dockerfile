FROM debian:bullseye

RUN apt-get update && apt-get install -y mariadb-server

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./tools/script.sh /

RUN chmod +x /script.sh

CMD ["/script.sh"]
