/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:52:14 by dsy               #+#    #+#             */
/*   Updated: 2019/10/20 16:16:35 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	size_t	i;

	i = 0;
	map = NULL;
	if (s && f)
	{
		if (!(map = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1)))
			return (NULL);
		while (i < ft_strlen((char *)s))
		{
			map[i] = f(i, s[i]);
			i++;
		}
		map[i] = '\0';
	}
	return (map);
}
