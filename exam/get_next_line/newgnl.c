/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:14:07 by dsy               #+#    #+#             */
/*   Updated: 2020/07/14 19:41:30 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 10

int cutstack(char *s, char **line)
{
	//run through s until \n or \0
	//if ends with \n
	//substr len into the *line
	//then dup into tmp whats after the substr
	//then free s and dump tmp back into it
	//or dup stack straight into line
	//return 1
	char	*tmp;
	int		i;

	i = 0;
	while (s[i] != '\n')
		i++;
	if(s[i] == '\n')
	{
		*line = ft_substr(s, 0, i);
		tmp = ft_strdup(s + i + 1);
		free(s);
		s = tmp;
	}
	else
	{
		*line = ft_strdup(s);
		free(s);
	}
	return (1);
}

int read_gnl(char *s, int ret, int fd)
{
	//read in a while into buff for buffsize til read 0
	//end the read string with a \0
	//strjoin s and buff into tmp
	//put tmp into s
	//if there is a \n in buff, break
	//return ret
	char buf[BUFFER_SIZE + 1];
	char *tmp;

	while ((ret = read(fd, &buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(s, buf);
		free(s);
		s = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

int get_last_stack(char **line, char *s)
{
	*line = ft_strdup(s);
	free(s);
	return (0);
}

int		gnl(int fd, char **line)
{
	//check line, fd, and bufsize
	//check stack and malloc it before return -1
	//run stack until \n \0
	//if stack ends with \n
	//else read
	//if ret 0 ret -1
	//if ret 0 and ends with \0 or is null
	//return last stack bit
	//in other cases, cutstack
	
	static char *s;
	int			ret;
	int			i;

	ret = 1;
	i = 0;
	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!s)
		if (!(s = malloc(1)))
			return (-1);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	//if there is something in stack, treat it
	if (s[i] == '\n')
		return(cutstack(s, line));
	else //else get something in there, or finish the prog
	{
		ret = read_gnl(s, ret, fd);
		if (ret < 0)
			return (-1);
		if (ret == 0 && (s == '\0' || s[i] == 0))
			return (get_last_stack(line, s));
	}
	return (cutstack(s, line));
}
