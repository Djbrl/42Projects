# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsy <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 17:08:38 by dsy               #+#    #+#              #
#    Updated: 2020/02/14 20:07:45 by dsy              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OBJS = srcs/*\

#SRCS = srcs/*\

LIBFTPATH = includes/libft 
LIBOBJ = includes/libft/libft.a

all:
	@cd $(LIBFTPATH) && make
	@gcc -Wall -Wextra -Werror srcs/parser/*.c $(LIBOBJ)

clean:
	@cd $(LIBFTPATH) && make clean
	@/bin/rm -f srcs/parser/*.o
	#@/bin/rm -f $(OBJS)

fclean: clean
	@cd $(LIBFTPATH) && make fclean
	#@/bin/rm -f $(NAME)

re: fclean all
