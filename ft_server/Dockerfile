FROM debian:buster
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update
RUN apt-get install -y wget openssl vim php7.3-fpm dpkg lsb-release gnupg 
RUN apt-get install -y nginx

#ssl
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
RUN mv localhost.dev.crt etc/ssl/certs/
RUN mv localhost.dev.key etc/ssl/private/
RUN chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

#mysql
RUN apt-get install -y mariadb-server php-mysql

#phpmyadmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz -O /tmp/phpmyadmin.tar.gz
RUN tar -xvf /tmp/phpmyadmin.tar.gz
RUN mv phpMyAdmin-5.0.2-all-languages phpmyadmin
RUN mv phpmyadmin /var/www/html
RUN cp -rp var/www/html/phpmyadmin/config.sample.inc.php var/www/html/phpmyadmin/config.inc.php 

#wordpress
RUN wget https://wordpress.org/latest.tar.gz -O /tmp/wordpress.tar.gz
RUN tar -xvf /tmp/wordpress.tar.gz
RUN mv wordpress/ var/www/html/
RUN chown -R www-data:www-data /var/www/html/wordpress

#autoindex
RUN mv /var/www/html/index.nginx-debian.html /var/www/html/temp.html

COPY ./srcs/default ./etc/nginx/sites-available/default
COPY ./srcs/php.ini ./etc/php/7.3/fpm/php.ini
COPY ./srcs/config.inc.php  ./var/www/html/phpmyadmin/config.inc.php
COPY ./srcs/phpinfo.php ./var/www/html/phpinfo.php
COPY ./srcs/wp-config.php ./var/www/html/wordpress/wp-config.php
COPY ./srcs/create_user.sql ./create_user.sql
COPY ./srcs/init_mysql.sh ./init_mysql.sh
COPY ./srcs/start.sh ./start.sh

RUN ./init_mysql.sh
EXPOSE 80
EXPOSE 443
