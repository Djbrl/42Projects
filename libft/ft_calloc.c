/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:37:21 by dsy               #+#    #+#             */
/*   Updated: 2019/10/23 16:58:55 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*stock;
	int		i;

	i = 0;
	if (!(stock = (char*)malloc(count * size)))
		return (NULL);
	ft_bzero(stock, count);
	return (stock);
}
