/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:04:44 by dsy               #+#    #+#             */
/*   Updated: 2019/10/12 18:10:35 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dest;
	s = src;
	if (n == 0)
		return ((void*)s);
	while (s[i] != c && i < n)
		i++;
	d = ft_memcpy(d, s, i + 1);
	if (s[i] == c)
		return (d + i + 1);
	else
		return (NULL);
}
