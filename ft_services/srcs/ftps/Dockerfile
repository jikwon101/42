FROM alpine:3.12.3

# Install ftp and dependencies
RUN apk update && \
	apk --no-cache add openssl vsftpd

# Setup vsftpd
COPY srcs/vsftpd.conf /etc/vsftpd
RUN chown root:root /etc/vsftpd/vsftpd.conf
RUN touch /var/log/vsftpd.log

# Setup SSL
RUN mkdir -p /etc/ssl/private/ftps
RUN openssl req -new -newkey rsa:2048 -nodes -days 365 -x509 \
			-subj "/C=KR/ST=Seoul/L=Seoul/O=42seoul/CN=localhost" \
			-keyout /etc/ssl/private/ftps/ftps.key \
			-out /etc/ssl/private/ftps/ftps.crt

# Setup for creating user
ENV FTPS_USER admin
ENV FTPS_PWD pass

# Init container
EXPOSE 20 21 21100-21104
COPY srcs/init.sh /init.sh
COPY srcs/testfile.txt  /var/ftps/user/$FTPS_USER/
ENTRYPOINT ["bin/sh", "/init.sh"]

