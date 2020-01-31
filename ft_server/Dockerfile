# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsy <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 20:42:34 by dsy               #+#    #+#              #
#    Updated: 2020/01/29 18:21:49 by dsy              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Image
FROM debian:buster

#Installations
RUN apt-get update -y
RUN apt-get install -y nginx
RUN apt-get install -y wget
RUN apt-get install -y unzip
RUN apt-get install -y php-fpm
RUN apt-get install -y php-mysql
RUN apt-get install -y mariadb-server
RUN apt-get install -y mariadb-client

#Wordpress
RUN wget https://fr.wordpress.org/wordpress-latest-fr_FR.zip
RUN unzip wordpress-latest-fr_FR.zip -d /var/www
RUN chown www-data:www-data /var/www/wordpress -R
RUN chmod -R -wx,u+rwX,g+rX,o+rX /var/www/wordpress
