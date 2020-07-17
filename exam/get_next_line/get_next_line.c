/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:10:51 by dsy               #+#    #+#             */
/*   Updated: 2020/07/17 04:00:12 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			cut_stack(char **s, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	//om avance jusqua fin de chaine ou fin de ligne
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	//si c'est une fin de ligne
	if ((*s)[i] == '\n')
	{
		//on copie tout ce qui est avant le \n dans line
		if (!(*line = ft_substr(*s, 0, i)))
			return (-1);
		//puis on dup ce aui est apres le \n dans tmp
		if (!(tmp = ft_strdup(*s + i + 1)))
			return (-1);
		free(*s);
		//puis on free > reassign dans s
		*s = tmp;
	}
	else
	{
	//sinon on dup directement la fin de chaine dans line
		if (!(*line = ft_strdup(*s)))
			return (-1);
		free(*s);
	}
	return (1);
}

int			gnl_read(int fd, char **s, int ret)
{
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	
	//boucle de lecture
	while ((ret = read(fd, &buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		//on join buff and le static en boucle dans tmp
		if (!(tmp = ft_strjoin(*s, buff)))
			return (-1);
		//on free s puis lui assgine le resultat de tmp
		free(*s);
		*s = tmp;
		//s'il y a un \n dans la chaine, on quitte la boucle
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ret);
}

int			empty_last_stack(char **line, char *stack)
{
	*line = ft_strdup(stack);
	free(stack);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char *s;
	int			ret;
	int			i;

	ret = 1;
	i = 0;
	//gestion d'erreur
	if (line == NULL || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	//on malloc le static pour la premiere iteration
	if (!s)
		if (!(s = malloc(1)))//malloc protege
			return (-1);
	//on parcours la chaine
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	//si on est a la fin d'une ligne, cutstack
	if (s[i] == '\n')
		return (cut_stack(&s, line));
	else
	{
		//sinon on est soit sur la premiere iteration, soit la derniere
		//soit au milieu d'une phrase (petit buffer_size)
		ret = gnl_read(fd, &s, ret);
		//sortie si erreur de read
		if (ret < 0)
			return (-1);
		//derniere iteration
		//si la chaine se termine ou commence par \0
		//et le read est nul (fin du fichier)
		if (ret == 0 && (s[0] == '\0' || s[i] == '\0'))
			return (empty_last_stack(line, s));
	}
	//on est au milieu du file et on continue a lire/couper
	return (cut_stack(&s, line));
}
