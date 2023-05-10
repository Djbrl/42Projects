# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsy <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 19:35:10 by dsy               #+#    #+#              #
#    Updated: 2023/05/02 19:35:11 by dsy              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#---------------------------------VARIABLES------------------------------------#

GREEN_COLOR = \033[0;32m
NAME = Animal

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

SRCS = src/Animal.cpp src/Cat.cpp src/Dog.cpp src/main.cpp
OBJS = $(SRCS:.cpp=.o)

BUILD_PATH = build/

#---------------------------------VARIABLES------------------------------------#


all: $(NAME)
	@echo "Ready : ${GREEN_COLOR}`pwd`/${NAME}${END_COLOR}"
	@mkdir -p $(BUILD_PATH)
	@mv $(OBJS) $(BUILD_PATH)

$(NAME): $(OBJS)
	@$(CC) ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	@rm -rf $(BUILD_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(BUILD_PATH)

re: fclean all
