/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 02:36:43 by dsy               #+#    #+#             */
/*   Updated: 2019/11/16 02:37:05 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			setup_line(char **line_stack, char **line, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (line_stack[fd][i] != '\n' && line_stack[fd][i] != '\0')
		i++;
	if (line_stack[fd][i] == '\n')
	{
		if (!(*line = ft_substr(line_stack[fd], 0, i)))
			return (-1);
		if (!(tmp = ft_strdup(line_stack[fd] + i + 1)))
			return (-1);
		free(line_stack[fd]);
		line_stack[fd] = tmp;
	}
	else
	{
		if (!(*line = ft_strdup(line_stack[fd])))
			return (-1);
		free(line_stack[fd]);
	}
	return (1);
}

int			gnl_read(int fd, char **line_stack, int ret)
{
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	while ((ret = read(fd, &buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(line_stack[fd], buf)))
			return (-1);
		free(line_stack[fd]);
		line_stack[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	static char	*line_stack[MAX_FD];
	int			ret;
	int			i;

	ret = 1;
	i = 0;
	if ((read(fd, line_stack[fd], 0) < 0) || line == NULL 
			|| fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (-1);
	while (line_stack[fd][i] != '\n' && line_stack[fd][i] != '\0')
		i++;
	if (line_stack[fd][i] == '\n')
		return (setup_line(line_stack, line, fd));
	else
	{
		ret = gnl_read(fd, line_stack, ret);
		if (ret < 0)
			return (-1);
		if (ret == 0 && (line_stack[fd][0] == '\0'))
			return (0);
	}
	return (setup_line(line_stack, line, fd));
}
