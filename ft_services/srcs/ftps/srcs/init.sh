# Create user
mkdir -p /var/ftps/user/$FTPS_USER
adduser -D $FTPS_USER --home=/var/ftps/user/$FTPS_USER
echo "$FTPS_USER:$FTPS_PWD" | chpasswd

# Run vsftpd
vsftpd /etc/vsftpd/vsftpd.conf
