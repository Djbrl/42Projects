/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:47:54 by dsy               #+#    #+#             */
/*   Updated: 2019/12/04 00:49:26 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static unsigned long	ft_power(unsigned long x, int y)
{
	if (y == 0 || x == 1)
		return (1);
	if (x == 0 || y < 0)
		return (0);
	return (x * ft_power(x, --y));
}

void					ft_putnbr_x(unsigned long value)
{
	int				len;
	unsigned long	rest;
	char			*res;
	int				base;

	base = 16;
	len = 0;
	if (value < 10)
		len = 1;
	else
		while (ft_power(base, len) <= value)
			len++;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return ;
	if (value < 10)
		res[0] = '0' + value;
	else
		while (--len >= 0)
		{
			rest = value % base;
			res[len] = ((rest < 10) ? '0' : 'A' - 10) + rest;
			value /= base;
		}
	ft_putstr(res);
	free(res);
}

/*
void	ft_putnbr_x(unsigned long value)
{
	int				len;
	unsigned long	rest;
	int base = 16;

	len = 0;

	if (value < 10)
		ft_putchar(value + '0');
	else
		while (value > 0)
		{
			rest = value % base;
			ft_putchar(((rest < 10) ? '0' : 'A' - 10) + rest);
			value /= base;
		}
}

*
{
	unsigned long nb;
	char *base = "0132456789abcdef";

	nb = (unsigned long)n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb < 16)
	{
		ft_putchar(base[nb]);
		return ;
	}
	ft_putnbr_x(nb / 16);
	ft_putchar(base[nb % 16]);
	return ;
}*/

int						s_conversion(va_list params, char arg_type)
{
	char *conv_arg;
	char c;

	c = 0;
	if (arg_type == 's')
	{
		conv_arg = (char*)va_arg(params, char*);
		ft_putstr(conv_arg);
	}
	else
	{
		c = (char)va_arg(params, int);
		write(1, &c, 1);
	}
	return (1);
}

int						p_conversion(va_list params)
{
	void *p;

	write(1, "0x", 2);
	p = va_arg(params, void*);
	ft_putnbr_x((unsigned long)p);
	return (1);
}

int						i_conversion(va_list params, char arg_type)
{
	int		conv_arg;
	char	c;

	c = 0;
	if (arg_type == 'i' || arg_type == 'd')
		conv_arg = (int)va_arg(params, int);
	else
		conv_arg = (unsigned int)va_arg(params, int);
	ft_putnbr(conv_arg);
	return (1);
}

int						x_conversion(va_list params)
{
	int conv_arg;

	conv_arg = (int)va_arg(params, int);
	ft_putnbr_x(conv_arg);
	return (1);
}
