/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 04:39:57 by dsy               #+#    #+#             */
/*   Updated: 2020/03/08 05:24:57 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int         init_data(t_data *data)
{
    data->pos_x = 0;
    data->pos_y = 0;
    data->dirX = 0;
    data->dirY = 0;
    data->planeX = 0;
    data->planeY = 0;
    //data->map = 0;
    data->so.ptr = 0;
    data->no.ptr = 0;
    data->ea.ptr = 0;
    data->we.ptr = 0;
    data->sprite.ptr = 0;
    data->gun.ptr = 0;
    data->x_res = 0;
    data->y_res = 0;
    data->floor.set = 0;
    data->ceiling.set = 0;
    data->speed = 1;
    return (1);
}
