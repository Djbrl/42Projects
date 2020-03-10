/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:23:12 by dsy               #+#    #+#             */
/*   Updated: 2020/03/10 22:41:33 by dsy              ###   ########.fr       */
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
	data->hit = 0;
}

void	calculate_step(t_game *d)
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
		if (d->map_key[d->mapX][d->mapY] > '0')
			d->hit = 1;
	}
	if (d->side == 0)
		d->perpWallDist = (d->mapX - d->pos_x + (1 - d->stepX) / 2) / d->rayDirX;
	else
		d->perpWallDist = (d->mapY - d->pos_y + (1 - d->stepY) / 2) / d->rayDirY;
}

void	calculate_line_height(t_game *d)
{
	if (d->perpWallDist <= 0)
		d->perpWallDist = 1;
	d->lineHeight = (int)(d->y_res / d->perpWallDist);
	d->drawStart = d->lineHeight / 2 + d->y_res / 2;
	if (d->drawStart < 0)
		d->drawStart = 0;
	d->drawEnd = d->lineHeight / 2 + d->y_res / 2;
	if (d->drawEnd >= d->y_res)
		d->drawEnd = d->y_res - 1;
}

void	choose_wall_color(t_game *d)
{
	d->red = 0xFF0000;
	d->green = 0x00FF00;
	d->blue = 0x0000FF;
	d->yellow = 0xFFFF00;
	if (d->map_key[d->mapX][d->mapY] == '1')
		d->color = d->red;
	if (d->side == 1)
		d->color /= 2;
	printf("line to draw : x %f, start %i end %i, color %i\n", d->pos_x, d->drawStart, d->drawEnd, d->color);
	drawVerLine(d->pos_x, 0, d->drawEnd, d->color, d);
}

void	read_keys(int key, t_game *d)
{
	if (key == KEY_UP)
	{
		if (d->map_key[(int)(d->pos_x + d->dirX)][(int)(d->pos_y)] == '0')
			d->pos_x += d->dirX;
		if (d->map_key[(int)(d->pos_x)][(int)(d->pos_y + d->dirY)] == '0')
			d->pos_y += d->dirY;
	}
	//move backwards if no wall behind you
	if (key == KEY_DOWN)
	{
		if (d->map_key[(int)(d->pos_x - d->dirX)][(int)(d->pos_y)] == '0') 
			d->pos_x -= d->dirX;
		if (d->map_key[(int)(d->pos_x)][(int)(d->pos_y - d->dirY)] == '0')
			d->pos_y -= d->dirY;
	}
	//rotate to the right
	if (key == KEY_RIGHT)
	{
		//both camera direction and camera plane must be rotated
		d->oldDirX = d->dirX;
		d->dirX = d->dirX;
		d->dirY = d->oldDirX;
		d->oldPlaneX = d->planeX;
		d->planeX = d->planeX - d->planeY;
		d->planeY = d->oldPlaneX + d->planeY;
	}
	//rotate to the left
	if (key == KEY_LEFT)
	{
		//both camera direction and camera plane must be rotated
		d->oldDirX = d->dirX;
		d->dirX = d->dirX - d->dirY;
		d->dirY = d->oldDirX + d->dirY;
		d->oldPlaneX = d->planeX;
		d->planeX = d->planeX - d->planeY;
		d->planeY = d->oldPlaneX + d->planeY;
	}
}

int		raycasting(int key, void *params)
{
	int done;
	int i;
	t_game *d;

	d = (t_game *)params;
	done = 0;
	i = 0;
	setup_raycasting_var(d);
	while (!done)
	{
		i = 0;
		while (i < d->y_res)
		{
			d->cameraX = 2 * i / (double)d->col - 1;
			d->rayDirX = d->dirX + d->planeX * d->cameraX;
			d->rayDirY = d->dirY + d->planeY * d->cameraX;
			d->mapX = (int)d->pos_x;
			d->mapY = (int)d->pos_y;
			d->deltaDistX = fabs(1 / d->rayDirX);
			d->deltaDistY = fabs(1 / d->rayDirY);
			calculate_step(d);
			printf("state : \nposx : %f\nposy : %f\ncase : %c\n(mapx-y : %i-%i)\nstepx : %i\nstepy : %i\ncurrent col %i\n\n", d->pos_x, d->pos_y, d->map_key[d->mapX][d->mapY], d->mapX, d->mapY, d->stepX, d->stepY, i);
			perform_dda(d);
			calculate_line_height(d);
			choose_wall_color(d);
	//		read_keys(key, d);
			i++;
		}
	}
	return (1);
}
