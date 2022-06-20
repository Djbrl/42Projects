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
NAME := so_long

LIB_FT := lib/libft/libft.a
MLX := lib/mlx/libmlx_Linux.a

CC := cc
CFLAGS := -Wall -Wextra -Werror #-lX11 -lXext
LFLAGS = -lX11 -lXext
PFLAGS := -Iinclude -Ilib/libft -Ilib/mlx

SRC_MLX_FUNC := control_functions.c
	
SRC_MLX_FUNC := $(addprefix mlx_functions/,$(SRC_MLX_FUNC))

SRC_PARSER := input_parsing.c \
	map_parsing.c parsing.c
SRC_PARSER := $(addprefix parser/,$(SRC_PARSER))

SRC_RAYCASTING :=
SRC_RAYCASTING := $(addprefix raycasting/,$(SRC_RAYCASTING))

SRC_UTILS := utils.c
SRC_UTILS := $(addprefix utils/, $(SRC_UTILS))


SRC_PATH := src
SRC_NAME := main.c \
			$(SRC_MLX_FUNC)\
			$(SRC_PARSER)\
			$(SRC_UTILS)\
			$(SRC_RAYCASTING)

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

$(NAME): $(OBJ) $(LIB_FT) $(MLX)
	@$(CC) $(OBJ) $(LIB_FT) $(LFLAGS) $(MLX) $(CFLAGS) -o $(NAME)

$(BUILD_PATH)/$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(PFLAGS) -c $< -o $@

$(LIB_FT):
	@echo "${YLW_COLOR}Compiling ${NAME}...${END_COLOR}"
	@make -C lib/libft
	@make -C lib/mlx

libft_clean:
	@make -C lib/libft clean

libft_fclean:
	@make -C lib/libft fclean

re: fclean all

clean: libft_clean
	@rm -rf $(BUILD_PATH)

fclean : libft_fclean
	@rm -rf $(BUILD_PATH)
	@rm -rf $(NAME)

#norminette will return an error/sude code for Makefile ! No need to print
norm :
	norminette > /dev/null

leaks :
	@make -s
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) haha.ber

.PHONY: all, clean, fclean, re, leaks, norm