/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:32:43 by othabchi          #+#    #+#             */
/*   Updated: 2020/01/12 20:20:38 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*newstr;

	i = 0;
	if (!s)
	{
		if (!(newstr = malloc(sizeof(char))))
			return (NULL);
		newstr[0] = 0;
		return (newstr);
	}
	if (!(newstr = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (start > ft_strlen(s))
	{
		newstr[0] = '\0';
		return (newstr);
	}
	while (i < len && s[start])
	{
		newstr[i] = s[start++];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
