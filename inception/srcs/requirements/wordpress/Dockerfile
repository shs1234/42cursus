# Use Debian Bullseye as base image
FROM debian:bullseye

# Update package lists and install required packages
RUN apt-get update && apt-get install -y curl php-fpm

COPY ./conf/wp-config.php /
COPY ./tools/script.sh /

CMD [ "sh", "/script.sh" ]