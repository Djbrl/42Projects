/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:09:29 by dsy               #+#    #+#             */
/*   Updated: 2019/11/06 21:27:34 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		setup_next_line(char **line_stack, char **line)
{
	int	i;

	i = 0;
	while ((*line_stack)[i] != '\n')
	{
		if ((*line_stack)[i] == '\0')
		{
			write(1, "\noops\n", 6);
			return (0);
		}
		i++;
	}
	(*line_stack)[i] = '\0';
	*line = ft_strdup(*line_stack);
	*line_stack = ft_strdup((*line_stack) + i + 1);
	return (1);
}

int		gnl_read(int fd, char *current_line, char **line_stack, char **line)
{
	int	bytes;

	if ((bytes = read(fd, current_line, BUFFER_SIZE)) > 0)
	{
		current_line[bytes] = '\0';
		if (*line_stack)
			*line_stack = ft_strjoin(*line_stack, current_line);
		else
			*line_stack = ft_strdup(current_line);
		setup_next_line(line_stack, line);
	}
	else
		return (0);
	return (bytes);
}

int		get_next_line(int fd, char **line)
{
	static char		*line_stack[MAX_FD];
	char			*current_line;
	int				ret;

	if (!line || (fd < 0 || fd >= MAX_FD) || (read(fd, line_stack[fd], 0) < 0)
			|| !(current_line = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (line_stack[fd] && setup_next_line(&line_stack[fd], line))
	{
		write(1, "\no\n", 3);
		free(current_line);
		return (1);
	}
	ft_bzero(current_line, (size_t)BUFFER_SIZE);
	ret = gnl_read(fd, current_line, &line_stack[fd], line);
	free(current_line);
	if (ret != 0 || line_stack[fd] == NULL || line_stack[fd][0] == '\0')
	{
		if (!ret && *line)
		{
		write(1, "\np1\n", 3);
			*line = NULL;
			return (0);
		}
		printf("we're in gnl() and ret is %i\n", ret);
		printf("line is currently: \"%s\"\nlinestack is currently : \"%s\"\n\n", *line, line_stack[fd]);
		write(1, "\np2\n", 3);
		return (1);
	}
	*line = line_stack[fd];
	line_stack[fd] = NULL;
	write(1, "d\n", 2);
	return (1);
}
