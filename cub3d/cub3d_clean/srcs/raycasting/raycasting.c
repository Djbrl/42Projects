/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:33:10 by dsy               #+#    #+#             */
/*   Updated: 2020/03/11 05:10:21 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int     *get_texture(t_game *data, t_ray *ray)
{
	if (ray->side == 0 && ray->rdir_x < 0)
		return (data->so.img_addr);
	else if (ray->side == 0 && ray->rdir_x > 0)
		return (data->no.img_addr);
	else if (ray->side == 1 && ray->rdir_y > 0)
		return (data->we.img_addr);
	else
		return (data->ea.img_addr);
}

int     get_size(t_game *data, t_ray *ray)
{
	if (ray->side == 0 && ray->rdir_x < 0)
		return (data->so.height);
	else if (ray->side == 0 && ray->rdir_x > 0)
		return (data->no.height);
	else if (ray->side == 1 && ray->rdir_y > 0)
		return (data->we.height);
	else
		return (data->ea.height);
}

void    init_ray(t_ray *ray, t_game *data)
{
	ray->map_x = (int)data->pos_x;
	ray->map_y = (int)data->pos_y;
	ray->camera_x = 2 * data->x / (double)data->width - 1;
	ray->rdir_x = data->dirX + data->planeX * ray->camera_x;
	ray->rdir_y = data->dirY + data->planeY * ray->camera_x;
	ray->d_dist_x = fabs(1 / ray->rdir_x);
	ray->d_dist_y = fabs(1 / ray->rdir_y);
	ray->hit = 0;
	//ray->sprite = 0;
}

void    init_dist(t_ray *ray, t_game *data)
{
	if (ray->rdir_x < 0 && (ray->step_x = -1) == -1)
		ray->dist_x = (data->pos_x - ray->map_x) * ray->d_dist_x;
	else
	{
		ray->dist_x = (-data->pos_x + 1 + ray->map_x) * ray->d_dist_x;
		ray->step_x = 1;
	}
	if (ray->rdir_y < 0 && (ray->step_y = -1) == -1)
		ray->dist_y = (data->pos_y - ray->map_y) * ray->d_dist_y;
	else
	{
		ray->dist_y = (-data->pos_y + 1 + ray->map_y) * ray->d_dist_y;
		ray->step_y = 1;
	}
}

void	draw_background(t_game *data)
{
	int     i;

	i = 0;
	data->x = -1;
	//data->to_draw = 0;
	while (i < (data->height * data->width))
	{
		if (i < (data->height * data->width) / 2)
			data->l.img_addr[i] = (data->floor.R << 16) 
				+ (data->floor.G << 8) + data->floor.B;
		else
			data->l.img_addr[i] = (data->ceiling.R << 16) 
				+ (data->ceiling.G << 8) + data->ceiling.B;
		i++;
	}

}

int     dda(t_ray *ray, t_game *data)
{
	while (ray->hit == 0)
	{
		if (ray->dist_x < ray->dist_y)
		{
			ray->dist_x += ray->d_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->dist_y += ray->d_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map_key[ray->map_x][ray->map_y] == '2')
			return (0);
		//	if (!(add_sprite(data, ray)))
		if (data->map_key[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
	return (1);
}

void    get_wall_height(t_ray *ray, t_game *data)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->map_x - data->pos_x + (1 -
					ray->step_x) / 2) / ray->rdir_x;
	else
		ray->wall_dist = (ray->map_y - data->pos_y + (1 -
					ray->step_y) / 2) / ray->rdir_y;
	ray->wall_height = (int)((float)data->height / (float)ray->wall_dist);
	ray->lower_pix = (int)(-ray->wall_height / 2 + data->height / 2);
	if (ray->lower_pix < 0)
		ray->lower_pix = 0;
	ray->higher_pix = ray->wall_height / 2 + data->height / 2;
	if (ray->higher_pix > data->height)
		ray->higher_pix = data->height - 1;
}

int         draw_pix_column(t_ray *ray, t_game *data)
{
	double  tex_x;
	double  y;
	int     size;
	int     *texture;
	int     diff;

	diff = 0;
	if (ray->higher_pix <= ray->wall_height)
		diff = (ray->wall_height - ray->higher_pix) / 2;
	texture = get_texture(data, ray);
	size = get_size(data, ray);
	y = (double)size / (double)ray->wall_height;
	tex_x = data->pos_x + ray->wall_dist * ray->rdir_x;
	if (ray->side == 0)
		tex_x = data->pos_y + ray->wall_dist * ray->rdir_y;
	tex_x = tex_x - floor(tex_x);
	while (ray->lower_pix < ray->higher_pix)
	{
		data->l.img_addr[(int)data->x + (ray->lower_pix * data->width)] =
			texture[(int)(tex_x * (double)size - 1)
			+ ((int)((ray->higher_pix - ray->lower_pix + diff) * y) * (size))];
		ray->lower_pix++;
	}
	return (1);
}

void	init (t_ray **ray)
{
	ray[0] = malloc(sizeof(t_ray));
}

void    clear_ray(t_ray **ray)
{
    free(*ray);
}

int		raycasting(t_game *d)
{
	t_ray *ray;
	init(&ray);
	d->l.mlx_img = mlx_new_image(d->mlx_ptr, d->width, d->height);
	d->l.img_addr = (int *)mlx_get_data_addr(d->l.mlx_img, &d->l.bpp, &d->l.sl, &d->l.endian);
	draw_background(d);
	while (++d->x < d->width)
	{
		init_ray(ray, d);
		init_dist(ray, d);
		if (!(dda(ray, d)))
			return (0);
		get_wall_height(ray, d);
		draw_pix_column(ray, d);
	}
	clear_ray(&ray);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->l.mlx_img, 0, 0);
	free(d->l.mlx_img);
	return (0);
}
