FROM alpine:3.12.3

# Install Nginx
RUN apk update && \
	apk --no-cache add nginx mysql-client

# Setup nginx
RUN mkdir -p /run/nginx
COPY srcs/default.conf /etc/nginx/conf.d/default.conf
COPY srcs/index.php /www/index.php

# Install PHP
RUN apk add php7 php7-fpm php7-opcache \
			php7-gd php7-mysqli php7-zlib php7-curl php7-json \
			php7-mbstring php7-session

# Download Wordpress
ADD https://wordpress.org/latest.tar.gz .

# Install Wordpressa
RUN tar -xvf latest.tar.gz && \
	mv wordpress /www && \
	rm -f latest.tar.gz
COPY srcs/wp-config.php /www/wordpress/wp-config.php
COPY srcs/wordpress.sql /wordpress.sql
COPY srcs/init.sh /init.sh

EXPOSE 5050
ENTRYPOINT ["/bin/sh", "init.sh"]


