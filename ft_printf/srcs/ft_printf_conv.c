/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:47:54 by dsy               #+#    #+#             */
/*   Updated: 2020/01/03 20:44:12 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		s_conversion(char *s, va_list params, char arg_type, t_field field)
{
	char 	*conv_arg;
	int	len;
	char 	c;

	c = 0;
	len = 0;
	if (arg_type == 's')
	{
		conv_arg = (char*)va_arg(params, char*);
		len = ft_strlen(conv_arg);
		print_balise_str(s, conv_arg, field, len);
	}
	else
	{
		c = (char)va_arg(params, int);
		print_balise_char(c, field);
	}
	return (1);
}

int		p_conversion(va_list params, char arg_type, t_field field)
{
	void *p;

	p = va_arg(params, void*);
	print_balise_add((unsigned long)p, arg_type, field);
	return (1);
}

int		i_conversion(va_list params, char arg_type, t_field field)
{
	int		nb;
	int		len;

	if (arg_type == 'i' || arg_type == 'd')
		nb = (int)va_arg(params, int);
	else
		nb = (unsigned int)va_arg(params, int);
	len = count_digit(nb, arg_type);
	print_balise_nb(nb, arg_type, field, len);
	return (1);
}

int		x_conversion(va_list params, char arg_type, t_field field)
{
	int	nb;
	int	len;

	nb = (int)va_arg(params, int);
	len = count_digit(nb, arg_type);
	if (len >= field.precision)
		field.precision = 0;
	print_balise_nb(nb, arg_type, field, len);
	return (1);
}
