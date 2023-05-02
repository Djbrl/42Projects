# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 15:24:10 by user42            #+#    #+#              #
#    Updated: 2022/02/18 15:49:13 by idouidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------VARIABLES------------------------------------#

GREEN_COLOR = \033[0;32m
NAME = megaphone

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3#-fsanitize=address

SRCS = megaphone.cpp
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