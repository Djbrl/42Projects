/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:11:10 by dsy               #+#    #+#             */
/*   Updated: 2020/07/08 01:22:37 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	esc_window(int key, void *params)
{
	t_game	*data;

	(void)key;
	data = (t_game *)params;
	if (data->mlx_ptr != NULL && data->win_ptr != NULL)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (exit_game("Exit (esc).\n", data));
}

int	cross_window(int key, void *params)
{
	t_game	*data;

	(void)key;
	data = (t_game *)params;
	return (exit_game("Exit (cross).\n", data));
}

int	key_stroke(int key, void *params)
{
	t_game	*data;

	data = (t_game *)params;
	int x = data->player_x;
	int y = data->player_y;
	if (key == KEY_W)
	{
		printf("Pressed W.\n");
		if (data->map[x - 1][y] != '1' )
		{
			data->map[x - 1][y] = 'P';
			data->map[x][y] = '0';
			draw_map(data);
		}
		else
			printf("You can't go there!\n");
	}
	if (key == KEY_S)
	{
		printf("Pressed S.\n");
		if (data->map[x + 1][y] != '1' )
		{
			data->map[x + 1][y] = 'P';
			data->map[x][y] = '0';
			draw_map(data);
		}
		else
			printf("You can't go there!\n");
	}
	if (key == KEY_A)
	{
		printf("Pressed A.\n");
		if (data->map[x][y - 1] != '1' )
		{
			data->map[x][y - 1] = 'P';
			data->map[x][y] = '0';
			draw_map(data);
		}
		else
			printf("You can't go there!\n");

	}
	if (key == KEY_D)
	{
		printf("Pressed D.\n");
		if (data->map[x][y + 1] != '1' )
		{
			data->map[x][y + 1] = 'P';
			data->map[x][y] = '0';
			draw_map(data);
		}
		else
			printf("You can't go there!\n");
	}
	if (key == KEY_ESC)
	{
		esc_window(key, data);
	}
	return (0);
}
