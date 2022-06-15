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

int	main(int ac, char **av)
{
	t_game	data;
	// int		ret;
	if (ac != 2)
		return (exit_error(ARG_ERR));
	if (!(check_map_extension(av[1])))
		return (exit_error(FILE_EXT));
	if (!parse_map(av[1]))
		return (exit_error(FILE_ERR));
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
		return (exit_error(MLX_INIT_ERR));
	if (!(data.win_ptr = mlx_new_window(data.mlx_ptr, 1080, 640, "The Mighty Quest For The Epic Loot")))
		return (exit_error(MLX_WIN_ERR));
	mlx_key_hook(data.win_ptr, key_stroke, &data);
	mlx_hook(data.win_ptr, 17, 0, cross_window, &data);
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
