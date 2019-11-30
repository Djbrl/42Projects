/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:26:52 by dsy               #+#    #+#             */
/*   Updated: 2019/11/30 18:12:09 by dsy              ###   ########.fr       */
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

static void	which_arg(char arg, va_list params)
{
	if (arg == 'c' || arg == 's')
		s_conversion(params);
	if (arg == 'i' || arg == 'd')
		i_conversion(params);
	//if (arg == 'p')
	//func
	//if (arg == 'x')
	//
}

static void	print_text(const char *str, va_list params)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_conversion(str[i + 1]))
			which_arg(str[i + 1], params);
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

	va_start(params, format);
	i = 0;
	if (format == NULL)
		return (-1);
	print_text(format, params);
	va_end(params);
	return (0);
}
