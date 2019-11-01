/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:06:15 by dsy               #+#    #+#             */
/*   Updated: 2019/11/01 18:38:34 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*line_buffer[256];
	char		*file;
	int 		rd;
	int 		i;

	if (!line || (fd < 0 || fd > 256) \
			|| !(file = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);	
	if (line_buffer[fd])
		if (check_line_buffer(line_buffer, line))
			return (1);
	i = 0;
	file = calloc(BUFFER_SIZE, 1);
	rd = gnl_read(fd, file, &line_buffer[fd], line);
	free(file);
	if (rd != 0 || line_buffer[fd] == NULL || line_buffer[fd][0] == '\0')
	{
		if ( !rd && *line)
			*line = NULL;
		return (rd);
	}
	*line = line_buffer[fd];
	line_buffer[fd] = NULL;
	return (1);
}
