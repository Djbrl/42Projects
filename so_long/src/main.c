/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:15:56 by dsy               #+#    #+#             */
/*   Updated: 2020/07/08 01:12:04 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*create_image(t_game *data, int height, int width, int casecolor)
{
	void *image = mlx_new_image(data->mlx_ptr, width, height);
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	int color = casecolor;
	if (pixel_bits != 32)
		color = mlx_get_color_value(data->mlx_ptr, color);
	for(int y = 0; y < height; ++y)
		for(int x = 0; x < width; ++x)
		{
			int pixel = (y * line_bytes) + (x * 4);

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
		}
	return image;
}

void	draw_map(t_game *data)
{
	int j = 0;
	int i = 0;
	while (i < data->height)
	{
		while (j < data->width)
		{
			if (data->map[i][j] == '1')
			 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, j * 1080/data->width, i * 640/data->height);
			if (data->map[i][j] == '0')
			 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->path, j * 1080/data->width, i * 640/data->height);
			if (data->map[i][j] == 'C')
			 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->item, j * 1080/data->width, i * 640/data->height);
			if (data->map[i][j] == 'P')
			{
				data->player_x = i;
				data->player_y = j;
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player, j * 1080/data->width, i * 640/data->height);
			}
			if (data->map[i][j] == 'E')
			 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit, j * 1080/data->width, i * 640/data->height);
			j++;
		}
		j = 0;
		i++;
	}

}

int	main(int ac, char **av)
{
	t_game	data;
	init_game_struct(&data);
	if (ac != 2)
		return (exit_error(ARG_ERR, &data));
	if (!(check_map_extension(av[1])))
		return (exit_error(FILE_EXT, &data));
	if (!parse_map(av[1], &data))
		return (exit_error(FILE_ERR, &data));
	if (!(data.mlx_ptr = mlx_init()))
		return (exit_error(MLX_INIT_ERR, &data));
	if (!(data.win_ptr = mlx_new_window(data.mlx_ptr, 1080, 640, "The Mighty Quest For The Epic Loot")))
		return (exit_error(MLX_WIN_ERR, &data));
	int padding = 20;
	data.wall = create_image(&data, (640 - padding) / data.height, (1080 - padding) / data.width, 0x444);
	data.player = create_image(&data, (640 - padding) / data.height, (1080 - padding) / data.width, 0x880808);
	data.path = create_image(&data, (640 - padding) / data.height, (1080 - padding) / data.width, 0x0);
	data.item = create_image(&data, (640 - padding) / data.height, (1080 - padding) / data.width, 0x777);
	data.exit = create_image(&data, (640 - padding) / data.height, (1080 - padding) / data.width, 0x888);
	// INIT GAME
	draw_map(&data);
	mlx_key_hook(data.win_ptr, key_stroke, &data);
	mlx_hook(data.win_ptr, 17, 0, cross_window, &data); //FIX segfault when crossing window
	mlx_loop(data.mlx_ptr);
	(void)ac;
	(void)av;
	return (0);
}
