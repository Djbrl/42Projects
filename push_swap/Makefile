# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsy <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 12:24:49 by dsy               #+#    #+#              #
#    Updated: 2022/04/05 15:59:06 by dsy              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#---------------------------------VARIABLES------------------------------------#
GREEN_COLOR = \033[0;32m
YLW_COLOR = \033[0;33m
END_COLOR = \033[0m
NAME := push_swap

LIB_FT := lib/libft/libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
PFLAGS := -Iinclude -Ilib/libft

SRC_PATH := src
SRC_NAME := main.c stack_functions.c utility_functions.c sorting_functions.c \
			operations/operations_sim.c operations/operations_rot.c \
			operations/operations_push_swap.c

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
	@make -C lib/libft

libft_clean:
	@make -C lib/libft clean

libft_fclean:
	@make -C lib/libft fclean

re: fclean all

clean: libft_clean
	@rm -rf $(NAME)

fclean : libft_fclean
	@rm -rf $(BUILD_PATH)
	@rm -rf $(NAME)

#norminette will return an error/sude code for Makefile ! No need to print
norm :
	norminette > /dev/null

leaks :
	@make -s
	@valgrind ./${NAME} --full-check=yes

.PHONY: all, clean, fclean, re, leaks, norm