/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:25:41 by dsy               #+#    #+#             */
/*   Updated: 2022/06/18 01:25:43 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map_shape(char **map)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != (size_t)tmp)
			return (0);
		tmp = ft_strlen(map[i]);
		i++;
	}
	return (1);
}

static inline int	ftn_check_map_content(char **map, int width)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][width] != '1')
			return (0);
		while (map[i][j])
		{
			if (map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'E' \
				&& map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_map_content(char **map)
{
	int	i;
	int	j;
	int	height;
	int	width;

	if (!check_map_shape(map))
		return (0);
	height = get_map_heigth(map) - 1;
	width = get_map_width(map) - 1;
	i = 0;
	j = -1;
	while (map[0][++j])
		if (map[0][j] != '1')
			return (0);
	while (map[height][i])
	{
		if (map[height][i] != '1')
			return (0);
		i++;
	}
	if (!ftn_check_map_content(map, width))
		return (0);
	return (1);
}

static inline void	ftn_check_map(char map, int *p, int *c, int *e)
{
	if (map == 'P')
		*p = *p + 1;
	if (map == 'C')
		*c = *c + 1;
	if (map == 'E')
		*e = *e + 1;
}

int	check_map_config(char **map)
{
	int	i;
	int	j;
	int	p_count;
	int	c_count;
	int	e_count;

	i = 0;
	j = 0;
	p_count = 0;
	c_count = 0;
	e_count = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			ftn_check_map(map[i][j], &p_count, &c_count, &e_count);
			j++;
		}
		j = 0;
		i++;
	}
	if (!c_count || !p_count || !e_count || p_count > 1 \
		|| !check_map_content(map))
		return (0);
	return (1);
}
