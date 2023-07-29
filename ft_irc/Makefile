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

GREY = \033[90m
BWHITE := \033[1;97m
RESET = \033[0m
GREEN_COLOR = \033[0;32m
NAME = ircserver

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

SRCS = src/main.cpp src/Server/AServer.cpp src/Server/IrcServer.cpp		\
       src/Utils/Utils.cpp src/User/User.cpp src/Channel/Channel.cpp	\
	   src/Server/IrcServer_EstablishConnection.cpp

BUILD_PATH = build/

OBJS = $(addprefix $(BUILD_PATH), $(notdir $(SRCS:.cpp=.o)))

# Set VPATH to the directories where the source files are located
VPATH = src src/Server src/Utils src/User src/Channel

#---------------------------------VARIABLES------------------------------------#

.PHONY: all clean fclean re

# Create a pattern rule for generating object files in the build/ directory
$(BUILD_PATH)%.o: %.cpp
	@mkdir -p $(BUILD_PATH)
	@echo "$(GREY)Compiling...$(RESET)                $(WHITE)$(RESET)$<"
	@$(CC) $(CFLAGS) -Iinclude -c $< -o $@

# Relink guard
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME) client
	@stty -echoctl # Silence echo for signals 
	@echo "Ready : ${GREEN_COLOR}`pwd`/${NAME}${RESET}"


client:
	@c++ client.cpp -Iinclude -o ircClient

clean:
	@rm -f $(OBJS)

# Delete the entire build/ directory when running make fclean
fclean:
	@rm -rf $(BUILD_PATH) $(NAME)

re: fclean all


