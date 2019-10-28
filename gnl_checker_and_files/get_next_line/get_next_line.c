/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:06:15 by dsy               #+#    #+#             */
/*   Updated: 2019/10/28 18:24:35 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*line_stack[256];
	char		*current_line;
	int 		rd;
	int 		i;

	if ((fd < 0 || fd > 255) || !line)
		return (-1);//checking
	if (!(current_line = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);//checking
	if (!(read(fd, line_stack[fd], 0)))
		return (-1);//checking


}
