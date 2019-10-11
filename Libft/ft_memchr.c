/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:11:52 by dsy               #+#    #+#             */
/*   Updated: 2019/10/11 15:20:10 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*src;

	i = 0;
	src = s;
	while (i < (unsigned char)n)
	{
		if (src[i] == c)
			return ((void*)src + i);
		else
			i++;
	}
	return (NULL);
}
