/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:09:30 by dsy               #+#    #+#             */
/*   Updated: 2020/02/15 22:33:10 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/keys.h"
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

int	ft_print_pix(int key, void *params)
{
	t_params *p = (t_params *)params;
	mlx_pixel_put(p->mlx_ptr, p->win_ptr, key, key, 0x2FFF6A);
	printf("key %d\n", key);
	if (key == KEY_ESC)
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	return (0);
}

int ft_images(int key, void *params)
{
	t_params *p = (t_params *)params;

	int bpp = 1;
	int sl = 1;
	int endian = 0;;
	int x = 0, y = 0;
	p->img_addr = (int*)mlx_get_data_addr(p->mlx_img, &bpp, &sl, &endian);
	while (++y < 600)
	{
		x = 0;
		while (++x < 600)
			p->img_addr[x * 600 + y] = 0xFFFFFF;
	}
	//mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->mlx_img, 200, 200);
	//mlx_destroy_image(p->mlx_ptr, p->mlx_img);
	return (0);
}

int	ft_destroy_window(int key, void *params)
{
	t_params *p = (t_params *)params;
	mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	return (0);
}
int main()
{
	void *mlx_ptr; //id connexion serv
	void *win_ptr; //id fenetre
	t_params p;

	int colors = 0x2FFF6A, x = 300, y = 300;

	p.mlx_ptr = mlx_init();
	p.win_ptr = mlx_new_window(p.mlx_ptr, 600, 600, "cub3d");
	p.mlx_img = mlx_new_image(p.mlx_ptr, 200, 100);

	
	//mlx_hook(p.win_ptr, 2, 0, ft_print_pix, &p);
//	mlx_hook(p.win_ptr, 2, 0, ft_images, &p);
	mlx_loop(p.mlx_ptr);
	//mlx_key_hook(win_ptr, deal_key, (void*)&p);
	//mlx_mouse_hook(init, (&mlx_new_window)(init, 300, 300, "test"), keys.a);
	return (0);
}
