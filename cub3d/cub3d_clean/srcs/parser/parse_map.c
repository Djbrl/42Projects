/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:13:18 by dsy               #+#    #+#             */
/*   Updated: 2020/03/05 04:07:48 by dsy              ###   ########.fr       */
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

int	seek(char *key)
{
	int i;

	i = 0;
	while (key[i])
	{
		if (key[i] >= '0' && key[i] <= '2')
			return (i);
		i++;
	}
	return (0);
}

int	check_file_keys(char **lfile, t_game *data)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (!lfile[i])
		{
			data->error = 2;
			return (0);
		}
		i++;
	}
	data->r_key = ft_split(lfile[0], ' ');
	data->n_key = ft_split(lfile[1], ' ');
	data->so_key = ft_split(lfile[2], ' ');
	data->w_key = ft_split(lfile[3], ' ');
	data->e_key = ft_split(lfile[4], ' ');
	data->s_key = ft_split(lfile[5], ' ');
	data->f_key = ft_split(lfile[6] + seek(lfile[6]), ',');
	data->c_key = ft_split(lfile[7] + seek(lfile[7]), ',');
	if (!(fill_map(data, lfile)))
		return (0);
	if (!(check_keys_content(data, lfile)))
		return (0);
	if (!(adjust_resolution(data)) || !(check_map(data)))
		return (0);
	return (1);
}

int	parse_map_file(char *path, t_game *data)
{
	char **loaded_file;

	if (!(loaded_file = load_map_file(path, data))
		|| !(check_file_keys(loaded_file, data)))
	{
		if (loaded_file)
			free_array(loaded_file);
		report_error(data);
		return (0);
	}
	free_array(loaded_file);
	return (1);
}
