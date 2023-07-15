# Makefile for managing Docker containers

DOCKER_COMPOSE_FILE := srcs/docker-compose.yml
DATA_DB_DIR := /home/$(USER)/data/db
DATA_WEBSITE_DIR := /home/$(USER)/data/website

all: up

# Build and start the containers
up:
		sudo docker-compose -f $(DOCKER_COMPOSE_FILE) build
		sudo docker-compose -f $(DOCKER_COMPOSE_FILE) up --force-recreate

# Stop and remove the containers
down:
		sudo docker-compose -f $(DOCKER_COMPOSE_FILE) down

# Show container status
ps:
		sudo docker-compose -f $(DOCKER_COMPOSE_FILE) ps -a
		sudo docker ps -a

# Clean up containers and volumes
clean: down
		sudo docker system prune
		sudo docker volume rm srcs_db srcs_website
		sudo rm -rf $(DATA_DB_DIR)
		sudo rm -rf $(DATA_WEBSITE_DIR)
		mkdir -p $(DATA_DB_DIR)
		mkdir -p $(DATA_WEBSITE_DIR)

# Rebuild and start the containers
re: clean up

# Access the MariaDB container
mariadb:
		sudo docker exec -it mariadb bash

# Access the Nginx container
nginx:
		sudo docker exec -it nginx bash

# Access the WordPress container
wordpress:
		sudo docker exec -it wordpress bash

.PHONY: all up down ps clean re mariadb nginx wordpress
