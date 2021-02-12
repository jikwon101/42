# Setup ssh
ssh-keygen -A >> /dev/null
adduser --disabled-password $SSH_USER
echo "$SSH_USER:$SSH_PWD" | chpasswd
