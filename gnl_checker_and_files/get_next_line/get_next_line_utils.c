/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:40:44 by dsy               #+#    #+#             */
/*   Updated: 2019/11/01 17:18:10 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(char *s)
{
	char	*newstr;
	int	i;
	int 	j;	

	i = 0;
	j = ft_strlen(s);
	if (!s)
		return (NULL);
	if (!(newstr = malloc(sizeof(char) * j)))
		return (NULL);
	while (i < j)
	{
		newstr[i] = s[i];
		i++;
	}
	return (newstr);
}

int	check_line_buffer(char **line_buffer, char **line)
{
	int i;

	i = 0;
	while ((*line_buffer)[i] != '\n')
	{
		if ((*line_buffer)[i] == '\0')
			return (0);
		i++;
	}
	(*line_buffer)[i] = '\0';
	*line = ft_strdup(*line_buffer);
	*line_buffer = ft_strdup((*line_buffer) + i + 1);
	return (1);
}

char	*ft_strjoin(char  *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !(newstr = (char*)malloc(sizeof(char) *
					ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

int	gnl_read(int fd, char *file, char **line_buffer, char **line)
{
	int		bytes;
	int		i;

	i = 0;
	while ((bytes = read(fd, file, BUFFER_SIZE))> 0)
	{
		file[bytes] = '\0';
		if (*line_buffer)
			*line_buffer = ft_strjoin(*line_buffer, file);
		else
			*line_buffer = ft_strdup(file);
		if (!check_line_buffer(line_buffer, line))
		{
			i = 1;
			break ;
		}
	}
	if (i)
		return (1);
	else
		return (bytes);
}
