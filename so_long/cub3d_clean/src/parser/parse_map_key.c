/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:26:32 by dsy               #+#    #+#             */
/*   Updated: 2020/05/11 18:41:17 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	i = 0;
	j = 0;
	data->row = get_rows(data);
	data->col = get_cols(data);
	if (data->row < 3 || data->col < 3)
		return (0);
	if (!(check_map_borders(data, data->row, data->col)))
	{
		data->error = 3;
		return (0);
	}
	if (!(check_map_player(data)))
	{
		data->error = 4;
		return (0);
	}
	if (!(check_map_values(data)))
	{
		data->error = 5;
		return (0);
	}
	return (1);
}
