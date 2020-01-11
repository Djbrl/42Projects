# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 16:31:35 by djsy              #+#    #+#              #
#    Updated: 2020/01/11 17:48:02 by othabchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJS = srcs/ft_printf.o srcs/ft_printf_conv.o srcs/ft_is_balise.o srcs/ft_pars.o srcs/ft_utils.o srcs/ft_display.o srcs/ft_nb_digit.o srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_putnbr.o srcs/ft_strlen.o srcs/ft_substr.o srcs/ft_atoi.o srcs/ft_putnbr_x.o srcs/ft_printf_pct.o

SRCS = srcs/ft_printf.c srcs/ft_printf_conv.c srcs/ft_is_balise.c srcs/ft_utils.c srcs/ft_display.c srcs/ft_pars.c srcs/ft_nb_digit.c srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_putnbr.c srcs/ft_strlen.c srcs/ft_substr.c srcs/ft_atoi.c srcs/ft_putnbr_x.c srcs/ft_printf_pct.c

all:
	@gcc -Wall -Werror -Wextra $(SRCS) -c 
	@mv ft_printf.o srcs/
	@mv ft_printf_conv.o srcs/
	@mv ft_is_balise.o srcs/
	@mv ft_pars.o srcs/
	@mv ft_utils.o srcs/
	@mv ft_display.o srcs/
	@mv ft_nb_digit.o srcs/
	@mv ft_putchar.o srcs/
	@mv ft_putstr.o srcs/
	@mv ft_putnbr.o srcs/
	@mv ft_putnbr_x.o srcs/
	@mv ft_atoi.o srcs/
	@mv ft_strlen.o srcs/
	@mv ft_substr.o srcs/
	@mv ft_printf_pct.o srcs/
	@ar rcs $(NAME) $(OBJS)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
