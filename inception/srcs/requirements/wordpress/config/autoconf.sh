#!/bin/bash

############### ENV CHECK #####################################
# Load environment variables from .env file
if [ -f "/.env" ]; then
    source "/.env"
fi

# Test if environment variables are accessible
if [ -z "$MYSQL_DB_NAME" ]; then
    echo "[ERROR] : MYSQL_DB_NAME is not set or accessible."
    exit 1
fi

if [ -z "$MYSQL_USER" ]; then
    echo "[ERROR] : MYSQL_USER is not set or accessible."
    exit 1
fi

############### DOWNLOAD WP ####################################

wp core download --locale=fr_FR --allow-root

sleep 2

############### CONFIG WP ######################################

if [ -f /var/www/html/wp-config.php ]
then
	echo "[NOTICE] : wp-config.php exists"
	sleep 2
else
echo "[NOTICE] : creating wp-config.php file..."
sleep 5

wp core config  --dbname=$MYSQL_DB_NAME \
                --dbuser=$WP_ADMIN \
                --dbpass=$WP_ADMIN_PASSWORD \
                --dbhost=$MYSQL_DB_HOST \
                --dbcharset=$WP_CHARSET \
                --dbprefix=wp_ \
                --dbcollate="utf8_general_ci" \
                --allow-root

echo "[NOTICE] : installing wordpress..."
sleep 5

wp core install --url="dsy.42.fr" \
                --title="dsy's inception" \
                --admin_user=$WP_ADMIN\
                --admin_password=$WP_ADMIN_PASSWORD \
                --admin_email=$WP_ADMIN_EMAIL \
                --allow-root
                
echo "[NOTICE] : creating a user..."
sleep 5

wp user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PASSWORD --allow-root

fi

chown -R www-data:www-data /var/www/*
chmod -R 755 /var/www/*
echo "[NOTICE] : wordpress online"
exec php-fpm7.3 -F -R
