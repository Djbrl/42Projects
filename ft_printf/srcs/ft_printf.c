/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:26:52 by dsy               #+#    #+#             */
/*   Updated: 2019/11/28 02:25:28 by dsy              ###   ########.fr       */
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

static void	print_text(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_conversion(str[i + 1]))
			if (str[i + 2])
				i = i + 2;
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		write(1, &str[i], 1);
		i++;
	}
}

int			ft_printf(const char *format, ...)
{
	int i;

	i = 0;
	if (format == NULL)
		return (0);
	print_text(format);
	return (0);
}
