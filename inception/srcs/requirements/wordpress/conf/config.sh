#!/bin/sh

# Downloads the WordPress core in French
wp core download --locale=fr_FR --allow-root

sleep 5

# Checks if wp-config.php file already exists
if [ -f /var/www/html/wp-config.php ]; then
    echo "===> wp-config.php already exists <==="
    sleep 5
else
    echo "===> creating wp-config.php <==== "
    sleep 5
    wp config create --dbname=$MYSQL_DB_NAME --dbuser=$WP_ADMIN --dbpass=$WP_ADMIN_PASSWORD --allow-root

    # Configures the wp-config.php file with database and site settings
    wp core config --dbname=$MYSQL_DB_NAME \
                  --dbuser=$WP_ADMIN \
                  --dbpass=$WP_ADMIN_PASSWORD \
                  --dbhost=$MYSQL_DB_HOST \
                  --dbcharset=$WP_CHARSET \
                  --dbprefix=wp_ \
                  --dbcollate="utf8_general_ci" \
                  --allow-root

    echo "===> Installing WordPress <==== "
    sleep 5

    # Installs WordPress with specified settings
    wp core install --url="dsy.42.fr" \
                    --title=INCEPTION \
                    --admin_user=$WP_ADMIN \
                    --admin_password=$WP_ADMIN_PASSWORD \
                    --admin_email=$WP_ADMIN_EMAIL \
                    --allow-root

    echo "===> Creating a user <==="
    sleep 5

    # Creates a user with specified details and author role
    wp user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PASSWORD --allow-root
fi

# Sets ownership and permissions for WordPress files
chown -R www-data:www-data /var/www/*
chmod -R 755 /var/www/*

echo "===> WORDPRESS IS UP <==="
# Starts php-fpm in foreground mode
exec php-fpm7.3 -F -R

