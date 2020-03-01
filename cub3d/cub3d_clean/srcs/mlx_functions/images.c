/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:43:27 by dsy               #+#    #+#             */
/*   Updated: 2020/03/01 16:27:28 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define WIN_HEIGHT 1280
#define WIN_WIDTH 1024

int	drawVerline(int key, void *params)
{
    t_game  *mlx = (t_game*)params;
//  int     count_w;
    int     count_h;

    count_h = mlx->drawStart;
    mlx->mlx_img = mlx_new_image(mlx->mlx_ptr, mlx->y_res, mlx->x_res);
    mlx->img_addr = (int *)mlx_get_data_addr(mlx->mlx_img, &mlx->bpp, &mlx->sl,
        &mlx->endian);
    while (++count_h < mlx->drawEnd)
    {
		mlx->img_addr[count_h * mlx->y_res + 10] = 0xFFFFFF;
    }
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->mlx_img, 0, 0);
    return (0);
}
/*
int	drawVerline(int key, void *params)
{
	(void)key;
	t_game *data;
	t_mlx	mlx;
	int line_col;

	line_col = 0;
	data = (t_game *)params;
	mlx.mlx_img = mlx_new_image(data->mlx_ptr, data->x_res, data->y_res);
	mlx.img_addr = (int*)mlx_get_data_addr(mlx.mlx_img, &mlx.bpp, &mlx.sl, &mlx.endian);
	printf("we got to this place\n");
	while (data->drawStart++ < data->drawEnd)
	{
		mlx.img_addr[data->drawStart * data->y_res + line_col] = 0xffffff;
	}
	printf("Magic done\n");
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, mlx.mlx_img, 0, 0);
	return (0);
}*/
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
