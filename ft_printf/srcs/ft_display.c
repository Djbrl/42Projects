/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:30:22 by othabchi          #+#    #+#             */
/*   Updated: 2020/01/12 20:24:59 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_balise_nb(long nb, char c, t_field f, int len)
{
	int	width;
	int	precision;

	precision = (f.precision > len) ? f.precision - len : len;
	width = (f.precision > len) ? f.width - (precision + len) : f.width - len;
	width = (nb < 0) ? width - 1 : width;
	if (f.flags[1] != '-' && (f.flags[0] != '0' ||
	(f.flags[0] == '0' && f.precision != 0)))
		while (width > 0 && width--)
			ft_putchar(' ');
	(nb < 0) ? ft_putchar('-') : 0;
	while (precision > 0 && precision-- && f.precision > len)
		ft_putchar('0');
	if (f.flags[1] == '-')
	{
		(c == 'x' || c == 'X') ? ft_putnbr_x(nb, c) : ft_putnbr(nb);
		while (width > 0 && width--)
			ft_putchar(' ');
		return ;
	}
	if (f.flags[0] == '0' && f.precision == 0)
		while (width > 0 && width--)
			ft_putchar('0');
	(c == 'x' || c == 'X') ? ft_putnbr_x(nb, c) : ft_putnbr(nb);
}

void	to_set_str(int width, t_field field, char *str, int check)
{
	int precision;

	precision = 0;
	if (!str)
	{
		precision = (field.precision > 0 && field.precision < 6) ?
					field.precision : 6;
		width = field.width - precision;
	}
	if (check == 1)
		width = field.width;
	while (width > 0 && width--)
		ft_putchar(' ');
}

void	print_balise_str(char *s, char *str, t_field f, int len)
{
	int		width;
	int		precision;
	int		check;
	char	*null;

	null = "(null)";
	check = 0;
	check = check_precision(s, check);
	precision = (f.precision > 0 && f.precision < len) ? f.precision : len;
	width = f.width - precision;
	if (f.flags[1] != '-')
		to_set_str(width, f, str, check);
	if (str)
		while (precision > 0 && precision-- && *str && check == 0)
			ft_putchar(*str++);
	else
	{
		if (precision)
			while (precision-- && *null && check == 0)
				ft_putchar(*null++);
		else if (check == 0)
			ft_putstr(null);
	}
	if (f.flags[1] == '-')
		to_set_str(width, f, str, check);
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
