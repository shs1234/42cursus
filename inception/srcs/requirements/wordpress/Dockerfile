# Use Debian Bullseye as base image
FROM debian:bullseye

# Update package lists and install required packages
RUN apt-get update && apt-get install -y wordpress php-fpm

# # Copy php.ini configuration file
# COPY php.ini /etc/php/7.4/fpm/php.ini

# # Start PHP-FPM service
# CMD ["php-fpm", "-F"]
