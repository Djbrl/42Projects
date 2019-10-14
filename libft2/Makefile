# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djsy <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 16:31:35 by djsy              #+#    #+#              #
#    Updated: 2019/10/11 16:09:03 by dsy              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJS = *.o

SRCS = *.c

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $^

$(OBJS): $(SRCS)
	gcc -Wall -Wextra -Werror $^ -c

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
