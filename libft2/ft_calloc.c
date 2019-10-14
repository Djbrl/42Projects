/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:37:21 by dsy               #+#    #+#             */
/*   Updated: 2019/10/12 18:15:17 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementcount, size_t elementsize)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char*)malloc(elementcount * sizeof(elementsize));
	if (!p)
		return (NULL);
	while (i < elementcount)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
