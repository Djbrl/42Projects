
#include "../includes/libftprintf.h"

unsigned long    ft_power(unsigned long x, unsigned long y)
{
	if (y == 0 || x == 1)
		return (1);
	/*if (x == 0 || y < 0)
	  return (0);*/
	return (x * ft_power(x, --y));
}

void			ft_putnbr_x(unsigned long value)
{
	int             len;
	unsigned long   rest;
	char            *res;
	int             base;

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

int	count_digit(int c)
{
	int	count;

	count = 0;
	while(c)
	{
		c = c /10;
		count++;
	}
	return (count);
}

void			print_balise(int c, t_field field)
{
	int	width;
	int	precision;

	precision = field.precision - count_digit(c);
	field.flags[2] == ' ' ? ft_putchar(' ') : 0;
	if (count_digit(c) >= field.precision)
		field.precision = 0;
	width = (field.flags[0] == '+') ? field.width - field.precision - 1 - count_digit(c) : field.width - field.precision - count_digit(c);
	if (field.flags[1] != '-' && field.flags[3] != '0'&& width > 0)
		while(width--)
			ft_putchar(' ');
	field.flags[0] == '+' ? ft_putchar('+') : 0;
	while (precision > 0 && precision--)
		ft_putchar('0');
	if (field.flags[1] == '-' && field.precision == 0)
	{
		ft_putnbr(c);
		while(width--)
			ft_putchar(' ');
	}
	if (field.flags[3] == '0' && field.precision == 0)
		while(width--)
			ft_putchar('0');
	ft_putnbr(c);
}
