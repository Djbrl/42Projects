# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djsy <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 16:31:35 by djsy              #+#    #+#              #
#    Updated: 2019/12/01 17:20:09 by dsy              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJS = srcs/ft_printf.o srcs/ft_printf_conv.o libft/*.o

SRCS = srcs/ft_printf.c srcs/ft_printf_conv.c

all:
	@cd libft/ && make
	@gcc -Wall -Wextra -Werror $(SRCS) -c
	@mv ft_printf.o srcs/
	@mv ft_printf_conv.o srcs/
	@ar rcs $(NAME) $(OBJS)

clean:
	@/bin/rm -f $(OBJS)
	@cd libft/ && make clean

fclean: clean
	@cd libft/ && make fclean
	@/bin/rm -f $(NAME)

re: fclean all
