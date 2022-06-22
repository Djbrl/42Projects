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

void	*create_image(t_game *d, int height, int width, int casecolor)
{
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	int		color;
	int		x;
	int		y;
	int		pixel;

	x = 0;
	y = 0;
	color = casecolor;
	image = mlx_new_image(d->mlx_ptr, width, height);
	buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	if (pixel_bits != 32)
		color = mlx_get_color_value(d->mlx_ptr, color);
	while (y < height)
	{
		while (x < width)
		{
			pixel = (y * line_bytes) + (x * 4);
			if (endian == 1)
			{
				buffer[pixel + 0] = (color >> 24);
				buffer[pixel + 1] = (color >> 16) & 0xFF;
				buffer[pixel + 2] = (color >> 8) & 0xFF;
				buffer[pixel + 3] = (color) & 0xFF;
			}
			else if (endian == 0)
			{
				buffer[pixel + 0] = (color) & 0xFF;
				buffer[pixel + 1] = (color >> 8) & 0xFF;
				buffer[pixel + 2] = (color >> 16) & 0xFF;
				buffer[pixel + 3] = (color >> 24);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (image);
}

static void	choose_texture(t_game *d, int i, int j)
{
	if (d->map[i][j] == '1')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->wall, \
			j * 1080 / d->width, i * 640 / d->height);
	if (d->map[i][j] == '0')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->path, \
			j * 1080 / d->width, i * 640 / d->height);
	if (d->map[i][j] == 'C')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->item, \
			j * 1080 / d->width, i * 640 / d->height);
	if (d->map[i][j] == 'P')
	{
		d->player_x = i;
		d->player_y = j;
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->player, \
			j * 1080 / d->width, i * 640 / d->height);
	}
	if (d->map[i][j] == 'E')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->exit, j \
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
