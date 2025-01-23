#!/bin/bash

if [ ! -d "/var/lib/mysql/$DB_NAME" ]; then
    mysql_install_db
    mysqld_safe &
    RET=1
    while [ $RET -ne 0 ]; do
        sleep 1
        mysql -e "status"
        RET=$?
    done
    mysql -e "CREATE DATABASE $DB_NAME;"
    mysql -e "CREATE USER '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD';"
    mysql -e "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%';"
    mysql -e "FLUSH PRIVILEGES;"
    mysqladmin shutdown
fi

exec mysqld_safe