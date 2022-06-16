/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:30:02 by dsy               #+#    #+#             */
/*   Updated: 2022/06/15 17:30:17 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_extension(char *path)
{
	int	i;

	i = 0;
	while (path[i] != '.')
		i++;
	if (path[i + 1] == 'b' && path[i + 2] == 'e'
		&& path[i + 3] == 'r' && path[i + 4] == 0)
		return (1);
	return (0);
}

int	load_map_data(int file, t_game *data)
{
	int		file_size;
	char	*map;
	char	tmp[1];
	int ret;

	file_size = 0;
	while (read(file, tmp, 1) > 0)
		file_size++;
	map = (char *)malloc(sizeof(char) * (file_size + 1));
	if ((ret = read(file, map, file_size)) == -1)
	{
		printf("couldnt load map");
		free(map);
		return (0);
	}
	printf("map loaded(ret %i) : \n%s\n", ret, map);
	close(file);
	(void)data;
	return (1);
}

int	parse_map(char *map, t_game *data)
{
	int file;

	file = open(map, O_RDONLY);
	if (file < 0)
		return (0);
	if (!load_map_data(file, data))
		return (exit_error(MAP_INVALID, data));
	return (file);
}