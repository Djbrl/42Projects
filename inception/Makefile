DOCKER_COMPOSE_FILE := srcs/docker-compose.yml
DATA_DB_DIR := /home/$(USER)/data/db
DATA_WEBSITE_DIR := /home/$(USER)/data/website

up:
		docker-compose -f $(DOCKER_COMPOSE_FILE) up --build --force-recreate

down:
		docker-compose -f $(DOCKER_COMPOSE_FILE) down

# container status
ps:
		docker-compose -f $(DOCKER_COMPOSE_FILE) ps -a
		docker ps -a

# Clean up
clean:
		docker-compose -f $(DOCKER_COMPOSE_FILE) down --volumes
		docker system prune --volumes
		rm -rf $(DATA_DB_DIR) $(DATA_WEBSITE_DIR)
		mkdir -p $(DATA_DB_DIR) $(DATA_WEBSITE_DIR)

re: clean up

# Raccourci mariaDB
mariadb:
		docker-compose -f $(DOCKER_COMPOSE_FILE) exec mariadb bash

.PHONY: up down ps clean re mariadb
