/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:51:13 by dsy               #+#    #+#             */
/*   Updated: 2020/02/23 19:00:57 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int esc_window(int key, void *params)
{
	(void)key;
	t_mlx *m = (t_mlx *)params;
	mlx_destroy_window(m->mlx_ptr, m->win_ptr);
	printf("Exit (esc).\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int cross_window(int key, void *params)
{
	(void)key;
	(void)params;
	printf("Exit (cross).\n");
	exit(EXIT_SUCCESS);
}

int toggle_minimap(int key, void *params)
{
	t_mlx *p = (t_mlx *)params;
	int bpp = 1;
	int sl = 1;
	int endian = 0;;
	int x = 0, y = 0;
	p->img_addr = (int*)mlx_get_data_addr(p->mlx_img, &bpp, &sl, &endian);
	while (++y < 100)
	{
		x = 0;
		while (++x < 200)
			p->img_addr[x * 100 + y] = 0xFFFFFF;
	}
/*	if (key == KEY_U)
	{
		if (p->mlx_img != NULL)
			mlx_destroy_image(p->mlx_ptr, p->mlx_img);
	}
	else*/
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->mlx_img, 200+key, 200+key);
	return (0);
}

int	key_stroke(int key, void *params)
{
	t_mlx *m = (t_mlx *)params;
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
		mlx_hook(m->win_ptr, 2, 0, toggle_minimap, m);
	if (key == KEY_ESC)
		esc_window(key, m);
	return (0);
}

int init_game(t_mlx *m, t_map *map)
{
	int x_res = ft_atoi(map->r_key[1]), y_res = ft_atoi(map->r_key[2]);
	
	init_mlx_struct(m);
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, x_res, y_res, "Cub3D");
	m->mlx_img = mlx_new_image(m->mlx_ptr, 200, 100);
	mlx_hook(m->win_ptr, 2, 0, key_stroke, m);
	mlx_hook(m->win_ptr, 17, 0, cross_window, m);
	mlx_loop(m->mlx_ptr);
	//mlx_key_hook(win_ptr, deal_key, (void*)&p);
	//mlx_mouse_hook(init, (&mlx_new_window)(init, 300, 300, "test"), keys.a);
	return (0);
}
