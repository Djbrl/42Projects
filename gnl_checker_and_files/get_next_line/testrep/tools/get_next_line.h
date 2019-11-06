/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:39:13 by dsy               #+#    #+#             */
/*   Updated: 2019/11/06 16:24:07 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define MAX_FD	256
# include <stdlib.h>
# include <unistd.h>

void	ft_bzero(void *s, size_t n);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		get_next_line(int fd, char **line);
int		setup_next_line(char **line_stack, char **line);
int		gnl_read(int fd, char *current_line, char **line_stack, char **line);
#endif
