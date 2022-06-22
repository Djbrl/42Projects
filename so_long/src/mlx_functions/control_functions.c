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

int	key_stroke(int key, t_game *data)
{
	int	x;
	int	y;

	x = data->player_x;
	y = data->player_y;
	if (key == KEY_W || key == KEY_UP)
		input_interpreter(data, x - 1, y);
	if (key == KEY_S || key == KEY_DOWN)
		input_interpreter(data, x + 1, y);
	if (key == KEY_A || key == KEY_LEFT)
		input_interpreter(data, x, y - 1);
	if (key == KEY_D || key == KEY_RIGHT)
		input_interpreter(data, x, y + 1);
	if (key == KEY_ESC)
		esc_window(data);
	draw_map(data);
	return (0);
}
