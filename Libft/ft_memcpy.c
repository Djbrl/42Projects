/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:17:35 by dsy               #+#    #+#             */
/*   Updated: 2019/10/12 18:13:25 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*src;

	i = 0;
	dest = str1;
	src = str2;
	if (dest == NULL & src == NULL)
		return (NULL);
	while (i < (unsigned char)n)
	{
		dest[i] = (unsigned char)src[i];
		i++;
	}
	dest[i - 1] = (unsigned char)src[i - 1];
	return (dest);
}
