/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:09:29 by dsy               #+#    #+#             */
/*   Updated: 2019/11/10 18:50:25 by dsy              ###   ########.fr       */
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
			return (0);
		i++;
	}
	(*line_stack)[i] = '\0';
	*line = ft_strdup(*line_stack);
	ft_bzero(*line_stack, i);
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
	static char		*line_stack;
	char			*current_line;
	int				ret;

	if (!line || !(current_line = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (line_stack && setup_next_line(&line_stack, line))
	{
		free(current_line);
		return (1);
	}
	ft_bzero(current_line, (size_t)BUFFER_SIZE);
	ret = gnl_read(fd, current_line, &line_stack, line);
	printf("line : \x1b[32m%s\x1b[0m\nline stack :\x1b[32m %s\x1b[0m\nreturn of read : %i\n", *line, line_stack, ret);
	free(current_line);
	return (ret == 0 ? 0 : 1);
}
