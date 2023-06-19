#!/bin/bash
service mysql start;

mysql -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DB_NAME}\`;"
mysql -e "CREATE USER IF NOT EXISTS \`${MYSQL_DB_HOST}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';"
mysql -e "GRANT ALL PRIVILEGES ON \`${MYSQL_DB_NAME}\`.* TO \`${MYSQL_DB_HOST}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_DB_ROOT_PASSWORD}';"
mysql -e "FLUSH PRIVILEGES;"
mysqladmin -u root -p$MYSQL_DB_ROOT_PASSWORD shutdown
exec mysqld_safe

