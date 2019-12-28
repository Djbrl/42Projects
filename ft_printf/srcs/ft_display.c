/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:30:22 by dsy               #+#    #+#             */
/*   Updated: 2019/12/28 03:13:57 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_balise_nb(int nb, char c, t_field field, int len)
{
	int	width;
	int	precision;

	precision = (field.precision > len) ? field.precision - len : len;
	(field.flags[2] == ' ' && nb >= 0) ? ft_putchar(' ') : 0;
	width = (field.flags[0] == '+' || field.flags[2] == '-') ?
		field.width - precision - 1 : field.width - precision;
	if (field.flags[1] != '-' && field.flags[3] != '0')
		while (width > 0 && width--)
			ft_putchar(' ');
	(field.flags[0] == '+') ? ft_putchar('+') : 0;
	/*while (precision > 0 && precision-- && field.precision != 0)
		ft_putchar('0');*/
	if (field.flags[1] == '-')
	{
		(c == 'x' || c == 'X') ? ft_putnbr_x(nb, c) : ft_putnbr(nb);
		while (width > 0 && width--)
			ft_putchar(' ');
		return ;
	}
	if (field.flags[3] == '0')
		while (width > 0 && width--)
			ft_putchar('0');
	(c == 'x' || c == 'X') ? ft_putnbr_x(nb, c) : ft_putnbr(nb);
}

void	to_set_str(int width, t_field field, char *str)
{
	if (!str)
		if (field.precision > 6)
			width = 4;
	while (width > 0 && width--)
		ft_putchar(' ');
}

void	print_balise_str(char *str, t_field field)
{
	int		width;
	int		precision;
	int		len;
	char	*null;

	null = "(null)";
	len = ft_strlen(str);
	precision = (field.precision > 0) ? field.precision : len;
	width = field.width - precision;
	if (field.width <= len && field.precision == 0)
	{
		ft_putstr(str);
		return ;
	}
	if (field.flags[1] != '-')
		to_set_str(width, field, str);
	if (str)
		while (precision > 0 && precision-- && *str)
			ft_putchar(*str++);
	else
		while (field.precision > 0 && field.precision-- && *null)
			ft_putchar(*null++);
	if (field.flags[1] == '-')
		to_set_str(width, field, str);
}

void	print_balise_char(char c, t_field field)
{
	int width;

	width = (field.width > 1) ? field.width - 1 : 0;
	if (field.flags[1] == '-')
	{
		ft_putchar(c);
		while (width > 0 && width--)
			ft_putchar(' ');
	}
	else
	{
		while (width > 0 && width--)
			ft_putchar(' ');
		ft_putchar(c);
	}
}

void	print_balise_add(unsigned long p, char c, t_field field)
{
	int		width;

	width = (p != 0) ? field.width - 14 : field.width;
	if (width > 0 && field.flags[1] != '-')
		while (width--)
			ft_putchar(' ');
	else if (field.flags[1] == '-')
	{
		ft_putnbr_x(p, c);
		while (width > 0 && width--)
			ft_putchar(' ');
	}
	field.flags[1] != '-' ? ft_putnbr_x(p, c) : 0;
}
