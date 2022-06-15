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

int	exit_error(char *err)
{
	ft_putstr(RED_COLOR);
	ft_putstr(err);
	ft_putstr(END_COLOR);
	return (0);
}

void	init_game_struct(t_game *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->l.mlx_img = NULL;
	data->l.img_addr = NULL;
}

void	free_mlx_struct(t_game *data)
{
	if (data->mlx_ptr != NULL)
		free(data->mlx_ptr);
	if (data->mlx_ptr != NULL)
		free(data->win_ptr);
	if (data->mlx_ptr != NULL)
		free(data->l.mlx_img);
	if (data->mlx_ptr != NULL)
		free(data->l.img_addr);
}
