# Use the official NGINX base image
FROM debian:buster

RUN apt update -y
RUN apt upgrade -y
RUN apt install wget -y
RUN apt install vim -y
RUN apt install php7.3 php-fpm php-mysql mariadb-client -y
RUN     apt-get install -y  \
        php7.3-cli \
        php7.3-common \
        php7.3-curl \
        php7.3-mbstring \
        php7.3-mysql \
        php-fpm curl \
        mariadb-client \
        curl

EXPOSE  9000
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www
RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz
RUN chown -R root:root /var/www/wordpress

COPY requirements/wordpress/conf/php.ini /etc/php/7.3/php.ini
COPY requirements/wordpress/conf/config.sh .

ENTRYPOINT ["bash", "./config.sh"]

# Start NGINX server
# CMD ["nginx", "-g", "daemon off;"]


