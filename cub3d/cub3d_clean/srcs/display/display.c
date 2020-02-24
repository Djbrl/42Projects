/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:51:13 by dsy               #+#    #+#             */
/*   Updated: 2020/02/24 15:50:40 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int testesc_window(int key, void *params)
{
	(void)key;
	t_game *data = (t_game *)params;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("Exit (esc).\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int testcross_window(int key, void *params)
{
	(void)key;
	(void)params;
	printf("Exit (cross).\n");
	exit(EXIT_SUCCESS);
}

int testtoggle_minimap(int key, void *params)
{
	(void)key;
	t_game *data = (t_game *)params;
	int bpp = 1;
	int sl = 1;
	int endian = 0;;
	int x = 0, y = 0;
	data->mlx_img = mlx_new_image(data->mlx_ptr, 1500, 1700);
	data->img_addr = (int*)mlx_get_data_addr(data->mlx_img, &bpp, &sl, &endian);
	while (++y < 100)
	{
		x = 0;
		while (++x < 200)
			data->img_addr[x * 100 + y] = 0xFFFFFF;
	}
/*	if (key == KEY_U)
	{
		if (data->mlx_img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	}
	else*/
	if (data->mlx_img != NULL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
	return (0);
}

int	testkey_stroke(int key, void *params)
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
	if (key == KEY_LEFT)
		printf("Pressed left.\n");
	if (key == KEY_RIGHT)
		printf("Pressed right.\n");
	if (key == KEY_UP)
		printf("Pressed up.\n");
	if (key == KEY_DOWN)
		printf("Pressed down.\n");
	if (key == KEY_M)
		testtoggle_minimap(key, data);
	if (key == KEY_U && data->mlx_img != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->mlx_img);
		data->mlx_img = NULL;
	}
	if (key == KEY_ESC)
		testesc_window(key, data);
	return (0);
}

int testinit_game(t_game *data)
{
	int x_res = ft_atoi(data->r_key[1]), y_res = ft_atoi(data->r_key[2]);
	
	init_game_struct(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, x_res, y_res, "Cub3D");
	mlx_hook(data->win_ptr, 2, 0, key_stroke, data);
	mlx_hook(data->win_ptr, 17, 0, cross_window, data);
	mlx_loop(data->mlx_ptr);
	//mlx_key_hook(win_ptr, deal_key, (void*)&p);
	//mlx_mouse_hook(init, (&mlx_new_window)(init, 300, 300, "test"), keys.a);
	return (0);
}
