/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:06:04 by dsy               #+#    #+#             */
/*   Updated: 2020/03/10 22:04:24 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_player_data(t_game *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map_key[i])
	{
		j = 0;
		while (data->map_key[i][j])
		{
			if (data->map_key[i][j] > 'A'
					&& data->map_key[i][j] < 'Z')
			{
				data->pos_x = i;
				data->pos_y = j;
				data->pov = data->map_key[i][j];
				data->map_key[i][j] = '0';
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
