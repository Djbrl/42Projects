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

int	esc_window(t_game *data)
{
	return (exit_game("Exit (esc).\n", data));
}

int	cross_window(t_game *data)
{
	return (exit_game("Exit (cross).\n", data));
}

static void	show_score(int score, int mode)
{
	if (mode == 1)
	{
		ft_putstr(GREEN_COLOR);
		ft_putstr("Score : ");
		ft_putnbr(score);
		ft_putstr("\n");
		ft_putstr(END_COLOR);
	}
	else
	{
		ft_putstr(YLW_COLOR);
		ft_putstr("Final Score : ");
		ft_putnbr(score);
		ft_putstr("\n");
		ft_putstr(END_COLOR);
	}
}

void	input_interpreter(t_game *data, int x, int y)
{
	if (data->map[x][y] != '1')
	{
		if (data->map[x][y] == 'E' && data->items_left < 1)
		{
			show_score(data->score, 2);
			exit_game("gg!\n", data);
		}
		else if (data->map[x][y] == 'E' && data->items_left > 0)
			ft_putstr("you can't exit yet!\n");
		else
		{	
			show_score(data->score, 1);
			data->score++;
			if (data->map[x][y] == 'C')
				data->items_left--;
			data->map[x][y] = 'P';
			data->map[data->player_x][data->player_y] = '0';
			draw_map(data);
		}
	}
	else
		ft_putstr("you can't go there!\n");
}

void	draw_player(t_game *data, int px, int py)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (data->player2.mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->player2.mlx_img);
	data->player2.mlx_img = mlx_new_image(data->mlx_ptr, 10, 10);
	data->player2.img_addr = mlx_get_data_addr(data->player2.mlx_img, \
		&data->player2.bpp, &data->player2.sl, &data->player2.endian);
	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			*(data->player2.img_addr + y * (data->player2.sl / 4) + x) = 0x80;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, \
		data->win_ptr, data->player2.mlx_img, px, py);
	data->player2_x = (float)px;
	data->player2_y = (float)py;
}

int	key_stroke(int key, t_game *data)
{
	int	x;
	int	y;

	x = data->player_x;
	y = data->player_y;
	if (key == KEY_W || key == KEY_UP)
	{
		input_interpreter(data, x - 1, y);
		data->player2_y -= data->player2_dy;
		data->player2_x -= data->player2_dx;
	}
	if (key == KEY_S || key == KEY_DOWN)
	{
		input_interpreter(data, x + 1, y);
		data->player2_y += data->player2_dy;
		data->player2_x += data->player2_dx;
	}
	if (key == KEY_A || key == KEY_LEFT)
	{
		input_interpreter(data, x, y - 1);
		data->player2_a -= 0.1;
		if (data->player2_a < 0)
			data->player2_a += 2 * PI;
		data->player2_dx = 5 * cos(data->player2_a);
		data->player2_dy = 5 * sin(data->player2_a);
	}
	if (key == KEY_D || key == KEY_RIGHT)
	{
		input_interpreter(data, x, y + 1);
		data->player2_a += 0.1;
		if (data->player2_a > 2 * PI)
			data->player2_a -= 2 * PI;
		data->player2_dx = 5 * cos(data->player2_a);
		data->player2_dy = 5 * sin(data->player2_a);
	}
	if (key == KEY_ESC)
		esc_window(data);
	draw_map(data);
	draw_player(data, data->player2_x, data->player2_y);
	return (0);
}
