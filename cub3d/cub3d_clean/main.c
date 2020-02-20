/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:15:56 by dsy               #+#    #+#             */
/*   Updated: 2020/02/20 20:56:23 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int ac, char **av)
{
	t_map	map;
	t_mlx	mlx;
	int		ret;

	if (ac != 2)
	{
		write(1, "Error\nPlease only input a valid map path.\n", 42);
		return (0);
	}
	ret = parse_map_file(av[1], &map);
	init_window(&mlx);
	//if (ret != 0)
	//	free_map_struct(data.map);
	return (0);
}
