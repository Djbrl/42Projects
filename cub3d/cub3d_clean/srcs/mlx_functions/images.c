/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:43:27 by dsy               #+#    #+#             */
/*   Updated: 2020/02/24 18:41:47 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int basic_image(int key, void *params)
{
	(void)key;

	t_game *data;
	int bpp;
	int sl;
	int endian;
	int x = -1, y = -1;

   	data = (t_game *)params;
	data->mlx_img = mlx_new_image(data->mlx_ptr, data->x_res, data->y_res);
	data->img_addr = (int*)mlx_get_data_addr(data->mlx_img, &bpp, &sl, &endian);
	while (++y < data->y_res)
	{
		x = -1;
		while (++x < data->x_res)
			data->img_addr[x * data->y_res + y] = 0xFFFFFF;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, key, 0);	
	return (0);
}
