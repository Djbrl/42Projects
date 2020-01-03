/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:30:22 by dsy               #+#    #+#             */
/*   Updated: 2019/12/30 14:40:23 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_balise_nb(int nb, char c, t_field f, int len)
{
	int	width;
	int	precision;

	if(len > f.precision)
		f.precision = 0;
	precision = (f.precision > len) ? f.precision - len : len;
	(f.flags[2] == ' ' && nb >= 0) ? ft_putchar(' ') : 0;
	width = (f.flags[0] == '+' || f.flags[2] == ' ') ?
		f.width - precision - 1 : f.width - precision;
	if (f.flags[1] != '-' && f.flags[3] != '0')
		while (width > 0 && width-- && f.width > (f.precision +len))
			ft_putchar(' ');
	(f.flags[0] == '+') ? ft_putchar('+') : 0;
	while (precision > 0 && precision-- && f.precision > 0)
		ft_putchar('0');
	if (f.flags[1] == '-')
	{
		(c == 'x' || c == 'X') ? ft_putnbr_x(nb, c) : ft_putnbr(nb);
		while (width > 0 && width-- && f.width > (f.precision +len))
			ft_putchar(' ');
		return ;
	}
	if (f.flags[3] == '0')
		while (width > 0 && width--)
			ft_putchar('0');
	(c == 'x' || c == 'X') ? ft_putnbr_x(nb, c) : ft_putnbr(nb);
}

void	to_set_str(int width, t_field field, char *str)
{
	if (!str)
		if (field.precision >= 6)
			width = field.width - 6;
	while (width > 0 && width--)
		ft_putchar(' ');
}

void	print_balise_str(char *str, t_field field)
{
	int		width;
	int		precision;
	int		len;
	char		*null;
	int		i;

	i = field.precision;
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
		while (i && i-- && field.precision >= 6 && *null)
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
