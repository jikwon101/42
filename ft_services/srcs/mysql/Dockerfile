FROM alpine:3.12.3

# Install MySQL and dependencies
RUN apk update && \
	apk --no-cache add mysql mysql-client

# Setup MySQL
RUN mkdir -p /run/mysqld
COPY srcs/my.cnf /etc/my.cnf
COPY srcs/init_file /init_file
COPY srcs/init.sh /init.sh

EXPOSE 3306
ENTRYPOINT ["/bin/sh", "init.sh"]
