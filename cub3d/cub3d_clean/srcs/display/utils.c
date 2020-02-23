/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 20:46:55 by dsy               #+#    #+#             */
/*   Updated: 2020/02/23 18:22:00 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_mlx_struct(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->mlx_img = NULL;
	mlx->img_addr = NULL;
}

void	free_mlx_struct(t_mlx *mlx)
{
	if (mlx->mlx_ptr != NULL)
		free(mlx->mlx_ptr);
	if (mlx->mlx_ptr != NULL)
		free(mlx->win_ptr);
	if (mlx->mlx_ptr != NULL)
		free(mlx->mlx_img);
	if (mlx->mlx_ptr != NULL)
		free(mlx->img_addr);
}
