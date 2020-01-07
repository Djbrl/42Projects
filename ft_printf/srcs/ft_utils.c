/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:40:25 by dsy               #+#    #+#             */
/*   Updated: 2020/01/03 23:47:13 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	count_digit(int nb, char c)
{
	int	count;
	int	div;

	count = 0;
	div = (c == 'd' || c == 'i' || c == 'u') ? 10 : 16;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / div;
		count++;
	}
	return (count);
}

int	check_precision(char *s, int check)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '.')
		i++;
	if (s[i] == '.' && (is_conversion(s[i + 1]) || s[i + 1] == '0'))
		check = 1;
	return (check);
}

int	is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'd' || c == 'u'
			|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	flags(char c)
{
	if (c == '%' || c == '+' || c == '-' || c == ' ' || c == '0')
		return (1);
	return (0);
}
