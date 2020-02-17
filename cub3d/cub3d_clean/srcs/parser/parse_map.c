/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:13:18 by dsy               #+#    #+#             */
/*   Updated: 2020/02/17 22:57:09 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char *remove_spaces(char *line)
{
	char *clean_line;
	int i;
	int j;

	j = 0;
	i = 0;
	while (line[j])
	{
		if (line[j] != ' ')
			i++;
		j++;
	}
	clean_line = (char*)malloc(sizeof(char) * i);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			clean_line[j] = line[i];
			j++;
		}
		i++;
	}
	clean_line[j] = 0;
	return (clean_line);
}

t_map fill_map(t_map map, char **loaded_file)
{
	int i;
	int j;
	int map_size;

	i = 8;
	while (loaded_file[i] != 0)
		i++;
	map_size = i - 8;
	map.map_key = (char **)malloc(sizeof(char*) * map_size + 1);
	i = 8;
	j = 0;
	while (j < map_size)
	{
		map.map_key[j] = remove_spaces(loaded_file[i]);
		j++;
		i++;
	}
	map.map_key[map_size] = 0;
	return (map);
}

int check_map_borders(t_map map, int row, int col)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map.map_key[i] != 0)
	{
		j = 0;
		while (map.map_key[i][j] != 0)
		{
			if ((i == 0 || i == row) &&
					(map.map_key[i][j] != '1' && map.map_key[i][j] != ' '))
				return (0);
			if ((j == 0 || j == col) && map.map_key[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int check_map_player(t_map map)
{
    int i;
    int j;
	int player;

    i = 0;
    j = 0;
	player = 0;
    while (map.map_key[i] != 0)
    {
        j = 0;
        while (map.map_key[i][j] != 0)
        {
            if (map.map_key[i][j] == 'N' || map.map_key[i][j] == 'S'
					|| map.map_key[i][j] == 'E' || map.map_key[i][j] == 'W')
			{
				if (player == 0)
					player++;
				else
					return (0);
			}
            j++;
        }
        i++;
    }
    return (1);
}

int check_map_values(t_map map)
{
    int i;
    int j;

	i = 0;
    j = 0;
    while (map.map_key[i] != 0)
    {
        j = 0;
        while (map.map_key[i][j] != 0)
        {
			if (map.map_key[i][j] != '1' && map.map_key[i][j] != '0'
				&& map.map_key[i][j] != '2' && map.map_key[i][j] != 'N'
				&& map.map_key[i][j] != 'S' && map.map_key[i][j] != 'E'
				&& map.map_key[i][j] != 'W')
				return (0);
			j++;
        }
        i++;
    }
    return (1);
}

int check_map(t_map map)
{
	int i;
	int j;
	int row;
	int col;

	i = 0;
	j = 0;
	row = get_rows(map);
	col = get_cols(map);
	if (check_map_borders(map, row, col) == 0)
	{
		write(1, "[Invalid map] Borders not closed.\n", 34);
		return (0);
	}
	if (check_map_player(map) == 0)
	{
		write(1, "[Invalid map] There is more that one player.\n", 44);
		return (0);
	}
	if (check_map_values(map) == 0)
	{
		write(1, "[Invalid map] Wrong value inside map.\n", 38);
		return (0);
	}
	return (1);
}

t_map	check_map_keys(char **loaded_file, t_map map)
{
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
	check_map(map);
	return (map);
}

t_map parse_map_file(char *path, t_map map)
{
	char **loaded_file;

	loaded_file = load_map_file(path);
	map = check_map_keys(loaded_file, map);
	free_array(loaded_file);
	return (map);
}
//Parsing map done, now parse keys
int main()
{
	t_map map;

	map = parse_map_file(PATH_MAP, map);
	free_map_struct(map);
	return (0);
}
