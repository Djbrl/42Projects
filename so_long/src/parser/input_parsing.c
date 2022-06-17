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

int	get_map_heigth(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_map_width(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

int	check_map_content(char **map)
{
	int	i;
	int	j;
	int	height;
	int width;

	height = get_map_heigth(map) - 1;
	width = get_map_width(map) - 1;
	i = 0;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (map[height][j])
	{
		if (map[height][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][width] != '1')
			return (0);
		if (map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'E' \
			&& map[i][j] != '0' && map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

int check_map_config(char **map)
{
	int	i;
	int	j;
	int	p_count;
	int	c_count;
	int	e_count;

	i = 0;
	j = 0;
	p_count = 0;
	c_count = 0;
	e_count = 0;
	if (!check_map_content(map))
		return (0);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c_count++;
			if (map[i][j] == 'P')
				p_count++;
			if (map[i][j] == 'E')
				e_count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (!c_count || !p_count || !e_count || p_count > 1)
		return (0);
	return (1);
}

int	check_map(char *map, t_game *data)
{
	char	**map_to_parse;

	if (ft_strlen(map) < 18)
	{
		free(map);
		return (0);
	}
	(void)data;
	map_to_parse = ft_split(map, '\n');
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