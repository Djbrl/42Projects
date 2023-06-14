# Use the official NGINX base image
FROM debian:buster

RUN apt update -y
RUN apt upgrade -y

RUN     apt-get update \
        && apt-get -y install apt-utils mariadb-server mariadb-client \
        && rm -rf /var/lib/mysql \
        && mkdir -p /var/lib/mysql /run/mysqld \
        && chown -R mysql:mysql /var/lib/mysql  /run/mysqld \
        && chmod 777 /var/run/mysqld 

EXPOSE  3306
COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf
COPY conf/init.sh .

ENTRYPOINT ["bash", "./init.sh"]

