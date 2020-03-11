/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:15:56 by dsy               #+#    #+#             */
/*   Updated: 2020/03/11 04:32:42 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int ac, char **av)
{
	t_game data;
	int		ret;

	if (ac != 2)
	{
		write(1, "Error\n[Input]Please only input a valid map path.\n", 49);
		return (0);
	}
	if (!(check_map_extension(av[1])))
	{
		write(1, "Error\n[Input]Bad map extension.\n", 32);
		return (0);
	}
	ret = parse_map_file(av[1], &data);
	if (ret)
		if (!(init_game(&data)))
		{
			write(1, "Error\n[MLX]Connection to MLX failed.\n", 37);
			return (0);
		}
	write(1, "o", 1);
	//if (ret != 0)
	//free_map_struct(&map);
	return (0);
}
