#!/bin/bash

/usr/bin/mysqld_safe > /dev/null 2>&1 &

RET=1
while [[ RET -ne 0 ]]; do
    echo "=> Waiting for confirmation of Mariadb service startup"
    sleep 5
    mysql -e "status" > /dev/null 2>&1
    RET=$?
done

mysql -e "CREATE DATABASE $DB_NAME;"
mysql -e "CREATE USER '${DB_USER}'@'%' IDENTIFIED BY '$DB_PASSWORD'"
mysql -e "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%';"
mysql -e "FLUSH PRIVILEGES;"

echo "=> Done!"

mysqladmin shutdown