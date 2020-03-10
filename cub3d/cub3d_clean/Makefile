# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsy <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 17:08:38 by dsy               #+#    #+#              #
#    Updated: 2020/03/10 22:43:24 by dsy              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OBJS = srcs/*\

SRCS = srcs/parser/*.c \
	   srcs/mlx_functions/*.c \
	   srcs/utils/*.c \
	   srcs/raycasting/raycasting_utils.c \
	   srcs/raycasting/raycasting.c \

LIBFTPATH = libs/libft 
LIBOBJ = libs/libft/libft.a

libft:
	@echo "compiling..."
	cd $(LIBFTPATH) && make -j5

all: libft
	gcc $(SRCS) main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit $(LIBOBJ) -o Cub3D

clean:
	@cd $(LIBFTPATH) && make clean

fclean: clean
	@cd $(LIBFTPATH) && make fclean
	@rm Cub3D

re: fclean all

.PHONY: libft, all, clean, fclean, re
