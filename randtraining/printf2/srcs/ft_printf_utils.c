/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:52:46 by dsy               #+#    #+#             */
/*   Updated: 2020/02/04 19:46:43 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int				is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'd' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

unsigned long	ft_power(unsigned long x, unsigned long y)
{
	if (y == 0 || x == 1)
		return (1);
	return (x * ft_power(x, --y));
}

void			neg_value(unsigned long *value)
{
	if (*value < 0)
	{
		*value *= -1;
		write(1, "-", 1);
	}
}

void			ft_putnbr_x(unsigned long value, char type)
{
	int				len;
	unsigned long	rest;
	char			*res;
	char			tmp;

	neg_value(&value);
	tmp = (type == 'X') ? 'A' : 'a';
	len = (value < 10) ? 1 : 0;
	(type == 'X' || type == 'x') ? 0 : ft_putstr("0x");
	while ((ft_power(16, len) <= value) && value >= 10)
		len++;
	if (!(res = malloc(sizeof(char) * (len))))
		return ;
	res[len] = 0;
	if (value < 10)
		res[0] = '0' + value;
	else
		while (--len >= 0)
		{
			rest = value % 16;
			res[len] = ((rest < 10) ? '0' : tmp - 10) + rest;
			value /= 16;
		}
	ft_putstr(res);
	g_ret += ft_strlen(res);
	free(res);
}
