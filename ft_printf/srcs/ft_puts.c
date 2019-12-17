/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:01:54 by othabchi          #+#    #+#             */
/*   Updated: 2019/12/17 23:14:02 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putcharplus(char c)
{
	write(1, &c, 1);
	g_ret++;
}

void	ft_putstrplus(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putcharplus(str[i]);
		i++;
	}
}

void	ft_putnbrplus(int n)
{
	long nb;

	nb = (long)n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putcharplus('-');
	}
	if (nb < 10)
	{
		ft_putcharplus(nb + '0');
		return ;
	}
	ft_putnbrplus(nb / 10);
	ft_putcharplus((nb % 10) + '0');
	return ;
}
