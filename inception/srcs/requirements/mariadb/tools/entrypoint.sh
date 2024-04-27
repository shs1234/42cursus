#!/bin/bash

DB_NAME=wordpress
DB_USER=user
DB_PASSWORD=password

# chmod 644 /etc/mysql/mariadb.conf.d/*.cnf

if [[ ! -d "/var/lib/mysql/$DB_NAME" ]]; then
    echo "=> Installing MariaDB ..."
    mysql_install_db > /dev/null 2>&1
    echo "=> Done!"  
    /create_user.sh
else
    echo "=> Using an existing volume of MariaDB"
fi

exec mysqld_safe
