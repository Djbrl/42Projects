/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:18:35 by dsy               #+#    #+#             */
/*   Updated: 2019/10/20 16:19:49 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char *s;
	unsigned char		temp[len];

	d = dst;
	s = src;
	i = 0;
	while (i++ < len)
		temp[i] = s[i];
	i = 0;
	while (i++ < len)
		d[i] = temp[i];
	return (d);
}
