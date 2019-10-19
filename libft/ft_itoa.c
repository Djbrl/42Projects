/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:48:32 by dsy               #+#    #+#             */
/*   Updated: 2019/10/19 17:47:32 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_nb_size(int nb)
{
	int	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (size + 1);
}

char	*ft_itoa(int nbr)
{
	char			*str;
	int	nb;
	int	index;
	int	size;

	if (nbr < 0)
		nb = (nbr * -1);
	else
		nb = nbr;
	size = get_nb_size(nb);
	index = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1 + (nbr < 0 ? 1 : 0)))))
		return (0);
	if (nbr < 0 && (str[index] = '-'))
		size++;
	index = size - 1;
	while (nb >= 10)
	{
		str[index--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	str[index] = (char)(nb % 10 + 48);
	str[size] = '\0';
	return (str);
}
