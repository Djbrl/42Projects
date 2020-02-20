/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:15:56 by dsy               #+#    #+#             */
/*   Updated: 2020/02/20 18:24:33 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int ac, char **av)
{
	t_map map;
	int i;

	if (ac != 2)
	{
		write(1, "Error\nPlease only input a valid map path.\n", 42);
		return (0);
	}
	i = parse_map_file(av[1], &map);
	if (i != 0)
		free_map_struct(map);
	return (0);
}
