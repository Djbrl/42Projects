/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:10:51 by dsy               #+#    #+#             */
/*   Updated: 2020/07/17 02:37:36 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			cut_stack(char **s, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	if ((*s)[i] == '\n')
	{
		if (!(*line = ft_substr(*s, 0, i)))
			return (-1);
		if (!(tmp = ft_strdup(*s + i + 1)))
			return (-1);
		free(*s);
		*s = tmp;
	}
	else
	{
		if (!(*line = ft_strdup(*s)))
			return (-1);
		free(*s);
	}
	return (1);
}

int			gnl_read(int fd, char **s, int ret)
{
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	while ((ret = read(fd, &buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(*s, buff)))
			return (-1);
		free(*s);
		*s = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ret);
}

int			empty_last_stack(char **line, char *stack)
{
	*line = ft_strdup(stack);
	free(stack);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char *s;
	int			ret;
	int			i;

	ret = 1;
	i = 0;
	if (line == NULL || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!s)
		if (!(s = malloc(1)))
			return (-1);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		return (cut_stack(&s, line));
	else
	{
		ret = gnl_read(fd, &s, ret);
		if (ret < 0)
			return (-1);
		if (ret == 0 && (s[0] == '\0' || s[i] == '\0'))
			return (empty_last_stack(line, s));
	}
	return (cut_stack(&s, line));
}
