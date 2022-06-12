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

// int	init_data(t_game *data)
// {
// 	data->pos_x = 0;
// 	data->pos_y = 0;
// 	data->dirX = 0;
// 	data->dirY = 0;
// 	data->planeX = 0;
// 	data->planeY = 0;
// 	//data->map = 0;
// 	data->so.mlx_img = 0;
// 	data->no.mlx_img = 0;
// 	data->ea.mlx_img = 0;
// 	data->we.mlx_img = 0;
// 	data->floor.set = 0;
// 	data->ceiling.set = 0;
// 	//data->sprite.ptr = 0;
// 	//data->valid = 1;
// 	//data->save = 0;
// 	//data->weapon.ptr = 0;
// 	//data->speed = 1;
// 	//data->life = 1;
// 	return (1);
// }

// int	init_game(t_game *data)
// {
// 	init_game_struct(data);
// 	init_data(data);
// 	data->width = ft_atoi(data->r_key[1]);
// 	data->height = ft_atoi(data->r_key[2]);
// 	data->floor.R = ft_atoi(data->f_key[0]);
// 	data->floor.G = ft_atoi(data->f_key[1]);
// 	data->floor.B = ft_atoi(data->f_key[2]);
// 	data->ceiling.R = ft_atoi(data->r_key[0]);
// 	data->ceiling.G = ft_atoi(data->r_key[1]);
// 	data->ceiling.B = ft_atoi(data->r_key[2]);
// 	if (!(get_player_data(data)))
// 		return (0);
// 	if (!(data->mlx_ptr = mlx_init()))
// 		return (0);
// 	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, data->height, "Cub3D")))
// 		return (0);
// 	mlx_hook(data->win_ptr, 2, 0, key_stroke, data);
// 	mlx_hook(data->win_ptr, 17, 0, cross_window, data);
// 	//mlx_loop_hook(data->mlx_ptr, raycasting, data);
// 	mlx_loop(data->mlx_ptr);
// 	return (0);
// }


int	esc_window(int key, void *params)
{
	(void)key;
	t_game *data = (t_game *)params;
	if(data->mlx_ptr != NULL && data->win_ptr != NULL)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("Exit (esc).\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	cross_window(int key, void *params)
{
	(void)key;
	(void)params;
	printf("Exit (cross).\n");
	exit(EXIT_SUCCESS);
}

int	key_stroke(int key, void *params)
{
	t_game *data = (t_game *)params;
	if (key == KEY_W)
		printf("Pressed W.\n");
	if (key == KEY_S)
		printf("Pressed S.\n");
	if (key == KEY_A)
		printf("Pressed A.\n");
	if (key == KEY_D)
		printf("Pressed D.\n");
	// if (key == KEY_M)
	// {
	// 		drawVerLine(i, 100, 300, 0xFFFFFF, data);
//		write(1, "ok\n", 3);
//		raycasting(data);
//			drawVerline(key, data);
//	}
	if (key == KEY_ESC)
		esc_window(key, data);
	printf("key : %i\n", key);
	return (0);
}


int main(int ac, char **av)
{
	t_game data;
	// t_game data;
	// int		ret;

	// if (ac != 2)
	// {
	// 	write(1, "Error\n[Input]Please only input a valid map path.\n", 49);
	// 	return (0);
	// }
	// if (!(check_map_extension(av[1])))
	// {
	// 	write(1, "Error\n[Input]Bad map extension.\n", 32);
	// 	return (0);
	// }
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
		return (0);
	if (!(data.win_ptr = mlx_new_window(data.mlx_ptr, 1080, 640, "The Mighty Quest For The Epic Loot")))
		return (0);
	mlx_key_hook(data.win_ptr, key_stroke, &data);
	mlx_hook(data.win_ptr, 17, 0, cross_window, &data);
	//mlx_loop_hook(data->mlx_ptr, raycasting, data);
	mlx_loop(data.mlx_ptr);

	(void)ac;
	(void)av;
	//if (ret != 0)
	//free_map_struct(&map);
	return (0);
}
