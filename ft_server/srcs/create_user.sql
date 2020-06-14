CREATE USER 'wordpress'@'%' IDENTIFIED BY '12345';
grant all privileges on *.* to 'wordpress'@'%';
CREATE USER 'phpmyadmin'@'%' IDENTIFIED BY '12345';
grant all privileges on *.* to 'phpmyadmin'@'%';
CREATE DATABASE wordpress;
FLUSH PRIVILEGES;
