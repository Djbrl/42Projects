/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:26:52 by dsy               #+#    #+#             */
/*   Updated: 2019/12/04 06:23:09 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'd' || c == 'u'
			|| c == 'x')
		return (1);
	return (0);
}

static int	which_arg(char arg, va_list params)
{
	if (arg == 'c' || arg == 's')
		if (!(s_conversion(params, arg)))
			return (0);
	if (arg == 'i' || arg == 'd' || arg == 'u')
		if (!(i_conversion(params, arg)))
			return (0);
	if (arg == 'p')
		if (!(p_conversion(params)))
			return (0);
	if (arg == 'x')
		if (!(x_conversion(params)))
			return (0);
	return (1);
}

static int	print_text(const char *str, va_list params, t_field field)
{
	int 	i;
	t_field tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		else if (str[i] == '%' && !is_conversion(str[i + 1]))
		{
			tmp = is_balise((char *)&str[i], field);
			/*printf("flag = %c %c %c %c || width = %zu || precision = %lu\n", tmp.flags[0], tmp.flags[1], tmp.flags[2], tmp.flags[3] , tmp.width, tmp.precision);*/
		}
		if (str[i] == '%')
		{
			if (!(which_arg(str[i + 1], params)))
				return (0);
			i = i + 2;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	int		i;
	va_list params;
	t_field field;

	field.flags[0] = '0';
	field.flags[1] = '0';
	field.flags[2] = '0';
	field.flags[3] = '0';
	field.width = 0;
	va_start(params, format);
	i = 0;
	if (format == NULL)
		return (-1);
	if (!(print_text(format, params, field)))
		return (-1);
	va_end(params);
	return (0);
}
