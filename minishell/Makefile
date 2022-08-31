# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsy <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 16:57:45 by dsy               #+#    #+#              #
#    Updated: 2022/08/31 16:57:47 by dsy              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#---------------------------------VARIABLES------------------------------------#

GREEN_COLOR = \033[0;32m
YLW_COLOR = \033[0;33m
END_COLOR = \033[0m

NAME := minishell

LIB_FT := libft/libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
PFLAGS := -Iinclude -Ilibft

SRC_OTHER := main.c display.c msh_control.c utils.c builtins/builtins_1.c \
			 msh_struct.c builtins/builtins_2.c builtins/builtins_runner.c \
			 list_utils.c minishell.c \

SRC_PATH := src
SRC_NAME := $(SRC_OTHER)

OBJ_PATH := obj
OBJ_NAME := $(SRC_NAME:.c=.o)

INCDIR := include
BUILD_PATH := build

SRC := $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ := $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ := $(addprefix $(BUILD_PATH)/,$(OBJ))

#---------------------------------VARIABLES------------------------------------#

all: ${NAME}
	@echo "Ready : ${GREEN_COLOR}`pwd`/${NAME}${END_COLOR}"

$(NAME): $(OBJ) $(LIB_FT)
	@$(CC) $(OBJ) $(LIB_FT) $(CFLAGS) -o $(NAME)

$(BUILD_PATH)/$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(PFLAGS) -c $< -o $@

$(LIB_FT):
	@echo "${YLW_COLOR}Compiling ${NAME}...${END_COLOR}"
#	@make -C lib/libft

libft_clean:
#	@make -C lib/libft clean

libft_fclean:
#	@make -C lib/libft fclean

re: fclean all

clean: libft_clean
	@rm -rf $(BUILD_PATH)

fclean : libft_fclean
	@rm -rf $(BUILD_PATH)
	@rm -rf $(NAME)

.PHONY: all, clean, fclean, re