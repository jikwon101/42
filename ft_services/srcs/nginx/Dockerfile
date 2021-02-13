FROM alpine:3.12.3

# Install nginx and dependencies
RUN apk update && \ 
	apk add --no-cache nginx openssh-server openssl

# Setup nginx
RUN mkdir -p /run/nginx && \
	mkdir /www
COPY srcs/index.html /www/index.html
COPY srcs/default.conf /etc/nginx/conf.d/default.conf

# Setup SSL
RUN mkdir -p /etc/ssl/private/nginx && \
	openssl req -new -newkey rsa:2048 -nodes -days 365 -x509 \
			-subj "/C=KR/ST=Seoul/L=Seoul/O=42seoul/CN=localhost" \
			-keyout /etc/ssl/private/nginx/nginx.key \
			-out /etc/ssl/private/nginx/nginx.crt

# Setup SSH
COPY srcs/setup_ssh.sh /setup_ssh.sh
RUN chmod +x /setup_ssh.sh

EXPOSE 80 443 22

# Init container
COPY srcs/init.sh /init.sh
RUN chmod +x /init.sh

#Temp
#ENV SSH_USER user
#ENV SSH_PWD pwd

ENTRYPOINT ["/bin/sh", "/init.sh"]
