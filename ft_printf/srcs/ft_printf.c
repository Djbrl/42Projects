/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:26:52 by dsy               #+#    #+#             */
/*   Updated: 2019/11/28 04:58:19 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'd' || c == 'u'
			|| c == 'x')
		return (1);
	return (0);
}

static void	print_text(const char *str, va_list params, t_convs conv_arg)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_conversion(str[i + 1]))
		{
			//which_arg
		}
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		write(1, &str[i], 1);
		i++;
	}
}

int			ft_printf(const char *format, ...)
{
	int i;
	va_list params;
	t_convs conv_arg;

	va_start(params, format);
	conv_arg.i = (int)va_arg(params, int);
	conv_arg.s = (char*)va_arg(params, char*);
	i = 0;
	if (format == NULL)
		return (-1);
	print_text(format, params, conv_arg);
	va_end(params);
	return (0);
}
