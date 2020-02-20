/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_other_keys_extend.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:53:16 by dsy               #+#    #+#             */
/*   Updated: 2020/02/20 18:13:03 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_rgb_values(t_map *map)
{
	int rgb_vals1[3];
	int rgb_vals2[3];
	int i;

	i = 0;
	while (map->f_key[i] && map->c_key[i])
	{
		rgb_vals1[i] = ft_atoi(map->f_key[i]);
		rgb_vals2[i] = ft_atoi(map->c_key[i]);
		if (rgb_vals1[i] > 255 || rgb_vals2[i] > 255)
			return (0);
		i++;
	}
	return (1);
}

int	check_rgb_keys_2(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->c_key[i])
	{
		j = 0;
		if (i > 2)
			return (0);
		while (map->c_key[i][j])
		{
			if (j > 2)
				return (0);
			if (map->c_key[i][j] < '0' || map->c_key[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	if (i != 3 || !(check_rgb_values(map)))
		return (0);
	return (1);
}
