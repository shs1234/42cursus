# !/bin/bash
DB_NAME=wordpress
DB_USER=user
DB_PASSWORD=password
service mariadb start
sleep 3

echo "CREATE DATABASE $DB_NAME;" | mysql
echo "CREATE USER '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD';" | mysql
echo "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%';" | mysql
echo "FLUSH PRIVILEGES;" | mysql

service mariadb stop

mysqld
