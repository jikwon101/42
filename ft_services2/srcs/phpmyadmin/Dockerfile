FROM alpine:3.12.3

# Install nginx
RUN apk update && \ 
	apk --no-cache add nginx 

# Install PHP
RUN apk add --no-cache php7 php7-fpm php7-mbstring \
			php7-session  php7-common php7-iconv php7-json \
			php7-gd php7-curl php7-xml php7-mysqli php7-imap \
			php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap \
			php7-xmlrpc php7-posix php7-mcrypt php7-gettext \
			php7-ldap php7-ctype php7-dom openssl

#Setup nginx
RUN mkdir -p /run/nginx
COPY srcs/default.conf /etc/nginx/conf.d/default.conf
COPY srcs/index.html /www/index.html

# Download phpMyAdmin
ADD https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-all-languages.tar.gz .

# Install phpMyAdmin
RUN tar -xvf /phpMyAdmin-4.9.5-all-languages.tar.gz
RUN rm -f /phpMyAdmin-4.9.5-all-languages.tar.gz
RUN mv /phpMyAdmin-4.9.5-all-languages /www/phpmyadmin

#Setup phpMyAdmin
COPY srcs/config.inc.php /www/phpmyadmin/config.inc.php
RUN chmod 705 /www/phpmyadmin/config.inc.php
							
EXPOSE 5000

CMD php-fpm7 \
	&& nginx -g "daemon off;"
