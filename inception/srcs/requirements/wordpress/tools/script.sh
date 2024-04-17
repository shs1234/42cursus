curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

mkdir /var/www/
mkdir /var/www/html
cd /var/www/html

wp core download --allow-root

sed -i -r 's/database_name_here/'"$MYSQL_DATABASE"'/1' wp-config.php
sed -i -r 's/username_here/'"$WORDPRESS_DB_USER"'/1' wp-config.php
sed -i -r 's/password_here/'"$WORDPRESS_DB_PASSWORD"'/1' wp-config.php

mv /wp-config.php /var/www/html/wp-config.php


wp core install --url=$DOMAIN_NAME/ --title=$WP_TITLE --admin_user=$WP_ADMIN_USR --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
wp user create $WP_USR $WP_EMAIL --role=author --user_pass=$WP_PWD --allow-root
wp theme install astra --activate --allow-root
wp plugin install redis-cache --activate --allow-root
wp plugin update --all --allow-root

 
sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 9000/g' /etc/php/7.4/fpm/pool.d/www.conf



mkdir /run/php

php-fpm7.4 -F