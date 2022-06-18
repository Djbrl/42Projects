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

char	*read_map_data(int file, char *path)
{
	int		file_size;
	char	*map;
	char	tmp[1];

	file_size = 0;
	while (read(file, tmp, 1) > 0)
		file_size++;
	close(file);
	file = open(path, O_RDONLY);
	map = (char *)malloc(sizeof(char) * (file_size + 1));
	if (read(file, map, file_size) == -1)
	{
		free(map);
		return (NULL);
	}
	close(file);
	return (map);
}

int	check_map(char *map, t_game *data)
{
	char	**map_to_parse;

	if (ft_strlen(map) < 17)
	{
		free(map);
		return (0);
	}
	(void)data;
	map_to_parse = ft_split(map, '\n');
	if (!map_to_parse)
		return (0);
	if (!check_map_config(map_to_parse))
		return (0);
	free_split(map_to_parse);
	free(map);
	return (1);
}

int	parse_map(char *path, t_game *data)
{
	int		file;
	char	*map;

	file = open(path, O_RDONLY);
	if (file < 0)
		return (0);
	map = read_map_data(file, path);
	if (!map || !check_map(map, data))
		return (exit_error(MAP_INVALID, data));
	return (file);
}
