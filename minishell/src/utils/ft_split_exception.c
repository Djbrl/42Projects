/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 00:19:24 by dsy               #+#    #+#             */
/*   Updated: 2022/04/05 16:22:11 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int	count_words(char *s, char c, char exception)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && ((s[i + 1] == c && (s[i + 2] && s[i + 2] != exception))
			|| s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	words_len(char *s, char c, char exception)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while ((s[i] != c || (s[i + 1] && s[i + 1] == exception))
			&& s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void	*leak(char **splitted, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (NULL);
}

static char	**fill(char *s, int words, char c, char **splitted, char exception)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < words)
	{
		while (*s == c && (*s + 1 && *s + 1 != exception))
			s++;
		len = words_len(s, c, exception);
		splitted[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!splitted[i])
			return (leak(splitted, i));
		j = 0;
		while (j < len)
			splitted[i][j++] = *s++;
		splitted[i][j] = '\0';
	}
	splitted[i] = NULL;
	return (splitted);
}

char	**ft_split_exception(char *s, char c, char exception)
{
	char	**splitted;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c, exception);
	splitted = (char **)malloc(sizeof(char *) * (words + 1));
	if (!splitted)
		return (NULL);
	splitted = fill(s, words, c, splitted, exception);
	return (splitted);
}
