/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:26:32 by dsy               #+#    #+#             */
/*   Updated: 2020/02/24 19:22:14 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
/*
int	check_map_borders(t_game *data, int row, int col)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map_key[i] != 0)
	{
		j = 0;
		while (data->map_key[i][j] != 0)
		{
			if ((i == 0 || i == row) &&
					(data->map_key[i][j] != '1' && data->map_key[i][j] != ' '))
				return (0);
			if ((j == 0 || j == col) && data->map_key[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_player(t_game *data)
{
	int i;
	int j;
	int player;

	i = 0;
	j = 0;
	player = 0;
	while (data->map_key[i] != 0)
	{
		j = 0;
		while (data->map_key[i][j] != 0)
		{
			if (data->map_key[i][j] == 'N' || data->map_key[i][j] == 'S'
					|| data->map_key[i][j] == 'E' || data->map_key[i][j] == 'W')
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
	return (player);
}

int	check_map_values(t_game *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map_key[i] != 0)
	{
		j = 0;
		while (data->map_key[i][j] != 0)
		{
			if (data->map_key[i][j] != '1' && data->map_key[i][j] != '0'
					&& data->map_key[i][j] != '2' && data->map_key[i][j] != 'N'
					&& data->map_key[i][j] != 'S' && data->map_key[i][j] != 'E'
					&& data->map_key[i][j] != 'W')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_game *data)
{
	int i;
	int j;
	int row;
	int col;

	i = 0;
	j = 0;
	row = get_rows(data);
	col = get_cols(data);
	if (!(check_map_borders(data, row, col)))
	{
		write(1, "Error\n[Invalid map] Borders not closed.\n", 40);
		return (0);
	}
	if (!(check_map_player(data)))
	{
		write(1, "Error\n[Invalid map] Invalid number of POV in the map.\n", 54);
		return (0);
	}
	if (!(check_map_values(data)))
	{
		write(1, "Error\n[Invalid map] Wrong value inside map.\n", 44);
		return (0);
	}
	return (1);
}
*/
int	find_longest_row(t_game *data)
{
	int i;
	int j;
	int max;

	i = 0;
	j = 0;
	max = 0;
	while (data->map_key[i])
	{
		j = 0;
		row = 0;
		while (data->map_key[i][j])
			if (data->map_key[i][j] != ' ')
				j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

int	arrange_map(t_game *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("longest row : %i\n", find_longest_row(data));
	return (1);
}
