/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:05:23 by dsy               #+#    #+#             */
/*   Updated: 2020/03/10 19:23:02 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_game(t_game *data)
{
	init_game_struct(data);
	data->x_res = ft_atoi(data->r_key[1]);
	data->y_res = ft_atoi(data->r_key[2]);
	if (!(get_player_data(data)))
		return (0);
	if (!(data->mlx_ptr = mlx_init()))
		return (0);
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, data->x_res, data->y_res, "Cub3D")))
		return (0);
	mlx_hook(data->win_ptr, 2, 0, key_stroke, data);
	mlx_hook(data->win_ptr, 17, 0, cross_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
