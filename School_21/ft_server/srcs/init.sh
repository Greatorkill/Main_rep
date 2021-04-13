service mysql start
service php7.3-fpm start
openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Russia/L=Moscow/O=School_21/OU=42moscow/CN=kgeorgia" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt;

mysql -e "CREATE DATABASE my_database;"
mysql -e "CREATE USER 'Kirill'@'localhost' IDENTIFIED BY 'root';"
mysql -e "GRANT ALL PRIVILEGES ON my_database.* TO 'Kirill'@'localhost';"
mysql -e "FLUSH PRIVILEGES;"

mkdir test
mv index.nginx-debian.html test/index.nginx-debian.html

service nginx start

bash
