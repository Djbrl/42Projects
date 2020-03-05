/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:15:56 by dsy               #+#    #+#             */
/*   Updated: 2020/03/05 01:09:27 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int ac, char **av)
{
	t_game data;
	int		ret;

	if (ac != 2)
	{
		write(1, "Error\n[Arguments]Please only input a valid map path.\n", 53);
		return (0);
	}
	data.drawStart = 100;
	data.drawEnd = 1000;
	ret = parse_map_file(av[1], &data);
	if (ret)
		if (!(init_game(&data)))
		{
			write(1, "Error\n[MLX]Connection to MLX failed.\n", 37);
			return (0);
		}
	//if (ret != 0)
	//free_map_struct(&map);
	return (0);
}
