DOCKER_COMPOSE_FILE := srcs/docker-compose.yml
DATA_DB_DIR := /home/$(USER)/data/db
DATA_WEBSITE_DIR := /home/$(USER)/data/website

up:
		sudo docker-compose -f $(DOCKER_COMPOSE_FILE) up --build --force-recreate

down:
		sudo docker-compose -f $(DOCKER_COMPOSE_FILE) down

# container status
ps:
		sudo docker-compose -f $(DOCKER_COMPOSE_FILE) ps -a
		sudo docker ps -a

# Clean up
clean:
		sudo docker-compose -f $(DOCKER_COMPOSE_FILE) down --volumes
		sudo docker system prune --volumes
		sudo rm -rf $(DATA_DB_DIR) $(DATA_WEBSITE_DIR)
		mkdir -p $(DATA_DB_DIR) $(DATA_WEBSITE_DIR)

re: clean up

# Raccourci mariaDB
mariadb:
		sudo docker-compose -f $(DOCKER_COMPOSE_FILE) exec mariadb bash

.PHONY: up down ps clean re mariadb
