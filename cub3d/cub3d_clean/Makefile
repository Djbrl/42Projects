# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsy <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 17:08:38 by dsy               #+#    #+#              #
#    Updated: 2020/02/20 19:59:32 by dsy              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OBJS = srcs/*\

SRCS = srcs/*/*.c

LIBFTPATH = includes/libft 
LIBOBJ = includes/libft/libft.a

libft:
	@cd $(LIBFTPATH) && make

all: libft
	gcc $(SRCS) main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit $(LIBOBJ) -o cub3D

clean:
	@cd $(LIBFTPATH) && make clean

fclean: clean
	@cd $(LIBFTPATH) && make fclean

re: fclean all

.PHONY: libft, all, clean, fclean, re
