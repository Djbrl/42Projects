/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_other_keys_extend.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:53:16 by dsy               #+#    #+#             */
/*   Updated: 2020/02/24 19:19:29 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		adjust_resolution(t_game *data)
{
	int res_values[2];

	if (!data->r_key[1] || !data->r_key[2])
		return (0);
	res_values[0] = ft_atoi(data->r_key[1]);
	res_values[1] = ft_atoi(data->r_key[2]);
	if (res_values[0] < 200 || res_values[1] < 200)
	{
		free(data->r_key[1]);
		free(data->r_key[2]);
		data->r_key[1] = ft_strdup("300");
		data->r_key[2] = ft_strdup("200");
	}
	if (res_values[0] > 2560)
	{
		free(data->r_key[1]);
		data->r_key[1] = ft_strdup("2560");
	}
	if (res_values[1] > 1440)
	{
		free(data->r_key[2]);
		data->r_key[2] = ft_strdup("1440");
	}
	return (1);
}

int		check_rgb_values(t_game *data)
{
	int rgb_vals1[3];
	int rgb_vals2[3];
	int i;

	i = 0;
	while (data->f_key[i] && data->c_key[i])
	{
		rgb_vals1[i] = ft_atoi(data->f_key[i]);
		rgb_vals2[i] = ft_atoi(data->c_key[i]);
		if (rgb_vals1[i] > 255 || rgb_vals2[i] > 255)
			return (0);
		i++;
	}
	return (1);
}

int		check_rgb_keys_2(t_game *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->c_key[i])
	{
		j = 0;
		if (i > 2)
			return (0);
		while (data->c_key[i][j])
		{
			if (j > 2)
				return (0);
			if (data->c_key[i][j] < '0' || data->c_key[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	if (i != 3 || !(check_rgb_values(data)))
		return (0);
	return (1);
}
