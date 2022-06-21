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
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
}

void	free_mlx_struct(t_game *data)
{
	(void)data;
	if (data->map != NULL)
		free_split(data->map);
	if (data->wall != NULL)
		mlx_destroy_image(data->mlx_ptr, data->wall);
	if (data->path != NULL)
		mlx_destroy_image(data->mlx_ptr, data->path);
	if (data->player != NULL)
		mlx_destroy_image(data->mlx_ptr, data->player);
	if (data->exit != NULL)
		mlx_destroy_image(data->mlx_ptr, data->exit);
	if (data->item != NULL)
		mlx_destroy_image(data->mlx_ptr, data->item);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
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