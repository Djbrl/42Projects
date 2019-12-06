
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

void			print_balise(int c, t_field field)
{
	int stock;
	char *tmp;

	tmp = ft_itoa(c);
	if (field.flags[0] == '+')
		ft_putchar('+');
	if (field.flags[2] == ' ')
		ft_putchar(' ');
	printf("flags = %s || width = %d || precision =  %d || error = %d\n", field.flags, field.width, field.precision, field.error);
	if (field.width != 0)
	{
		stock = (field.flags[0] == '+') ? field.width - ft_strlen(tmp) - 1 : field.width - ft_strlen(tmp);
		if (field.flags[1] == '-')
		{
			ft_putnbr(c);
			while (stock)
			{
				ft_putchar(' ');
				stock--;
			}
		}
		else if (field.flags[3] == '0')
		{
			while (stock)
                        {
                                ft_putchar('0');
                                stock--;
                        }
			ft_putnbr(c);
		}
		else
		{
			while(stock)
			{
				ft_putchar(' ');
				stock--;
			}
			ft_putnbr(c);
		}
	}
}


