/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:47:54 by dsy               #+#    #+#             */
/*   Updated: 2020/01/06 11:20:29 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**void	ft_putnbr_x(unsigned long value)
**{
**	int				len;
**	unsigned long	rest;
**	int base = 16;
**
**	len = 0;
**
**	if (value < 10)
**		ft_putchar(value + '0');
**	else
**		while (value > 0)
**		{
**			rest = value % base;
**			ft_putchar(((rest < 10) ? '0' : 'A' - 10) + rest);
**			value /= base;
**		}
**}
**
**
**{
**	unsigned long nb;
**	char *base = "0132456789abcdef";
**
**	nb = (unsigned long)n;
**	if (nb < 0)
**	{
**		nb *= -1;
**		ft_putchar('-');
**	}
**	if (nb < 16)
**	{
**		ft_putchar(base[nb]);
**		return ;
**	}
**	ft_putnbr_x(nb / 16);
**	ft_putchar(base[nb % 16]);
**	return ;
**}
*/
void					percent_conversion()
{
	write(1, "%", 1);
}

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
	ft_putnbr_x((unsigned long)p, 'x');
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

int						x_conversion(va_list params, char arg_type)
{
	int conv_arg;

	conv_arg = (int)va_arg(params, int);
	ft_putnbr_x(conv_arg, arg_type);
	return (1);
}
