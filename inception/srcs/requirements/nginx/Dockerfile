# Use the official NGINX base image
FROM debian:buster

RUN apt update -y
RUN apt install nginx -y
RUN apt install vim -y
RUN apt install curl -y

RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=dsy.42.fr/UID=dsy"

RUN mkdir -p /var/run/nginx

COPY conf/nginx.conf /etc/nginx/nginx.conf

RUN chmod -R 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

# Start NGINX server
CMD ["nginx", "-g", "daemon off;"]

