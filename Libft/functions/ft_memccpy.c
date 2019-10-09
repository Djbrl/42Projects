/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:04:44 by dsy               #+#    #+#             */
/*   Updated: 2019/10/09 16:38:34 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t i;

	i = 0;
	char *dest = str1;
	const char *src = str2;
	while (i < (unsigned char)n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;
	char *d1;
	const char *s1;

	i = 0;
	d = dest;
	s = src;
	while (s[i] != c && i < n)
		i++;
	d = ft_memcpy(d, s, i+1);
	if (s[i] == c)
		return (d + i + 1);
	else
		return (NULL);
}
