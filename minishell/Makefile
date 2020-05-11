# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsy <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 17:08:38 by dsy               #+#    #+#              #
#    Updated: 2020/03/11 00:03:58 by dsy              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OBJS = srcs/*\

minishell = minishell

SRCS = srcs/*

LIBFTPATH = libft/ 
LIBOBJ = libft/libft.a

all: 	
	@echo "compiling..."
	@cd libft ; make
	gcc $(SRCS) main.c $(LIBOBJ) -o minishell
#	gcc $(SRCS) main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit $(LIBOBJ) -o Cub3D

clean:
	@cd $(LIBFTPATH) ; make clean

fclean: clean
	@cd $(LIBFTPATH) ; make fclean
	rm minishell
re: fclean all

.PHONY: libft, all, clean, fclean, re
