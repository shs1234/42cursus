FROM debian:bullseye

RUN apt-get update && apt-get install -y nginx && apt-get install -y openssl

COPY ./conf/default /
COPY ./tools/script.sh /

RUN chmod +x /script.sh
RUN ./script.sh > /dev/null 2>&1

ENTRYPOINT ["nginx", "-g", "daemon off;"]