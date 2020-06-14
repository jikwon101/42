#!/bin/bash

service nginx start
service php7.3-fpm start
service mysql start

mysql < /var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password
mysql < /create_user.sql -u root --skip-password
