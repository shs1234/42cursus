# mv /nginx.conf /etc/nginx/
mv /default /etc/nginx/sites-available/

openssl req -new -newkey rsa:2048 -nodes -keyout server.key -out server.csr -subj "/C=KR/L=SEOUL/O=42seoul"
openssl x509 -req -days 365 -in server.csr -signkey server.key -out server.crt
mv server.crt /etc/ssl/certs/
mv server.key /etc/ssl/private/

nginx -g 'daemon off;'