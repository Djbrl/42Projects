/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:52:46 by dsy               #+#    #+#             */
/*   Updated: 2019/12/27 14:08:59 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int						is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'd' || c == 'u'
			|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

unsigned long			power(unsigned long x, int y)
{
	if (y == 0 || x == 1)
		return (1);
	if (x == 0 || y < 0)
		return (0);
	return (x * power(x, --y));
}

void					ft_putnbr_x(unsigned long value, char type)
{
	int				len;
	unsigned long	rest;
	char			*res;
	char			letter_case;

	letter_case = 'a';
	type == 'X' ? (letter_case = 'A') : 1;
	len = 0;
	value < 10 ? (len = 1) : 1;
	if (len == 0)
		while (power(16, len) <= value)
			len++;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return ;
	if (value < 10)
		res[0] = '0' + value;
	else
		while (--len >= 0)
		{
			rest = value % 16;
			res[len] = ((rest < 10) ? '0' : letter_case - 10) + rest;
			value /= 16;
		}
	ft_putstr(res);
	free(res);
}
