/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:13:18 by dsy               #+#    #+#             */
/*   Updated: 2020/02/16 07:35:07 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_map fill_map(t_map map, char **loaded_file)
{
	int i;
	int j;
	int map_size;

	i = 8;
	j = 0;
	while (loaded_file[i] != 0)
		map_size = i++;
	map.map_key = (char **)malloc(sizeof(char*) * map_size);
	i = 8;
	while (i < map_size)
	{
		map.map_key[j] = loaded_file[i];
		i++;
		j++;
	}
	map.map_key[i] = 0;
	return (map);
}

int check_map(t_map map) //finish checkmap
{
	int i;
	int j;
	int row;
	int col;

	i = 0;
	j = 0;
	row = get_rows(map);
	col = get_cols(map);
	while (map.map_key[i] != 0)//row
	{
		j = 0;
		while (map.map_key[i][j] != 0)//col
		{
			if (i == 0 && map.map_key[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_keys(char **loaded_file)
{
	t_map map;
	int i;

	i = 0;
	map.r_key = ft_split(loaded_file[0], ' ');
	map.n_key = ft_split(loaded_file[1], ' ');
	map.so_key = ft_split(loaded_file[2], ' ');
	map.w_key = ft_split(loaded_file[3], ' ');
	map.e_key = ft_split(loaded_file[4], ' ');
	map.s_key = ft_split(loaded_file[5], ' ');
	map.f_key = ft_split(loaded_file[6] + 2, ',');
	map.c_key = ft_split(loaded_file[7] + 2, ',');
	map = fill_map(map, loaded_file);
	//check_map(map);
	//free_map_struct(map);
	return (1);
}

int	parse_map_file(char *path)
{
	char **loaded_file;

	loaded_file = load_map_file(path); //phantom leaks ?
	check_map_keys(loaded_file);
	free_array(loaded_file);
	//system("leaks a.out");
	return (1);
}

int main()
{
	parse_map_file(PATH_MAP);
	return (0);
}
