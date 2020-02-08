/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:04:57 by dsy               #+#    #+#             */
/*   Updated: 2020/02/08 22:25:39 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	s_conversion(char *s, va_list params, char arg_type, t_field field)
{
	char	*conv_arg;
	int		len;
	char	c;

	conv_arg = NULL;
	c = 0;
	len = 0;
	if (arg_type == 's')
	{
		conv_arg = (char*)va_arg(params, char*);
		len = (!conv_arg) ? 6 : ft_strlen(conv_arg);
		print_balise_str(s, conv_arg, field, len);
	}
	else
	{
		c = (char)va_arg(params, int);
		print_balise_char(c, field);
	}
}

void	p_conversion(va_list params, char arg_type, t_field field)
{
	void *p;

	p = va_arg(params, void*);
	print_balise_add((unsigned long)p, arg_type, field);
}

void	nb_conversion(va_list params, char *str, char arg_type, t_field field)
{
	long	nb;
	int		len;
	int		check;

	check = 0;
	check = check_precision(str, check);
	if (arg_type == 'i' || arg_type == 'd' || arg_type == 'x'
		|| arg_type == 'X')
		nb = (int)va_arg(params, int);
	else
		nb = (unsigned int)va_arg(params, int);
	len = count_digit(nb, arg_type);
	if (check != 1 && ((arg_type == 'x' || arg_type == 'X') && nb < 0))
		print_balise_nb(4294967296 + nb, arg_type, field, len);
	else if (check != 1 || nb != 0)
		print_balise_nb(nb, arg_type, field, len);
	else
		while (field.width && field.width--)
			ft_putchar(' ');
}
