# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsy <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 17:08:38 by dsy               #+#    #+#              #
#    Updated: 2020/02/24 18:27:57 by dsy              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OBJS = srcs/*\

SRCS = srcs/*/*.c

LIBFTPATH = includes/libft 
LIBOBJ = includes/libft/libft.a

libft:
	@echo "compiling..."
	cd $(LIBFTPATH) && make -j5

all: libft
	gcc -Wall -Werror -Wextra $(SRCS) main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit $(LIBOBJ) -o Cub3D

clean:
	@cd $(LIBFTPATH) && make clean

fclean: clean
	@cd $(LIBFTPATH) && make fclean

re: fclean all

.PHONY: libft, all, clean, fclean, re
