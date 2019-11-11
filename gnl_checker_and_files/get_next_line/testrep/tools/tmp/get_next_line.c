/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:09:29 by dsy               #+#    #+#             */
/*   Updated: 2019/11/11 18:18:29 by dsy              ###   ########.fr       */
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

int		gnl_read(int fd, char *file_content, char **line_stack, char **line)
{
	int	bytes;

	if ((bytes = read(fd, file_content, BUFFER_SIZE + 1)) > 0)
	{
		file_content[bytes] = '\0';
		if (*line_stack)
			*line_stack = ft_strjoin(*line_stack, file_content);
		else
			*line_stack = ft_strdup(file_content);
		setup_next_line(line_stack, line);
	}
	else
		return (0);
	return (bytes);
}

int		get_next_line(int fd, char **line)
{
	static char		*line_stack;
	char			*file_content;
	int				ret;

	//---------------
	if (!line || (fd < 0 || fd > MAX_FD) || BUFFER_SIZE < 1 ||
			!(file_content = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	ft_bzero(file_content, (size_t)BUFFER_SIZE);
	if (line_stack && setup_next_line(&line_stack, line))
	{
		free(file_content);
		return (1);
	}
	//----------------
	ret = gnl_read(fd, file_content, &line_stack, line);
	if (ret == -1)
	{
		free(file_content);
		return (ret);
	}
	printf("line : \x1b[32m%s\x1b[0m\nline stack :\x1b[31m %s\x1b[0m\nreturn of read : %i\n\n", *line, line_stack, ret);
	free(file_content);
	if (!line_stack || line_stack[0] == '\0')
		*line = NULL;
	if (ret == 0 && line_stack && !setup_next_line(&line_stack, line))
		*line = ft_strdup(line_stack);
	printf("last line read : %s\n", *line);
	return (ret == 0 ? 0 : 1);
}
