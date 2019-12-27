/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:26:52 by dsy               #+#    #+#             */
/*   Updated: 2019/12/27 11:17:01 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
//add function that checks combinaison of flags
//add function that prints that combinaison before/after the result

int			is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'd' || c == 'u'
			|| c == 'x' || c == 'X')
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

static int	print_text(const char *str, va_list params)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		else if (str[i] == '%' && is_conversion(str[i + 1]))
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

	va_start(params, format);
	i = 0;
	if (format == NULL)
		return (-1);
	if (!(print_text(format, params)))
		return (-1);
	va_end(params);
	return (0);
}
