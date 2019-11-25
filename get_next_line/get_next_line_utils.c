/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:18:08 by dsy               #+#    #+#             */
/*   Updated: 2019/11/23 15:28:19 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strdup(const char *s1)
{
	int		len;
	char	*res;

	len = 0;
	while (s1[len])
		len++;
	res = malloc(len * sizeof(char) + 1);
	if (res == 0)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		res[len] = s1[len];
		len++;
	}
	res[len] = '\0';
	return (res);
}

size_t		ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char		*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (*str == '\0' && (char)c != '\0')
			return (0);
		str++;
	}
	return ((char *)str);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		cpy;
	size_t	lalen;

	if (s == NULL || start < 0)
		return (NULL);
	lalen = ft_strlen((char *)s);
	if (start >= lalen)
		len = 0;
	else
		len = lalen - start < len ? lalen - start : len;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == 0)
		return (NULL);
	cpy = 0;
	while (len)
	{
		res[cpy] = s[start];
		cpy++;
		start++;
		len--;
	}
	res[cpy] = '\0';
	return (res);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	s1_len = s1 ? ft_strlen((char *)s1) : 0;
	s2_len = s2 ? ft_strlen((char *)s2) : 0;
	if (!(result = malloc(sizeof(char) *
	(s1_len + s2_len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}
