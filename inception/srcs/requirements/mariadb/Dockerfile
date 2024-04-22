FROM debian:bullseye

RUN apt-get update && apt-get install -y mariadb-server mariadb-client

COPY ./tools/script.sh /
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
# RUN sed -i "s/127.0.0.1/0.0.0.0/" /etc/mysql/mariadb.conf.d/50-server.cnf 

CMD ["sh", "/script.sh"]
