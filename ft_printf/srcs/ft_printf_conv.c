/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:47:54 by dsy               #+#    #+#             */
/*   Updated: 2019/12/04 06:23:49 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		s_conversion(va_list params, char arg_type, t_field field)
{
	char *conv_arg;
	char c;

	c = 0;
	if (arg_type == 's')
	{
		conv_arg = (char*)va_arg(params, char*);
		print_balise_str(conv_arg, field);
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
	int		conv_arg;

	if (arg_type == 'i' || arg_type == 'd')
		conv_arg = (int)va_arg(params, int);
	else
		conv_arg = (unsigned int)va_arg(params, int);
	print_balise_nb(conv_arg, field);
	return (1);
}

int		x_conversion(va_list params, char arg_type, t_field field)
{
	int conv_arg;

	conv_arg = (int)va_arg(params, int);
	print_balise_hexa(conv_arg, arg_type, field);
	return (1);
}
