/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:43:27 by dsy               #+#    #+#             */
/*   Updated: 2020/05/11 18:41:13 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	drawVerLine(double x, int start, int end, int color, t_game *d)
{
    t_game  *mlx = d;
	write(1, "oop", 3);
	if (mlx->l.mlx_img == NULL)
	{	
	write(1, "oop", 3);
    	mlx->l.mlx_img = mlx_new_image(mlx->mlx_ptr, mlx->height, mlx->width);
	write(1, "oop", 3);
    	mlx->l.img_addr = (int *)mlx_get_data_addr(mlx->l.mlx_img, &mlx->l.bpp, &mlx->l.sl,
        &mlx->l.endian);
	write(1, "oop", 3);
	}
	write(1, "ook", 3);
    while (++start < end)
    {
		mlx->l.img_addr[start * mlx->height + (int)x] = color;
    }
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->l.mlx_img, 0, 0);
	write(1, "oop", 3);
    return (0);
}
