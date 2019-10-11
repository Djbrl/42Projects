/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:04:44 by dsy               #+#    #+#             */
/*   Updated: 2019/10/11 15:25:00 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy_dup(void *str1, const void *str2, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*src;

	i = 0;
	dest = str1;
	src = str2;
	while (i < (unsigned char)n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dest;
	s = src;
	while (s[i] != c && i < n)
		i++;
	d = ft_memcpy_dup(d, s, i + 1);
	if (s[i] == c)
		return (d + i + 1);
	else
		return (NULL);
}
