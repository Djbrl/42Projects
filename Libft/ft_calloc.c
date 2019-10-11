/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:37:21 by dsy               #+#    #+#             */
/*   Updated: 2019/10/11 15:01:44 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	size_t i;
	char *p;

	i = 0;
	p = (char*)malloc(elementCount * sizeof(elementSize));
	if (!p)
		return (NULL);
	while (i < elementCount)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
