/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:05:49 by dsy               #+#    #+#             */
/*   Updated: 2020/02/07 05:05:50 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

long	ft_power(long x, long y)
{
	if (y == 0 || x == 1)
		return (1);
	return (x * ft_power(x, --y));
}

void	neg_value(long *value)
{
	if (*value < 0)
	{
		*value *= -1;
		write(1, "-", 1);
	}
}

void	ft_putnbr_x(long value, char c)
{
	int				len;
	unsigned long	rest;
	char			*res;
	char			tmp;

	neg_value(&value);
	tmp = (c == 'X') ? 'A' : 'a';
	len = (value < 10) ? 1 : 0;
	(c == 'X' || c == 'x') ? 0 : ft_putstr("0x");
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
	free(res);
}
