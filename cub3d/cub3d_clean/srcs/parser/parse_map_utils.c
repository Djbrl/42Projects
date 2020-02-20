/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 06:31:50 by dsy               #+#    #+#             */
/*   Updated: 2020/02/20 14:43:40 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_map_struct(t_map map)
{
	free_array(map.r_key);
	free_array(map.n_key);
	free_array(map.so_key);
	free_array(map.w_key);
	free_array(map.e_key);
	free_array(map.s_key);
	free_array(map.f_key);
	free_array(map.c_key);
	free_array(map.map_key);
}

int		get_rows(t_map *map)
{
	int i;

	i = 0;
	while (map->map_key[i] != 0)
		i++;
	return (i);
}

int		get_cols(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->map_key[0][i] != 0)
	{
		if (map->map_key[0][i] == '1')
			j++;
		i++;
	}
	return (j - 1);
}

char	*remove_spaces(char *line)
{
	char	*clean_line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (line[j])
	{
		if (line[j] != ' ')
			i++;
		j++;
	}
	clean_line = (char*)malloc(sizeof(char) * i);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			clean_line[j++] = line[i];
		i++;
	}
	clean_line[j] = 0;
	return (clean_line);
}
