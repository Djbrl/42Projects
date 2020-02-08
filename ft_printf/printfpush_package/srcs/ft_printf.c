/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:04:48 by dsy               #+#    #+#             */
/*   Updated: 2020/02/08 22:19:11 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			g_ret = 0;

int			pars(char *s)
{
	int stock;
	int	i;

	i = 0;
	stock = 0;
	while (s[i])
	{
		while (s[stock] && s[stock] != '%')
			stock++;
		if (s[stock] == '%')
		{
			i = stock + 1;
			while (s[i] && !is_conversion(s[i]))
				i++;
			if ((s[i] == '\0') || ((s[i] == 'x' || s[i] == 'X') &&
			pars_hexa(&s[stock]) != 1) || ((s[i] == 'd' || s[i] == 'i' ||
			s[i] == 'u' || s[i] == '%') && (pars_decimal(&s[stock]) != 1)) ||
			((s[i] == 'c' || s[i] == 'p') && (pars_char_n_add(&s[stock]) != 1))
			|| (s[i] == 's' && pars_str(&s[stock]) != 1))
				return (0);
		}
		i++;
		stock = i;
	}
	return (1);
}

void		which_arg(char *str, va_list params)
{
	int		i;
	t_field	field;

	i = 0;
	field = is_balise(str, params);
	while (str[i] && !is_conversion(str[i]))
		i++;
	if (str[i] == 'c' || str[i] == 's')
		s_conversion(str, params, str[i], field);
	if (str[i] == 'i' || str[i] == 'd' || str[i] == 'u' ||
		str[i] == 'x' || str[i] == 'X')
		nb_conversion(params, str, str[i], field);
	if (str[i] == 'p')
		p_conversion(params, str[i], field);
	if (str[i] == '%')
		print_balise_pct(field);
}

static int	print_text(const char *str, va_list params)
{
	int i;

	i = 0;
	if (pars((char *)str) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			which_arg((char *)&str[i], params);
			while (str[i] && !is_conversion(str[i]))
				i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list	params;
	int		stock;

	va_start(params, format);
	if (format == NULL)
		return (-1);
	if (!(print_text(format, params)))
		return (-1);
	va_end(params);
	stock = g_ret;
	g_ret = 0;
	return (stock);
}
