/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:27:59 by dsy               #+#    #+#             */
/*   Updated: 2022/06/15 17:28:18 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_error(char *err, t_game *data)
{
	ft_putstr(RED_COLOR);
	ft_putstr(err);
	ft_putstr(END_COLOR);
	free_mlx_struct(data);
	exit(EXIT_FAILURE);
	return (0);
}

int	exit_game(char *msg, t_game *data)
{
	ft_putstr(YLW_COLOR);
	ft_putstr(msg);
	ft_putstr(END_COLOR);
	free_mlx_struct(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	init_game_struct(t_game *data)
{
	data->map = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->wall.mlx_img = NULL;
	data->player.mlx_img = NULL;
	data->player2.mlx_img = NULL;
	data->player2.img_addr = NULL;
	data->player2_x = 0;
	data->player2_y = 0;
	data->player2_dx = 0;
	data->player2_dy = 0;
	data->player2_a = 0;
	data->path.mlx_img = NULL;
	data->item.mlx_img = NULL;
	data->exit.mlx_img = NULL;
	data->wall.img_addr = NULL;
	data->player.img_addr = NULL;
	data->exit.img_addr = NULL;
	data->path.img_addr = NULL;
	data->item.img_addr = NULL;
}

void	free_mlx_struct(t_game *data)
{
	(void)data;
	if (data->map != NULL)
		free_split(data->map);
	if (data->wall.mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->wall.mlx_img);
	if (data->path.mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->path.mlx_img);
	if (data->player.mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->player.mlx_img);
	if (data->exit.mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->exit.mlx_img);
	if (data->item.mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->item.mlx_img);
	if (data->mlx_ptr != NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
	}
}

void	free_split(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}
