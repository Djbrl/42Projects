/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:13:18 by dsy               #+#    #+#             */
/*   Updated: 2020/02/24 15:21:45 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	fill_map(t_game *data, char **loaded_file)
{
	int i;
	int j;
	int map_size;

	i = 8;
	while (loaded_file[i] != 0)
		i++;
	map_size = i - 8;
	if (!(data->map_key = (char **)malloc(sizeof(char*) * (map_size + 1))))
		return (0);
	i = 8;
	j = 0;
	while (j < map_size)
	{
		data->map_key[j] = remove_spaces(loaded_file[i]);
		j++;
		i++;
	}
	data->map_key[map_size] = 0;
	return (1);
}

int	check_file_keys(char **loaded_file, t_game *data)
{
	int i;

	i = 0;
	data->r_key = ft_split(loaded_file[0], ' ');
	data->n_key = ft_split(loaded_file[1], ' ');
	data->so_key = ft_split(loaded_file[2], ' ');
	data->w_key = ft_split(loaded_file[3], ' ');
	data->e_key = ft_split(loaded_file[4], ' ');
	data->s_key = ft_split(loaded_file[5], ' ');
	data->f_key = ft_split(loaded_file[6] + 2, ',');
	data->c_key = ft_split(loaded_file[7] + 2, ',');
	if (!(fill_map(data, loaded_file)))
		return (0);
	if (!(check_keys_content(data, loaded_file)))
		write(1, "Error\n[Bad Map Keys] Map Keys are incorrect.\n", 45);
	if (!(adjust_resolution(data)) || !(check_map(data)))
		return (0);
	return (1);
}

int	parse_map_file(char *path, t_game *data)
{
	char **loaded_file;

	if (!(loaded_file = load_map_file(path))
		|| !(check_file_keys(loaded_file, data)))
	{
		if (loaded_file)
			free_array(loaded_file);
		return (0);
	}
	arrange_map(data);
	free_array(loaded_file);
	return (1);
}
