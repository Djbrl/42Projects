/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:30:02 by dsy               #+#    #+#             */
/*   Updated: 2022/06/15 17:30:17 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_extension(char *path)
{
	int	i;

	i = 0;
	while (path[i] != '.')
		i++;
	if (path[i + 1] == 'b' && path[i + 2] == 'e'
		&& path[i + 3] == 'r' && path[i + 4] == 0)
		return (1);
	return (0);
}

int	parse_map(char *map)
{
	int file;

	file = open(map, O_RDONLY);
	if (file == -1)
		return (0);
	return (file);
}