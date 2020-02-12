/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:09:30 by dsy               #+#    #+#             */
/*   Updated: 2020/02/12 22:23:20 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/keys.h"
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

int deal_key(int key, void *p)
{
	write(1, "x", 1);
	mlx_pixel_put(p.mlx_ptr, p.win_ptr, 200, 200, 0xFFFFFF);
	return (0);
}

int main()
{
	void *mlx_ptr; //id connexion serv
	void *win_ptr; //id fenetre
	t_params p;

	int colors = 0x2FFF6A, x = 300, y = 300;
	
	p.mlx_ptr = mlx_init(); 							//return identifier for connexion to graphical server
	p.win_ptr = mlx_new_window(mlx_ptr, 600, 600, "cub3d"); 	//return id fenetre
	while (x++ < 350)
		mlx_pixel_put(p.mlx_ptr, p.win_ptr, x, y, colors);
	mlx_key_hook(win_ptr, deal_key, (void*)p);
	mlx_loop(mlx_ptr);							 			//obligatory mlx_loop to run window
	//mlx_mouse_hook(init, (&mlx_new_window)(init, 300, 300, "test"), keys.a);
	return (0);
}
