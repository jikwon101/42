# Start SSH Daemon
/bin/sh setup_ssh.sh
/usr/sbin/sshd

#Start nginx
/usr/sbin/nginx -g "daemon off;"
