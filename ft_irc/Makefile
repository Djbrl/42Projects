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
NAME = ircserver

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

SRCS = src/main.cpp src/server/AServer.cpp src/server/IrcServer.cpp \
       src/utils/Utils.cpp src/server/User/User.cpp src/server/Channel/Channel.cpp

# Change the location for the object files to be stored in the build/ directory
BUILD_PATH = build/

# Generate the object file names by replacing the .cpp extension with .o in SRCS
OBJS = $(addprefix $(BUILD_PATH), $(notdir $(SRCS:.cpp=.o)))

# Set VPATH to the directories where the source files are located
VPATH = src src/server src/utils src/server/User src/server/Channel

#---------------------------------VARIABLES------------------------------------#

.PHONY: all clean fclean re

# Create a pattern rule for generating object files in the build/ directory
$(BUILD_PATH)%.o: %.cpp
	@mkdir -p $(BUILD_PATH)
	@echo "$(GREY)Compiling...                $(WHITE)$<"
	@$(CC) $(CFLAGS) -Iinclude -c $< -o $@

all: $(NAME) client
	@echo "Ready : ${GREEN_COLOR}`pwd`/${NAME}${END_COLOR}"

# Depend directly on the object files for the executable $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

client:
	c++ client.cpp -Iinclude -o ircClient

clean:
	@rm -f $(OBJS)

# Delete the entire build/ directory when running make fclean
fclean:
	@rm -rf $(BUILD_PATH) $(NAME)

re: fclean all


