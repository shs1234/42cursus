mv /nginx.conf /etc/nginx/
mv /default /etc/nginx/sites-available/

nginx -g 'daemon off;'