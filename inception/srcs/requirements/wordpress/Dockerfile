# Use Debian Bullseye as base image
FROM debian:bullseye

# Update package lists and install required packages
RUN apt-get update && apt-get install -y curl php-fpm php-mysql

COPY ./tools/script.sh /

CMD [ "sh", "/script.sh" ]