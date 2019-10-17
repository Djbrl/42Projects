/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:32:43 by dsy               #+#    #+#             */
/*   Updated: 2019/10/17 18:23:03 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char *newstr;

	i = 0;
	if (!(newstr = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (start > ft_strlen(s))
		return (0);
	while (i < len && s[start])
	{
		newstr[i] = s[start++];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
