/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:27:17 by dsy               #+#    #+#             */
/*   Updated: 2019/10/18 18:16:08 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	isinset(char c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

size_t	findend(char const *s1, char const *set)
{
	size_t i;
	
	i = ft_strlen(s1) - 1;
	while(isinset(s1[i], set) && i >= 0)
		i--;
	if (i == 0)
		return (0);
	else
		return (i);
}

size_t	findstart(char const *s1, char const *set)
{
	size_t i;

	i = 0;
	while (isinset(s1[i], set))
		i++;
	if (s1[i] == '\0')
		return (0);
	else
		return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t i;
	size_t start;
	size_t end;
	char *newstr;

	i = 0;
	end = findend(s1, set);
	start = findstart(s1, set);
	if (!(newstr = (char*)malloc(sizeof(char) * (end - start  + 1) + 1)))
		return (NULL);
	if (s1 == set || (end == 0 && start == 0))
	{
		*newstr = '\0';
		return (newstr);
	}
	while (start <= end)
	{
		newstr[i] = s1[start];
		start++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
