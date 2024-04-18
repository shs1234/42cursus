#!/bin/bash

service mariadb start

echo "CREATE DATABASE $DB_NAME default CHARACTER SET UTF8;" | mysql
echo "CREATE USER '$DB_USER'@'%' identified by '$DB_PASSWORD';" | mysql
echo "GRANT ALL PRIVILEGES ON $DB_NAME.* TO $DB_USER@'%';" | mysql
echo "FLUSH PRIVILEGES;" | mysql

service mariadb stop
mysqld
