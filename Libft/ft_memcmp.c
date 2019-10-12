/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:04:46 by dsy               #+#    #+#             */
/*   Updated: 2019/10/12 18:12:51 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s, const void *s2, size_t n)
{
	size_t		i;
	const char	*dest;
	const char	*src;

	i = 0;
	dest = s;
	src = s2;
	if (dest == src)
		return (0);
	while (i < (unsigned char)n)
	{
		if (dest[i] < src[i])
			return (-1);
		else if (dest[i] > src[i])
			return (1);
		else
			i++;
	}
	return (0);
}
