/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:13:08 by dsy               #+#    #+#             */
/*   Updated: 2020/02/15 23:51:52 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	load_into_file(char **file)
{
	
}

int fetch_file(char *path)
{
	char	*file;
	char	*buf;
	int		fd;

	fd = open(path, O_RDONLY);
	while ((read(fd, file, 10)))
		buf = ft_strjoin(file, buf);
	printf("file : \n%s", buf);
	return (0);
}

int main()
{
	fetch_file("../../files/map.cub");
	return (0);
}
