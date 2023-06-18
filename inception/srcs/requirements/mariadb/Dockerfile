# Use the official NGINX base image
FROM debian:buster

RUN apt update -y
RUN apt upgrade -y

RUN     apt-get update \
        && apt-get -y install apt-utils mariadb-server mariadb-client \
        && mkdir -p /var/run/mysqld \
        && chown -R mysql:mysql /var/lib/mysql  /var/run/mysqld \
        && chmod 777 /var/run/mysqld

EXPOSE  3306
COPY requirements/mariadb/conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf
COPY requirements/mariadb/conf/init.sh .

ENTRYPOINT ["bash", "./init.sh"]

