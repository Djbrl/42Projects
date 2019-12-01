/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:47:54 by dsy               #+#    #+#             */
/*   Updated: 2019/12/01 17:37:39 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
/*
int c_conversion(va_list params, t_convs conv_arg)
{
	conv_arg.c = (char)va_arg(params, char);
	write(1, &conv_arg.c, 1);
	return (0);
}
*/
int s_conversion(va_list params, char arg_type)
{
	char *conv_arg;
	char c;

	c = 0;
	if (arg_type == 's')
	{
		conv_arg = (char*)va_arg(params, char*);
		ft_putstr(conv_arg);
	}
	else
	{
		c = (char)va_arg(params, int);
		write(1, &c, 1);
	}
	return (1);
}

//int p_conversion(va_list params);
/*int d_conversion(va_list params, t_convs conv_arg)
{
	conv_arg.d = (int)va_arg(params, int);
	write(1, &conv_arg.d, 1);
	return (0);
}
*/
int i_conversion(va_list params, char arg_type)
{
	int conv_arg;
	char c;

	c = 0;
	if (arg_type == 'i' || arg_type == 'd')
		conv_arg = (int)va_arg(params, int);
	else
		conv_arg = (unsigned int)va_arg(params, int);
	ft_putnbr(conv_arg);
	return (1);
}
//int u_conversion(va_list params);
//int x_conversion(va_list params);
