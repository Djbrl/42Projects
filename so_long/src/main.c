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

static int	count_items(t_game *data)
{
	int	i;
	int	j;
	int	items;

	i = 0;
	j = 0;
	items = 0;
	while (i < data->height)
	{
		while (j < data->width)
		{
			if (data->map[i][j] == 'C')
				items++;
			j++;
		}
		j = 0;
		i++;
	}
	return (items);
}

static void	init_game(t_game *data)
{
	int	padding;
	int	resolution[2];

	padding = 0;
	resolution[0] = (640 - padding) / data->height;
	resolution[1] = (1080 - padding) / data->width;
	data->items_left = count_items(data);
	data->score = 0;
	create_image(&data->wall, data, resolution, 0x444);
	create_image(&data->player, data, resolution, 0x880808);
	create_image(&data->player2, data, resolution, 0x880808);
	create_image(&data->path, data, resolution, 0x0);
	create_image(&data->item, data, resolution, 0x777);
	create_image(&data->exit, data, resolution, 0x888666);
	draw_map(data);
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
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (exit_error(MLX_INIT_ERR, &data));
	data.win_ptr = mlx_new_window(data.mlx_ptr, 640, 640, "Deep Blue");
	if (!data.win_ptr)
		return (exit_error(MLX_WIN_ERR, &data));
	init_game(&data);
	data.player2_dx = cos(data.player2_a) * 5;
	data.player2_dy = sin(data.player2_a) * 5; 

	data.posX = 320;
	data.posY = 320;
	data.dirX = -1;
	data.dirX = 0;
	data.planeX = 0;
	data.planeY = 0.66;
	data.oldtime = 0;
	data.time = 0;
	mlx_hook(data.win_ptr, 2, (1L << 0), key_stroke, &data);
	mlx_hook(data.win_ptr, MLX_ON_DESTROY, 0, cross_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
