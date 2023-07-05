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
NAME = btcExchange

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

SRCS = src/main.cpp src/BitcoinExchange.cpp
OBJS = $(SRCS:.cpp=.o)

BUILD_PATH = build/

#---------------------------------VARIABLES------------------------------------#

.PHONY: all clean fclean re

%.o: %.cpp
	@echo "$(GREY)Compiling...                $(WHITE)$<"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	@echo "Ready : ${GREEN_COLOR}`pwd`/${NAME}${END_COLOR}"

$(NAME): $(OBJS)
	$(CC) ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	@rm -f $(NAME) $(OBJS)

fclean: clean

re: fclean all
