/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:47:54 by dsy               #+#    #+#             */
/*   Updated: 2019/11/30 18:17:59 by dsy              ###   ########.fr       */
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
int s_conversion(va_list params)
{
	int i;
	char *conv_arg;

	i = 0;
	conv_arg = (char*)va_arg(params, char*);
	printf("%s\n", conv_arg);
	while (conv_arg[i])
		write(1, &(conv_arg[i++]), 1);
	return (0);
}

//int p_conversion(va_list params);
/*int d_conversion(va_list params, t_convs conv_arg)
{
	conv_arg.d = (int)va_arg(params, int);
	write(1, &conv_arg.d, 1);
	return (0);
}
*/
int i_conversion(va_list params)
{
	int conv_arg;
	conv_arg = (int)va_arg(params, int);
	printf("%i\n", conv_arg);
	write(1, &conv_arg, 1);
	return (0);
}
//int u_conversion(va_list params);
//int x_conversion(va_list params);
