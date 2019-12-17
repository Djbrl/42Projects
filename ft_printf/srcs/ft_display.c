/* ************************************************************************** */

#include "../includes/libftprintf.h"

void                    print_balise_nb(int nb, char c, t_field field)
{
	int     width;
	int	precision;
	int	len;

	len = count_digit(nb, c);
	precision = (field.precision == 0) ? len : field.precision - len;
	(field.flags[2] == ' ' && nb >= 0) ? ft_putchar(' ') : 0;
	width = (field.flags[0] == '+' || field.flags[2] == '-') ?
		field.width - precision -1 : field.width - precision;
	if (field.flags[1] != '-' && field.flags[3] != '0')
		while (width > 0 && width--)
			ft_putchar(' ');
	(field.flags[0] == '+') ? ft_putchar('+') : 0;
	while (precision > 0 && precision-- && field.precision != 0)
		ft_putchar('0');
	if (field.flags[1] == '-')
	{
		(c == 'x' || c == 'X') ? ft_putnbr_x(nb, c) : ft_putnbr(nb);
		while (width > 0 && width--)
			ft_putchar(' ');
		return;
	}
	if (field.flags[3] == '0')
		while (width > 0 && width--)
			ft_putchar('0');
	(c == 'x' || c == 'X') ? ft_putnbr_x(nb, c) : ft_putnbr(nb);
}

void	to_set_str(t_field field, int width)
{
	if (field.width > field.precision && field.flags[1] != '-')
	{
		if (field.precision > 0)
			while (field.precision --)
				ft_putchar(' ');
		else
			while (width > 0 && width--)
				ft_putchar(' ');
	}
	else if (field.width > field.precision && field.flags[1] == '-')
	{
		if (field.precision > 0)
			while (field.precision --)
				ft_putchar(' ');
		else
			while (width > 0 && width--)
				ft_putchar(' ');
	}
}

void	print_balise_str(char *str, t_field field)
{
	int	width;
	int	precision;
	int	len;
	int	cpy;
	int	i;

	i = 0;
	len = ft_strlen(str);
	precision = (field.precision > len) ?
	field.precision - len : len - field.precision;
	width = field.width - precision;
	cpy = (field.precision == 0) ? width : field.precision;
	if (field.width < len && field.precision == 0)
	{
		ft_putstr(str);
		return;
	}
	to_set_str(field, width);
	while(cpy > 0 && cpy--)
	{
		ft_putchar(str[i]);
		i++;
	}
	to_set_str(field, width);
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
		while(width > 0 && width--)
			ft_putchar(' ');
		ft_putchar(c);
	}
}

void	print_balise_add(unsigned long p, char c, t_field field)
{
	int     width;

	width = (p != 0) ? field.width - 14 : field.width;
	if (width > 0 && field.flags[1] != '-')
		while (width--)
			ft_putchar(' ');
	else if(field.flags[1] == '-')
	{
		ft_putnbr_x(p, c);
		while (width > 0 && width--)
			ft_putchar(' ');
	}
	field.flags[1] != '-' ? ft_putnbr_x(p, c) : 0;
}
