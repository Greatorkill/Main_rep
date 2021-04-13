FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y

RUN apt-get -y install vim
RUN apt-get -y install wget
RUN apt-get -y install nginx
RUN apt-get -y install mariadb-server
RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

WORKDIR /var/www/html/

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz
RUN mv phpMyAdmin-5.0.1-english phpmyadmin

COPY ./srcs/config.inc.php phpmyadmin
COPY ./srcs/wp-config.php /var/www/html
COPY ./srcs/init.sh /var
COPY ./srcs/nginx.conf /var/

RUN mv /var/nginx.conf /etc/nginx/sites-available/default
RUN chown -R www-data:www-data *
RUN chmod -R 755 /var/www/*

ENTRYPOINT bash /var/init.sh

EXPOSE 80 443
