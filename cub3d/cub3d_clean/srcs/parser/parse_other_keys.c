/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_other_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:35:14 by dsy               #+#    #+#             */
/*   Updated: 2020/02/21 20:24:25 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_keys_order(t_map *map, char **loaded_file)
{
	int i;

	i = 0;
	if (ft_strncmp(map->r_key[0], "R", ft_strlen(map->r_key[0])) != 0)
		return (0);
	if (ft_strncmp(map->n_key[0], "NO", ft_strlen(map->n_key[0])) != 0)
		return (0);
	if (ft_strncmp(map->so_key[0], "SO", ft_strlen(map->so_key[0])) != 0)
		return (0);
	if (ft_strncmp(map->w_key[0], "WE", ft_strlen(map->w_key[0])) != 0)
		return (0);
	if (ft_strncmp(map->e_key[0], "EA", ft_strlen(map->e_key[0])) != 0)
		return (0);
	if (ft_strncmp(map->s_key[0], "S", ft_strlen(map->s_key[0])) != 0)
		return (0);
	if (loaded_file[6][0] != 'F')
		return (0);
	if (loaded_file[7][0] != 'C')
		return (0);
	if (loaded_file[8][0] != '1')
		return (0);
	return (1);
}

int	check_res_key(t_map *map)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (map->r_key[i])
	{
		j = 0;
		if (i > 2)
			return (0);
		while (map->r_key[i][j])
		{
			if (map->r_key[i][j] < '0' || map->r_key[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}

int	check_rgb_keys(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->f_key[i])
	{
		j = 0;
		if (i > 2)
			return (0);
		while (map->f_key[i][j])
		{
			if (j > 2)
				return (0);
			if (map->f_key[i][j] < '0' || map->f_key[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	if (i != 3 || !(check_rgb_keys_2(map)))
		return (0);
	return (1);
}

int	check_sprite_keys(t_map *map)
{
	int fd;

	if (map->n_key[2] || map->so_key[2] || map->w_key[2]
			|| map->e_key[2] || map->s_key[2])
		return (0);
	if (((fd = open(ft_strjoin("files/", map->n_key[1]), O_RDONLY)) < 0)
		|| ((fd = open(ft_strjoin("files/", map->so_key[1]), O_RDONLY)) < 0)
		|| ((fd = open(ft_strjoin("files/", map->w_key[1]), O_RDONLY)) < 0)
		|| ((fd = open(ft_strjoin("files/", map->e_key[1]), O_RDONLY)) < 0)
		|| ((fd = open(ft_strjoin("files/", map->s_key[1]), O_RDONLY)) < 0))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	check_keys_content(t_map *map, char **loaded_file)
{
	int i;

	i = 0;
	if (!(check_keys_order(map, loaded_file))
		|| !(check_res_key(map)) || !(check_sprite_keys(map))
		|| !(check_rgb_keys(map)))
		return (0);
	return (1);
}
