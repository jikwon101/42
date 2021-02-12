# Setup MySQL
/usr/bin/mysql_install_db --user=root > /dev/null

# Create wordpress database
mysqld -u root --bootstrap < init_file

mysqld -u root
