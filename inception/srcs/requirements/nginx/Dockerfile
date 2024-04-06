FROM debian:bullseye

RUN apt-get update && apt-get install -y nginx && apt-get install -y openssl

COPY ./tools/wait-for-wordpress.sh /usr/local/bin/wait-for-wordpress.sh

RUN chmod +x /usr/local/bin/wait-for-wordpress.sh

CMD ["wait-for-wordpress.sh"]
