# !/bin/bash

DB_NAME=wordpress
DB_USER=user
DB_PASSWORD=password
echo "111"
if [ ! -d "/var/lib/mysql/$DB_NAME" ]; then
    mysqld_safe &
    echo "222"
    # mysqld_safe > /dev/null 2>&1 &
    RET=1
    echo "333"
    while [ $RET -ne 0 ]; do
        echo "=> Waiting for confirmation of MariaDB service startup"
        sleep 5
        service mariadb status
        # mysql -uroot -e "status" > /dev/null 2>&1
        mysql -uroot -e "status"
        RET=$?
        echo "444"
        echo "$RET"
    done

    mysql -uroot -e "CREATE DATABASE $DB_NAME;"
    mysql -uroot -e "CREATE USER '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD';"
    mysql -uroot -e "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%';"
    mysql -uroot -e "FLUSH PRIVILEGES;"
    echo "555"
    mysqladmin -uroot shutdown
    echo "666"
fi
echo "777"
mysqld_safe
echo "888"