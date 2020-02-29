/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:43:27 by dsy               #+#    #+#             */
/*   Updated: 2020/02/29 23:08:16 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	drawVerline(int key, void *params)
{
	(void)key;
	t_game *data;
	int line_col;

	line_col = 0;
	data = (t_game *)params;
	data->mlx_img = mlx_new_image(data->mlx_ptr, data->x_res, data->y_res);
	data->img_addr = (int*)mlx_get_data_addr(data->mlx_img, &data->bpp, &data->sl, &data->endian);
	printf("we got to this place\n");
	while (data->drawStart++ < data->drawEnd)
	{
		data->img_addr[data->drawStart * data->y_res + line_col] = 0xffffff;
	}
	printf("Magic done\n");
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
	return (0);
}
/*
int basic_image(int key, void *params)
{
	(void)key;

	t_game *data;
	int bpp;
	int sl;
	int endian;
	int x = -1;
	int y = -1;

	data = (t_game *)params;
	data->mlx_img = mlx_new_image(data->mlx_ptr, data->x_res, data->y_res);
	data->img_addr = (int*)mlx_get_data_addr(data->mlx_img, &bpp, &sl, &endian);
	while (++x < data->drawEnd)
	{
		y = 100;
		//while (++x < data->drawEnd)
			data->img_addr[x * (data->y_res) + y] = 0xffffff;
		//	data->img_addr[(x * data->y_res) / 2] = 0xFFFFFF;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, key, 0);	
	return (0);
}*/
