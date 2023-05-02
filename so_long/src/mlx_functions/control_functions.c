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

void	draw_player(t_game *data, int px, int py)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (data->player2.mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->player2.mlx_img);
	data->player2.mlx_img = mlx_new_image(data->mlx_ptr, 10, 10);
	data->player2.img_addr = mlx_get_data_addr(data->player2.mlx_img, \
		&data->player2.bpp, &data->player2.sl, &data->player2.endian);
	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			*(data->player2.img_addr + y * (data->player2.sl / 4) + x) = 0x80;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, \
		data->win_ptr, data->player2.mlx_img, px, py);
	data->player2_x = (float)px;
	data->player2_y = (float)py;
}
int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{

	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	//  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10

	deltaX /= pixels; // 1
	deltaY /= pixels; // 0

	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (0);
}

// void	draw_ray(t_game *data)
// {
// 	int rwidth = (1080 - 20) / data->width;

// 	data->ray_mysterio.ra = data->player2_a;
// 	data->ray_mysterio.dof = 0;
// 	float aTan = -1/tan(data->ray_mysterio.ra);
// 	if (data->ray_mysterio.ra > PI)
// 	{
// 		int calc = data->player2_y / rwidth;
// 		calc *= rwidth;
// 		data->ray_mysterio.ry = calc - 0.0001;
// 		data->ray_mysterio.rx = (data->player2_y - data->ray_mysterio.ry) * aTan + data->player2_x;
// 		data->ray_mysterio.yo = -rwidth;
// 		data->ray_mysterio.xo = - data->ray_mysterio.yo * aTan;
// 	}
// 	if (data->ray_mysterio.ra < PI)
// 	{
// 				int calc = data->player2_y / rwidth;
// 		calc *= rwidth;
// 		data->ray_mysterio.ry = calc + rwidth;
// 		data->ray_mysterio.rx = (data->player2_y - data->ray_mysterio.ry) * aTan + data->player2_x;
// 		data->ray_mysterio.yo = rwidth;
// 		data->ray_mysterio.xo = - data->ray_mysterio.yo * aTan;
// 	}
// 	if (data->ray_mysterio.ra == 0 || data->ray_mysterio.ra == PI)
// 	{
// 		data->ray_mysterio.rx = data->player2_x;
// 		data->ray_mysterio.ry = data->player2_y;
// 		data->ray_mysterio.dof = 8;
// 	}
// 	while (data->ray_mysterio.dof < 8)
// 	{
// 		data->ray_mysterio.mx = (int)(data->ray_mysterio.rx) / rwidth;
// 		data->ray_mysterio.my = (int)(data->ray_mysterio.ry) / rwidth;
// 		// data->ray_mysterio.mp = data->ray_mysterio.my * data->width-1 + data->ray_mysterio.mx;
// 		printf("rx ry mx my %i %i %i %i\n",  data->ray_mysterio.mx,  data->ray_mysterio.mx, data->ray_mysterio.mx, data->ray_mysterio.my);
// 		if ((data->ray_mysterio.mx < data->width-1 && data->ray_mysterio.mx >= 0) && (data->ray_mysterio.my < data->height-1 && data->ray_mysterio.my >= 0))
// 		{
// 			if (data->ray_mysterio.my <= 0)
// 				data->ray_mysterio.my = 1;
// 			if (data->ray_mysterio.mx <= 0)
// 				data->ray_mysterio.mx = 1;
// 			if (data->map[data->ray_mysterio.mx - 1][data->ray_mysterio.my - 1] && data->map[data->ray_mysterio.mx -1][data->ray_mysterio.my -1] == '1')
// 				data->ray_mysterio.dof = 8;
// 			else
// 				data->ray_mysterio.dof++;

// 		}
// 		else
// 		{
// 			data->ray_mysterio.rx += data->ray_mysterio.xo;
// 			data->ray_mysterio.ry += data->ray_mysterio.yo;
// 			data->ray_mysterio.dof++;
// 		}
// 	}
// 	draw_line(data->mlx_ptr, data->win_ptr, 
// 		data->player2_x, data->player2_y, 
// 		data->ray_mysterio.rx, 
// 		data->ray_mysterio.ry, 0xFFFFFF);
// }

void draw_ray(t_game *d)
{
	int i = 0;
	while (i < 640)
	{
		//init
		d->cameraX = 2 * i / (640) - 1;
		d->rayDirX = d->dirX + d->planeX * d->cameraX;
		d->rayDirY = d->dirY + d->planeY * d->cameraY;
		d->mapX = (int)d->player2_x / 64;
		d->mapY = (int)d->player2_y / 64;
		
		d->deltaDistX = (d->rayDirX == 0) ? 1e30 : fabs(1 / d->rayDirX);
		d->deltaDistY = (d->rayDirY == 0) ? 1e30 : fabs(1 / d->rayDirY);

		d->hit = 0;

		//start dda
		if (d->rayDirX < 0)
		{
			d->stepX = -1;
			d->sideDistX = (d->player2_x /64 - d->mapX) * d->deltaDistX;
		}
		else
		{
			d->stepX = 1;
			d->sideDistX = (d->mapX + 1.0 - d->player2_x/64) * d->deltaDistX;
		}
		if (d->rayDirY < 0)
		{
			d->stepY = -1;
			d->sideDistY = (d->player2_y/64 - d->mapY) * d->deltaDistY;
		}
		else
		{
			d->stepY = 1;
			d->sideDistY = (d->mapY + 1.0 - d->player2_y/64) * d->deltaDistY;
		}
		//perform dda
		while (d->hit == 0)
		{
			if (d->sideDistX < d->sideDistY)
			{
				d->sideDistX += d->deltaDistX;
				d->mapX += d->stepY;
				d->side = 0;
			}
			else
			{
				d->sideDistY += d->deltaDistY;
				d->mapY += d->stepY;
				d->side = 1;
			}
			//check wall
			if (d->map[d->mapX/64][d->mapY/64] == '1')
			{
				d->hit = 1;
				draw_line(d->mlx_ptr, d->win_ptr,d->player2_x, d->player2_y,d->mapX * 64,d->mapY * 64, 0xFFFFFF);
			}
		}
		//calc wall
		if (d->side == 0)
			d->perpWallDist = (d->sideDistX - d->deltaDistX);
		else
			d->perpWallDist = (d->sideDistY - d->deltaDistY);
		
		// int col = 0;
		// if (d->map[d->mapX/64][d->mapY/64] == '1')
		// 	col = 0xFF0000;
		// if (d->side == 1)
		// 	col /=2;
		i++;
	}
}

int	key_stroke(int key, t_game *data)
{
	int	x;
	int	y;

	x = data->player_x;
	y = data->player_y;
	if (key == KEY_W || key == KEY_UP || key == 126)
	{
		input_interpreter(data, x - 1, y);
		data->player2_y += data->player2_dy;
		data->player2_x += data->player2_dx;
	}
	if (key == KEY_S || key == KEY_DOWN || key == 125)
	{
		input_interpreter(data, x + 1, y);
		data->player2_y -= data->player2_dy;
		data->player2_x -= data->player2_dx;
	}
	if (key == KEY_A || key == KEY_LEFT || key == 123)
	{
		input_interpreter(data, x, y - 1);
		data->player2_a -= 0.1;
		if (data->player2_a < 0)
			data->player2_a += 2 * PI;
		data->player2_dx = 5 * cos(data->player2_a);
		data->player2_dy = 5 * sin(data->player2_a);
	}
	if (key == KEY_D || key == KEY_RIGHT || key == 124)
	{
		input_interpreter(data, x, y + 1);
		data->player2_a += 0.1;
		if (data->player2_a > 2 * PI)
			data->player2_a -= 2 * PI;
		data->player2_dx = 5 * cos(data->player2_a);
		data->player2_dy = 5 * sin(data->player2_a);
	}
	if (key == KEY_ESC || key == 53)
		esc_window(data);
	// printf("%i\n", key);
	draw_map(data);
	draw_player(data, data->player2_x, data->player2_y);
	draw_line(data->mlx_ptr, data->win_ptr, \
		data->player2_x, data->player2_y, \
		data->player2_x + data->player2_dx * 5, \
		data->player2_y + data->player2_dy * 5, 0xFFFFFF);
	draw_ray(data);
	return (0);
}
