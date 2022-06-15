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
	ft_putstr(YLW_COLOR);
	printf("Exit (esc).\n");
	ft_putstr(END_COLOR);
	exit(EXIT_SUCCESS);
	return (0);
}

int	cross_window(int key, void *params)
{
	(void)key;
	(void)params;
	ft_putstr(YLW_COLOR);
	ft_putstr("Exit (cross).\n");
	ft_putstr(END_COLOR);
	exit(EXIT_SUCCESS);
}

int	key_stroke(int key, void *params)
{
	t_game	*data;

	data = (t_game *)params;
	if (key == KEY_W)
		printf("Pressed W.\n");
	if (key == KEY_S)
		printf("Pressed S.\n");
	if (key == KEY_A)
		printf("Pressed A.\n");
	if (key == KEY_D)
		printf("Pressed D.\n");
	if (key == KEY_ESC)
		esc_window(key, data);
	printf("key : %i\n", key);
	return (0);
}
