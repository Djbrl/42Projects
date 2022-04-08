/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:04:03 by dsy               #+#    #+#             */
/*   Updated: 2020/02/09 17:48:33 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_balise_nb(long nb, char c)
{
	(c == 'x' || c == 'X') ? ft_putnbr_x(nb, c) : ft_putnbr(nb);
}

void	print_balise_str(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	print_balise_char(char c)
{
	ft_putchar(c);
}

void	print_balise_add(unsigned long p, char c)
{
	ft_putnbr_x(p, c);
}
