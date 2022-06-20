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

void	create_image(t_game *data, int height, int width)
{
	void *image = mlx_new_image(data->mlx_ptr, width, height);
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	int color = 0x444444;
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
	data->image = image;
}

int	main(int ac, char **av)
{
	t_game	data;
	int		position[2];
	// int		ret;
	init_game_struct(&data);
	if (ac != 2)
		return (exit_error(ARG_ERR, &data));
	if (!(check_map_extension(av[1])))
		return (exit_error(FILE_EXT, &data));
	if (!parse_map(av[1], &data))
		return (exit_error(FILE_ERR, &data));
	//ROADMAP
	// - parse map
	// - init structure
	// - start game window

	// ret = parse_map_file(av[1], &data);
	// if (ret)
	// 	if (!(init_game(&data)))
	// 	{
	// 		write(1, "Error\n[MLX]Connection to MLX failed.\n", 37);
	// 		return (0);
	// 	}
	// write(1, "o", 1);
	//init_game(&data);
	if (!(data.mlx_ptr = mlx_init()))
		return (exit_error(MLX_INIT_ERR, &data));
	if (!(data.win_ptr = mlx_new_window(data.mlx_ptr, 1080, 640, "The Mighty Quest For The Epic Loot")))
		return (exit_error(MLX_WIN_ERR, &data));
	mlx_key_hook(data.win_ptr, key_stroke, &data);
	mlx_hook(data.win_ptr, 17, 0, cross_window, &data);
	position[0] = 0;
	position[1] = 0;
	int padding = 20;
	create_image(&data, (640 - padding) / data.height, (1080 - padding) / data.width);
	int i = 0;
	int j = 0;
	while (data.map[i])
	{
		while (data.map[i][j])
			printf("%c\n", data.map[i][j++]);
		j = 0;
		i++;
	}
	// while(i < data.width)
	// {
	// 	while (j < data.height)
	// 	{
	// 		printf("%c\n", data.map[i][j]);
	// 		j++;
	// 	}
	// 	i++;
	// 	j = 0;
	// }
	i = 0;
	j = 0;
	while (data.map[i])
	{
		while (data.map[i][j])
		{
			if (data.map[i][j] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.image, i * 1080/data.width, j * 640/data.height);
			j++;
		}
		j = 0;
		i++;
	}
	// position[0] = 1080/2 + (1080/20 * 3);
	// position[1] = 640/2 - (1080/20 * 3) ;
	// create_image(&data, 640 / 20, 1080 / 20, position);
	//destroy image before quitting
	mlx_loop(data.mlx_ptr);
	// int i = 0;
	// int j = 0;
	// while(i++ < 10)
	// 	mlx_pixel_put(data.mlx_ptr, data.win_ptr, i, 0, 0xFFFFFF);
	// while(j++ < 10)
	// 	mlx_pixel_put(data.mlx_ptr, data.win_ptr, 0, j, 0xFFFFFF);
	// mlx_loop(data.mlx_ptr);
	// //if (ret != 0)
	//free_map_struct(&map);
	(void)ac;
	(void)av;
	return (0);
}
