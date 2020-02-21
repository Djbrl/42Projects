# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsy <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 20:42:34 by dsy               #+#    #+#              #
#    Updated: 2020/02/21 16:31:25 by dsy              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Image
FROM debian:buster

#Installations
RUN apt-get update -y
RUN apt-get install -y nginx
RUN apt-get install -y wget
RUN apt-get install -y unzip
RUN  sudo apt install php7.3 php7.3-fpm php7.3-mysql php-common php7.3-cli php7.3-common php7.3-json php7.3-opcache php7.3-readline
RUN apt-get install -y mariadb-server
RUN apt-get install -y mariadb-client

#MariaDB
RUN systemctl enable mariadb
RUN sudo mariadb -u root

#PHP
RUN sudo systemctl enable php7.3-fpm

#Nginx
RUN systemctl enable nginx
RUN sudo chown www-data:www-data /usr/share/nginx/html/ -R
RUN sudo rm /etc/nginx/sites-enabled/default


#Wordpress
RUN wget https://fr.wordpress.org/wordpress-latest-fr_FR.zip
RUN unzip wordpress-latest-fr_FR.zip -d /var/www
RUN chown www-data:www-data /var/www/wordpress -R
RUN chmod -R -wx,u+rwX,g+rX,o+rX /var/www/wordpress
