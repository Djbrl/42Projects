/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:17:35 by dsy               #+#    #+#             */
/*   Updated: 2019/10/09 14:57:27 by dsy              ###   ########.fr       */
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
