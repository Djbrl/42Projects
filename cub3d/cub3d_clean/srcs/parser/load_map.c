/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:13:08 by dsy               #+#    #+#             */
/*   Updated: 2020/02/19 21:46:35 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		get_file_size(char *path)
{
	int		fd;
	int		file_size;
	char	tmp[1];

	file_size = 0;
	fd = open(path, O_RDONLY);
	if (fd > 0)
		while (read(fd, tmp, 1) > 0)
			file_size++;
	else
		return (-1);
	close(fd);
	return (file_size - 1);
}

char	*fetch_file(char *path)
{
	char	*file;
	int		fd;
	int		ret;
	int		n;

	if ((n = get_file_size(path)) < 0)
		return (0);
	if (!(file = (char*)malloc(sizeof(char) * n)))
	{
		free(file);
		return (0);
	}
	if ((fd = open(path, O_RDONLY)) < 0)
		return (0);
	if ((ret = read(fd, file, n)) < 0)
		return (0);
	return (file);
}

char	**load_map_file(char *path)
{
	char	**parsed_file;
	char	*file;
	int		i;

	i = 0;
	if ((file = fetch_file(path)) == 0)
		return (NULL);
	if ((parsed_file = ft_split(file, '\n')) == 0)
	{
		free_array(parsed_file);
		return (NULL);
	}
	free(file);
	return (parsed_file);
}
