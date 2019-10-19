/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:48:49 by dsy               #+#    #+#             */
/*   Updated: 2019/10/19 15:15:15 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		str_chr(char c, char charset)
{
	if (charset == c)
		return (1);
	return (0);
}

int		count_word(char *str, char charset)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str_chr(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !str_chr(str[i], charset))
			i++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		word_length(char *str, char charset)
{
	int		i;

	i = 0;
	while (str[i] && !str_chr(str[i], charset))
		i++;
	return (i);
}

char	**ft_split(char *str, char charset)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * count_word(str, charset) + 1)))
		return (0);
	while (str[i])
	{
		if (!str_chr(str[i], charset))
		{
			if (!(tab[j] = (char*)malloc(sizeof(char) *
							word_length(str + i, charset) + 1)))
				return (0);
			tab[j] = ft_strncpy(tab[j], &str[i], word_length(&str[i], charset));
			i += word_length(&str[i], charset);
			j++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}
/*
   size_t	count_words(char const *s, char c)
   {
   size_t i;
   size_t j;
   size_t flag;

   i = 0;
   j = 0;
   flag = 0;
   while (s[i])
   {
   if (s[i] != c && flag == 0)
   {
   flag = 1;
   j++;
   }
   if (s[i] == c)
   flag = 0;
   i++;
   }
   return (j);
   }

   int find_next_c(char const *s, char c, int n)
   {
   int i;

   i = n + 1;
   while (s[i])
   {
   if (s[i] == c)
   return (i);
   i++;
   }
   return (i);
   }

   char	**ft_split(char const *s, char c)
   {
   char **str;
   size_t words;
   size_t i;
   size_t j;

   i = 0;
   j = 0;
   words = count_words(s, c);
   if (!words)
   {
   if (!(str = malloc(sizeof(char*))))
   return (NULL);
   str[0] = 0;
   return (str);
   }
   if (!(str = malloc(sizeof(char*) * words + 1)))
   return (NULL);
   while (i < words)
   {
   while (s[j])
   {
   if (s[j] == c && i > 0)
   str[i] = ft_strndup(s + j, find_next_c(s, c, j));
   str[i] = ft_strndup(s, find_next_c(s, c, -1));
   j++;
   }
   i++;
   }
   str[i] = 0;
   return (str);
   }*/
