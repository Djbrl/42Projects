/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 20:46:55 by dsy               #+#    #+#             */
/*   Updated: 2020/02/24 15:39:56 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_game_struct(t_game *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->mlx_img = NULL;
	data->img_addr = NULL;
}

void	free_mlx_struct(t_game *data)
{
	if (data->mlx_ptr != NULL)
		free(data->mlx_ptr);
	if (data->mlx_ptr != NULL)
		free(data->win_ptr);
	if (data->mlx_ptr != NULL)
		free(data->mlx_img);
	if (data->mlx_ptr != NULL)
		free(data->img_addr);
}
