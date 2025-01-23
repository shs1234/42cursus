#!/bin/bash

if [ ! -d "/var/lib/mysql/$DB_NAME" ]; then
    echo "Installing MariaDB"
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
else
    echo "MariaDB already installed"
fi

exec mysqld_safe