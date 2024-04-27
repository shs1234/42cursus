FROM debian:bullseye

RUN apt-get update && apt-get install -y mariadb-server mariadb-client

COPY ./tools/script.sh /
COPY ./tools/entrypoint.sh /
COPY ./tools/create_user.sh /

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
EXPOSE 3306
# CMD ["sh", "/script.sh"]
CMD ["/entrypoint.sh"]
