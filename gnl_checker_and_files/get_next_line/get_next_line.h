/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:39:13 by dsy               #+#    #+#             */
/*   Updated: 2019/10/31 15:47:29 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10
# define MAX_FD	1024
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int			get_next_line(int, char**);
int	check_line_buffer(char **, char **);
char 		*ft_strdup(char *s);
int	gnl_read(int fd, char *file, char **line_buffer, char **line);
#endif
