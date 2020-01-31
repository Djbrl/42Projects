/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:12:23 by dsy               #+#    #+#             */
/*   Updated: 2020/01/20 14:12:23 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_balise_pct(t_field f)
{
	int	width;

	width = f.width - 1;
	if (f.flags[1] != '-' && f.flags[0] != '0')
		while (width > 0 && width--)
			ft_putchar(' ');
	if (f.flags[1] == '-')
	{
		ft_putchar('%');
		while (width > 0 && width--)
			ft_putchar(' ');
		return ;
	}
	if (f.flags[0] == '0')
		while (width > 0 && width--)
			ft_putchar('0');
	ft_putchar('%');
}
