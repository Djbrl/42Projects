/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:26:32 by dsy               #+#    #+#             */
/*   Updated: 2020/02/19 21:45:30 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
