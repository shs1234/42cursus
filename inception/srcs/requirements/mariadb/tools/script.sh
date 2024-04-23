# !/bin/bash

DB_NAME=wordpress
DB_USER=user
DB_PASSWORD=password

if [ ! -d "/var/lib/mysql/$DB_NAME" ]; then
    mysqld_safe > /dev/null 2>&1 &
    RET=1
    while [[ RET -ne 0 ]]; do
        echo "=> Waiting for confirmation of MariaDB service startup"
        sleep 1
        mysql -uroot -e "status" > /dev/null 2>&1
        RET=$?
    done

    mysql -uroot -e "CREATE DATABASE $DB_NAME;"
    mysql -uroot -e "CREATE USER '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD';"
    mysql -uroot -e "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%';"
    mysql -uroot -e "FLUSH PRIVILEGES;"

    mysqladmin -uroot shutdown
fi

mysqld_safe
