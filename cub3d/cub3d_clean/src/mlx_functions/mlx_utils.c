/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 20:46:55 by dsy               #+#    #+#             */
/*   Updated: 2020/05/11 18:41:14 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game_struct(t_game *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->l.mlx_img = NULL;
	data->l.img_addr = NULL;
}

void	free_mlx_struct(t_game *data)
{
	if (data->mlx_ptr != NULL)
		free(data->mlx_ptr);
	if (data->mlx_ptr != NULL)
		free(data->win_ptr);
	if (data->mlx_ptr != NULL)
		free(data->l.mlx_img);
	if (data->mlx_ptr != NULL)
		free(data->l.img_addr);
}
