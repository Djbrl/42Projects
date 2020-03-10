/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:43:27 by dsy               #+#    #+#             */
/*   Updated: 2020/03/10 19:30:59 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	drawVerLine(double x, int start, int end, int color, t_game *d)
{
    t_game  *mlx = d;
//link to new  img struct
    mlx->mlx_img = mlx_new_image(mlx->mlx_ptr, mlx->y_res, mlx->x_res);
    mlx->img_addr = (int *)mlx_get_data_addr(mlx->mlx_img, &mlx->bpp, &mlx->sl,
        &mlx->endian);
    while (++start < end)
    {
		mlx->img_addr[start * mlx->y_res + (int)x] = color;
    }
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->mlx_img, 0, 0);
    return (0);
}
