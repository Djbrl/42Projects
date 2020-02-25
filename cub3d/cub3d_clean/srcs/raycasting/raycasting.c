/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:23:12 by dsy               #+#    #+#             */
/*   Updated: 2020/02/25 21:06:39 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	setup_raycasting_var(t_game *data)
{
	data->dirX = -1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0.66;
	data->time = 0;
	data->cameraX = 0;
	data->rayDirX = 0;
	data->rayDirY = 0;
	hit = 0;
}

void	calculate_step(t_game *d);
{
	if (d->rayDirX < 0)
	{
		d->stepX = -1;
		d->sideDistX = (d->pos_x - d->mapX) * d->deltaDistX;
	}
	else
	{
		d->stepX = 1;
		d->sideDistX = (d->mapX + 1.0 - d->pos_x) * d->deltaDistX;
	}
	if (d->rayDirY < 0)
	{
		d->stepY = -1;
		d->sideDistY = (d->pos_y - d->mapY) * d->deltaDistY;
	}
	else
	{
		d->stepY = 1;
		d->sideDistY = (d->mapY + 1.0 - d->pos_y) * d->deltaDistY;
	}
}

void		perform_dda(t_game *d)
{
	while (d->hit == 0)
	{
		if (d->sideDistX < d->sideDistY)
		{
			d->sideDistX += d->deltaDistX;
			d->mapX += d->stepX;
			d->side = 0;
		}
		else
		{
			d->sideDistY += d->deltaDistY;
			d->mapY += d->stepY;
			d->side = 1;
		}
		if (d->map_key[mapX][mapY] > '0')
			hit = 1;
	}
	if (d->side == 0)
		d->perpWallDist = (d->mapX - d->pos_x + (1 - d->stepX) / 2) / d->rayDirX;
	else
		d->perpWallDist = (d->mapY - d->pos_y + (1 - d->stepY) / 2) / d->rayDirY;
}

void	calculate_line_height(t_game *d)
{
	d->lineHeight = (int)(d->y_res / d->perpWalldist);
	d->drawStart = d->lineHeight / 2 + d->y_res / 2;
	if (d->drawStart < 0)
		d->drawStart = 0;
	d->drawEnd = d->lineHeight / 2 + d->y_res / 2;
	if (d->drawEnd >= y_res)
		drawEnd = h - 1;
}

void	choose_wall_color(t_game *d)
{
	d->red = 0xFF0000;
	d->green = 0x00FF00;
	d->blue = 0x0000FF;
	d->yellow = 0xFFFF00;
	if (d->map_key[mapX][mapY] == '1')
		d->color = d->red;
	if (side == 1)
		color /= 2;
	//drawVerLine(x, drawStart, drawEnd, color);
	//continue here
}

int		raycasting(t_game *d)
{
	int done;
	int i;

	done = 0;
	i = 0;
	setup_raycasting_var(d);
	while (!done)
	{
		while (i < data->col)
		{
			d->cameraX = 2 * i / (double)d->col - 1;
			d->rayDirX = d->dirX + d->planeX * d->cameraX;
			d->rayDirY = d->dirY + d->planeY * d->cameraX;
			d->mapX = (int)d->pos_x;
			d->mapY = (int)d->pos_y;
			d->deltaDistX = (d->rayDirY == 0)
				? 0 : ((d->rayDirX == 0) ? 1 : abs(1 / d->rayDirX));
			d->deltaDistY = (d->rayDirX == 0)
				? 0 : ((d->rayDirY == 0) ? 1 : abs(1 / d->rayDirY));
			calculate_step(d);
			perform_dda(d);
			calculate_line_height(t_game *d)
			i++;
		}
	}
	return (1);
}
