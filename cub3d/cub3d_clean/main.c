/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:15:56 by dsy               #+#    #+#             */
/*   Updated: 2020/02/21 23:28:08 by dsy              ###   ########.fr       */
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
	if (ret)
		init_game(&mlx, &map);
	//if (ret != 0)
	//free_map_struct(&map);
	return (0);
}
