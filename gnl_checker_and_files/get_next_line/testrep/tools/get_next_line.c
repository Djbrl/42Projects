/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:09:29 by dsy               #+#    #+#             */
/*   Updated: 2019/11/08 16:48:24 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		setup_next_line(char **save, char **line)
{
	int	i;

	i = 0;
	while ((*save)[i] != '\n')
	{
		if ((*save)[i] == '\0')
			return (0);
		i++;
	}
	(*save)[i] = '\0';
	*line = ft_strdup(*save);
	ft_bzero(*save, i);
	*save = ft_strdup((*save) + i + 1);
	return (1);
}

int		gnl_read(int fd, char *this_line, char **save, char **line)
{
	int	bytes;

	if ((bytes = read(fd, this_line, BUFFER_SIZE)) > 0)
	{
		this_line[bytes] = '\0';
		if (*save)
			*save = ft_strjoin(*save, this_line);
		else
			*save = ft_strdup(this_line);
		setup_next_line(save, line);
	}
	else
		return (0);
	return (bytes < 0 ? -bytes : bytes);
}

int		gnl_clean_line(char **line)
{
	*line = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*save[MAX_FD];
	char			*this_line;
	int				ret;

	if (!line || (fd < 0 || fd >= MAX_FD) || (read(fd, save[fd], 0) < 0) ||
	BUFFER_SIZE < 1 || !(this_line = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (save[fd] && setup_next_line(&save[fd], line))
	{
		free(this_line);
		return (1);
	}
	ft_bzero(this_line, (size_t)BUFFER_SIZE);
	ret = gnl_read(fd, this_line, &save[fd], line);
	free(this_line);
	if (ret != 0 || save[fd] == NULL || save[fd][0] == '\0')
	{
		if (!ret)
			return (gnl_clean_line(line));
		return (1);
	}
	*line = save[fd];
	save[fd] = NULL;
	return (1);
}
