FROM    debian:buster


RUN     apt-get -y update \
        && apt-get -y upgrade \
        && apt-get install -y  \
        systemd \
        nginx \
        openssl \
        vim

EXPOSE  443

ADD     ./config/nginx.conf /etc/nginx/sites-available/default
RUN     rm -rf /etc/nginx/sites-enabled/default
RUN     ln -s /etc/nginx/sites-available/default /etc/nginx/sites-enabled/default

RUN     mkdir -p /etc/nginx/ssl && openssl req -newkey rsa:2048 -x509 -days 365 -nodes -keyout /etc/nginx/ssl/services.key -out /etc/nginx/ssl/services.pem \
        -subj "/C=FR/ST=Paris/L=Paris/O=42, Inc./OU=IT/CN=Inception"


CMD     ["nginx", "-g", "daemon off;"]
