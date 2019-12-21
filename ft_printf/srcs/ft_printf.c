/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:26:52 by dsy               #+#    #+#             */
/*   Updated: 2019/12/20 08:35:24 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			g_ret = 0;

int			pars(char *str)
{
	int stock;
	int	i;

	i = 0;
	stock = 0;
	while (str[i])
	{
		while (str[stock] && str[stock] != '%')
			stock++;
		if (str[stock] == '%')
		{
			i = stock;
			while (str[i] && !is_conversion(str[i]))
				i++;
			if ((str[i] == '\0') || ((str[i] == 'x' || str[i] ==
                         'X') && pars_hexa(&str[stock]) != 1) || ((str[i] ==
                         'd' || str[i] == 'i' || str[i] == 'u') && 
			 (pars_decimal(&str[stock]) != 1)) || ((str[i] == 'c'
			  || str[i] == 'p') && (pars_char_n_add(&str[stock])
			!= 1)) || (str[i] == 's' && pars_str(&str[stock]) != 1))
                                return (0);
		}
		i++;
		stock = i;
	}
	return (1);
}
static int	which_arg(char *str, va_list params)
{
	int	i;
	t_field	field;

	i = 0;
	field = is_balise(str, params);
	if (field.error == 1)
		return (0);
	while(str[i] && !is_conversion(str[i]))
			i++;
	if (str[i] == 'c' || str[i] == 's')
		if (!(s_conversion(params, str[i], field)))
			return (0);
	if (str[i] == 'i' || str[i] == 'd' || str[i] == 'u')
		if (!(i_conversion(params, str[i], field)))
			return (0);
	if (str[i] == 'p')
		if (!(p_conversion(params, str[i], field)))
			return (0);
	if (str[i] == 'x' || str[i] == 'X')
		if (!(x_conversion(params, str[i], field)))
			return (0);
	return (1);
}

static int	print_text(const char *str, va_list params)
{
	int 	i;
	i = 0;
	if (pars((char *)str) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		else if (str[i] == '%' && str[i + 1] != '%')
		{
			if (!(which_arg((char *)&str[i], params)))
				return (0);
			i++;
			while (str[i] && !is_conversion(str[i]))
				i++;
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list params;

	va_start(params, format);
	if (format == NULL)
		return (-1);
	if (!(print_text(format, params)))
		return (-1);
	va_end(params);
	return (g_ret);
}
