/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:13:18 by dsy               #+#    #+#             */
/*   Updated: 2020/02/23 13:09:17 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	fill_map(t_map *map, char **loaded_file)
{
	int i;
	int j;
	int map_size;

	i = 8;
	while (loaded_file[i] != 0)
		i++;
	map_size = i - 8;
	if (!(map->map_key = (char **)malloc(sizeof(char*) * (map_size + 1))))
		return (0);
	i = 8;
	j = 0;
	while (j < map_size)
	{
		map->map_key[j] = remove_spaces(loaded_file[i]);
		j++;
		i++;
	}
	map->map_key[map_size] = 0;
	return (1);
}

int	check_file_keys(char **loaded_file, t_map *map)
{
	int i;

	i = 0;
	map->r_key = ft_split(loaded_file[0], ' ');
	map->n_key = ft_split(loaded_file[1], ' ');
	map->so_key = ft_split(loaded_file[2], ' ');
	map->w_key = ft_split(loaded_file[3], ' ');
	map->e_key = ft_split(loaded_file[4], ' ');
	map->s_key = ft_split(loaded_file[5], ' ');
	map->f_key = ft_split(loaded_file[6] + 2, ',');
	map->c_key = ft_split(loaded_file[7] + 2, ',');
	if (!(fill_map(map, loaded_file)))
		return (0);
	if (!(check_keys_content(map, loaded_file)))
		write(1, "Error\n[Bad Map Keys] Map Keys are incorrect.\n", 45);
	if (!(adjust_resolution(map)) || !(check_map(map)))
		return (0);
	return (1);
}

int	parse_map_file(char *path, t_map *map)
{
	char **loaded_file;

	if (!(loaded_file = load_map_file(path))
		|| !(check_file_keys(loaded_file, map)))
	{
		if (loaded_file)
			free_array(loaded_file);
		return (0);
	}
	free_array(loaded_file);
	return (1);
}
