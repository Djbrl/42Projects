/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend_isbalise.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 04:55:17 by dsy               #+#    #+#             */
/*   Updated: 2020/02/09 17:37:32 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		extend_check_star(int c, t_field field)
{
	if (c < 0 && field.width > 0)
		field.flags[1] = '/';
}

t_field		check_star(char *str, va_list args)
{
	int		i;
	int		c;
	t_field	field;

	i = 0;
	field.width = 0;
	field.precision = 0;
	field.flags[0] = '/';
	field.flags[1] = '/';
	while (str[i] && !is_conversion(str[i]))
	{
		if (str[i] == '*')
		{
			c = (int)va_arg(args, int);
			if (c < 0)
				field.flags[1] = '-';
			extend_check_star(c, field);
			if (str[i - 1] && str[i - 1] == '.')
				field.precision = c;
			else
				field.width = (c < 0) ? -c : c;
		}
		i++;
	}
	return (field);
}
