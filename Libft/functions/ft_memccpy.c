/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:04:44 by dsy               #+#    #+#             */
/*   Updated: 2019/10/09 15:00:52 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t i;

	i = 0;
	char *ret = str1;
	const char *s = str2;
	while (i < (unsigned char)n)
	{
		ret[i] = s[i];
		i++;
	}
	return (ret);
}

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;
	char *d1;
	const char *s1;

	i = 0;
	d1 = dest;
	s1 = src;
	while (s1[i] != c && i < n)
		i++;
	d1 = ft_memcpy(d1, s1, i+1);
	if (s1[i] == c)
		return (d1 + i + 1);
	else
		return (NULL);
}
