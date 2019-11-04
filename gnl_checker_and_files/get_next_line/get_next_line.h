/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:39:13 by dsy               #+#    #+#             */
/*   Updated: 2019/11/04 11:01:21 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10
# define MAX_FD	256
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char 		*ft_strdup(char *s);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *s);
int			get_next_line(int, char**);
int			gnl_verify_line(char **, char **);
int			gnl_read_file(int fd, char *file, char **line_buffer, char **line);
#endif
