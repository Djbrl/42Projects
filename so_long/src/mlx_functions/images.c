/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:16:37 by dsy               #+#    #+#             */
/*   Updated: 2022/06/22 14:16:52 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_pixel_data(t_img *img, int pixel, int color)
{
	if (img->endian == 1)
	{
		img->img_addr[pixel + 0] = (color >> 24);
		img->img_addr[pixel + 1] = (color >> 16) & 0xFF;
		img->img_addr[pixel + 2] = (color >> 8) & 0xFF;
		img->img_addr[pixel + 3] = (color) & 0xFF;
	}
	else if (img->endian == 0)
	{
		img->img_addr[pixel + 0] = (color) & 0xFF;
		img->img_addr[pixel + 1] = (color >> 8) & 0xFF;
		img->img_addr[pixel + 2] = (color >> 16) & 0xFF;
		img->img_addr[pixel + 3] = (color >> 24);
	}
}

void	create_image(t_img *img, t_game *d, int resolution[2], int casecolor)
{
	int		color;
	int		x;
	int		y;
	int		pixel;

	x = 0;
	y = 0;
	color = casecolor;
	img->mlx_img = mlx_new_image(d->mlx_ptr, resolution[1], resolution[0]);
	img->img_addr = mlx_get_data_addr(img->mlx_img, \
		&img->bpp, &img->sl, &img->endian);
	if (img->bpp != 32)
		color = mlx_get_color_value(d->mlx_ptr, color);
	while (y < resolution[0])
	{
		while (x < resolution[1])
		{
			pixel = (y * img->sl) + (x * 4);
			write_pixel_data(img, pixel, color);
			x++;
		}
		x = 0;
		y++;
	}
}

static void	choose_texture(t_game *d, int i, int j)
{
	if (d->map[i][j] == '1')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->wall.mlx_img, \
			j * 1080 / d->width, i * 640 / d->height);
	if (d->map[i][j] == '0')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->path.mlx_img, \
			j * 1080 / d->width, i * 640 / d->height);
	if (d->map[i][j] == 'C')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->item.mlx_img, \
			j * 1080 / d->width, i * 640 / d->height);
	if (d->map[i][j] == 'P')
	{
		d->player_x = i;
		d->player_y = j;
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->player.mlx_img, \
			j * 1080 / d->width, i * 640 / d->height);
	}
	if (d->map[i][j] == 'E')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->exit.mlx_img, j \
			* 1080 / d->width, i * 640 / d->height);
}

void	draw_map(t_game *data)
{
	int	j;
	int	i;

	i = -1;
	j = -1;
	while (++i < data->height)
	{
		while (++j < data->width)
			choose_texture(data, i, j);
		j = -1;
	}
}
