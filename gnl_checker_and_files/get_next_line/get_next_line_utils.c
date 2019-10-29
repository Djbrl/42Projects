/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:40:44 by dsy               #+#    #+#             */
/*   Updated: 2019/10/29 17:01:06 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(char *s)
{
	char	*newstr;
	int	i;
	int 	j;	

	i = 0;
	j = ft_strlen(s);
	if (!s)
		return (NULL);
	if (!(newstr = malloc(sizeof(char) * j)))
		return (NULL);
	while (i < j)
	{
		newstr[i] = s[i];
		i++;
	}
	return (newstr);
}

int    check_line_stack(char **stack, char **line)
{
	int i;

	i = 0;
	while ((*stack)[i] != '\n')
	{
		if (*stack[i] == '\0')
			return (0);
		i++;
	}
	(*stack)[i] = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup((*stack) + i + 1);
	return (1);
}
/*
   static int	gnl_read(int fd, char *file, char **buffer)
   {
   static int rd;

   if (fd > 0 && buffer)
   {
   while ((rd = read(fd, file, BUFFER_SIZE)) > 0);
//
}
else
return (-1);
}*/
