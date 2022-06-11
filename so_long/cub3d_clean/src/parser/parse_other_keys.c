/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_other_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:35:14 by dsy               #+#    #+#             */
/*   Updated: 2020/05/11 19:47:03 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_keys_order(t_game *data, char **loaded_file)
{
	int i;

	i = 0;
	if (ft_strncmp(data->r_key[0], "R", ft_strlen(data->r_key[0])) != 0)
		return (0);
	if (ft_strncmp(data->n_key[0], "NO", ft_strlen(data->n_key[0])) != 0)
		return (0);
	if (ft_strncmp(data->so_key[0], "SO", ft_strlen(data->so_key[0])) != 0)
		return (0);
	if (ft_strncmp(data->w_key[0], "WE", ft_strlen(data->w_key[0])) != 0)
		return (0);
	if (ft_strncmp(data->e_key[0], "EA", ft_strlen(data->e_key[0])) != 0)
		return (0);
	if (ft_strncmp(data->s_key[0], "S", ft_strlen(data->s_key[0])) != 0)
		return (0);
	if (loaded_file[6][0] != 'F')
		return (0);
	if (loaded_file[7][0] != 'C')
		return (0);
	if (loaded_file[8][0] != '1')
	{
		data->error = 3;
		return (0);
	}
	return (1);
}

int	check_res_key(t_game *data)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (data->r_key[i])
	{
		j = 0;
		if (i > 2)
			return (0);
		while (data->r_key[i][j])
		{
			if (data->r_key[i][j] < '0' || data->r_key[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	if (i != 3)
	{
		data->error = 1;
		return (0);
	}
	return (1);
}

int	check_rgb_keys(t_game *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->f_key[i])
	{
		j = 0;
		if (i > 2)
			return (0);
		while (data->f_key[i][j])
		{
			if (j > 2)
				return (0);
			if (data->f_key[i][j] < '0' || data->f_key[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	if (i != 3 || !(check_rgb_keys_2(data)))
	{
		data->error = 1;
		return (0);
	}
	return (1);
}

int	check_sprite_keys(t_game *data)
{
	int fd;

	if (data->n_key[2] || data->so_key[2] || data->w_key[2]
			|| data->e_key[2] || data->s_key[2])
		return (0);
	if (((fd = open(ft_strjoin("data/", data->n_key[1]), O_RDONLY)) < 0)
		|| ((fd = open(ft_strjoin("data/", data->so_key[1]), O_RDONLY)) < 0)
		|| ((fd = open(ft_strjoin("data/", data->w_key[1]), O_RDONLY)) < 0)
		|| ((fd = open(ft_strjoin("data/", data->e_key[1]), O_RDONLY)) < 0)
		|| ((fd = open(ft_strjoin("data/", data->s_key[1]), O_RDONLY)) < 0))
	{
		close(fd);
		data->error = 1;
		return (0);
	}
	close(fd);
	return (1);
}

int	check_keys_content(t_game *data, char **loaded_file)
{
	int i;

	i = 0;
	if (!(check_keys_order(data, loaded_file))
		|| !(check_res_key(data)) || !(check_sprite_keys(data))
		|| !(check_rgb_keys(data)))
		return (0);
	return (1);
}
