curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

mkdir /var/www/
mkdir /var/www/html
cd /var/www/html

wp core download --allow-root

mv /wp-config.php /var/www/html/wp-config.php

mkdir /run/php

php-fpm7.4 -F