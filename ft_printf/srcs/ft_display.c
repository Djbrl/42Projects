#include "../includes/libftprintf.h"

void                    print_balise_nb(int c, t_field field)
{
	int     width;
	int     precision;
	int     stock;

	if (count_digit(c) >= field.precision)
		field.precision = 0;
	precision = (field.precision == 0) ? count_digit(c) : field.precision - count_digit(c);
	stock = (field.flags[0] == '+' || field.flags[0] == ' ') ? precision + 1 : precision;
	field.flags[2] == ' ' && c >= 0 ? ft_putchar(' ') : 0;
	width = (field.flags[0] == '+' || field.flags[2] == ' ') ? field.width - field.precision -1 : field.width - field.precision;
	if (field.flags[1] != '-' && field.flags[3] != '0')
		while(width > 0 && width--)
			ft_putchar(' ');
	field.flags[0] == '+' ? ft_putchar('+') : 0;
	while (precision > 0 && precision-- && field.precision != 0)
		ft_putchar('0');
	if (field.flags[1] == '-')
	{
		ft_putnbr(c);
		while (width > 0 && width-- && field.precision != 0)
			ft_putchar(' ');
	}
	if (field.flags[3] == '0' && field.precision == 0)
		while(stock++ < field.width)
			ft_putchar('0');
	field.flags[1] == '-' ? 0 : ft_putnbr(c);
	while (stock++ < field.width && width > 0 && field.precision == 0)
		ft_putchar(' ');
}

void	print_balise_str(char *str, t_field field)
{
	int	width;
	int	precision;
	int	len;
	int	cpy;

	len = ft_strlen(str);
	precision = (field.precision > len) ? field.precision - len : len - field.precision;
	width = field.width - precision;
	cpy = (field.precision == 0) ? width : field.precision;
	if (field.width < len && field.precision == 0)
	{
		ft_putstr(str);
		return;
	}
	if (field.width > field.precision && field.flags[1] != '-')
	{
		if (field.precision > 0)
			while (field.precision --)
				ft_putchar(' ');
		else
			while (width > 0 && width--)
				ft_putchar(' ');
	}
	while(cpy > 0 && cpy--)
	{
		ft_putchar(*str);
		*str++;
	}
	if(field.width > field.precision && field.flags[1] == '-')
	{
                if (field.precision > 0)
                        while (field.precision --)
                                ft_putchar(' ');
                else
                        while (width > 0 && width--)
                                ft_putchar(' ');
	}
}
void	print_balise_char(char c, t_field field)
{
	return;
}
