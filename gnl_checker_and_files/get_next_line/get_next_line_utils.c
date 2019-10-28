/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:40:44 by dsy               #+#    #+#             */
/*   Updated: 2019/10/28 17:51:20 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_read(int fd, char *file, char **buffer)
{
	static int rd;

	if (fd > 0 && buffer)
	{
		while ((rd = read(fd, file, BUFFER_SIZE)) > 0)
			//
	}
	else
		return (-1);
}
