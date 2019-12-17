#include "../includes/libftprintf.h"

unsigned long    ft_power(unsigned long x, unsigned long y)
{
	if (y == 0 || x == 1)
		return (1);
	return (x * ft_power(x, --y));
}

void			ft_putnbr_x(unsigned long value, char c)
{
	int             len;
	unsigned long   rest;
	char            *res;
	int             base;
	char		tmp;

	tmp = (c == 'X') ? 'A' : 'a';
	if (value == 0)
		return ;
	base = 16;
	len = 0;
	(c == 'X' || c == 'x') ? 0: write(1, "0x", 2);
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
			res[len] = ((rest < 10) ? '0' : tmp - 10) + rest;
			value /= base;
		}
	ft_putstr(res);
	free(res);
}

int	count_digit(int nb, char c)
{
	int	count;
	int	div;

	count = 0;
	div = (c == 'd' || c == 'i' || c == 'u') ? 10 : 16;
	while(nb)
	{
		nb = nb /div;
		count++;
	}
	return (count);
}

int                     is_conversion(char c)
{
        if (c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'd' || c == 'u'
                        || c == 'x' || c == 'X')
                return (1);
        return (0);
}

int                     check_balise(char c)
{
        if (c == '+' || c == '-' || c == '0' || c == ' ' || c == '.'
	 || (c >= '0' && c <= '9') || c == '*')
                return (1);
        return (0);
}
