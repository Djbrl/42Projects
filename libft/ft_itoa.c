/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:48:32 by dsy               #+#    #+#             */
/*   Updated: 2019/10/20 15:38:12 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*intmin(void)
{
	char *str;

	str = ft_strdup("-2147483648");
	return (str);
}

char	*ft_itoa(int n)
{
	char	buff[22];
	char	*str;
	int		i;
	int		ntmp;

	i = 0;
	ntmp = n;
	if (n < 0)
		ntmp = -n;
	while (ntmp > 0)
	{
		buff[i++] = (ntmp % 10) + 48;
		ntmp = ntmp / 10;
	}
	if (n < 0)
		buff[i++] = '-';
	str = ft_memalloc((size_t)i + 1);
	if (n == -2147483648)
		return (intmin());
	else if (n == 0 && str)
		str[0] = '0';
	while (--i >= 0 && str)
		str[ntmp++] = buff[i];
	return (str);
}
