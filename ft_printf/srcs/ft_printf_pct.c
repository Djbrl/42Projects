/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:28:39 by othabchi          #+#    #+#             */
/*   Updated: 2020/01/11 18:03:22 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_balise_pct(t_field f)
{
	int	width;

	width = f.width - 1;
	if (f.flags[1] != '-' && (f.flags[0] != '0'))
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