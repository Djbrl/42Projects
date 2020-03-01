/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 06:31:50 by dsy               #+#    #+#             */
/*   Updated: 2020/03/01 16:34:50 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_map_struct(t_game *data)
{
	free_array(data->r_key);
	free_array(data->n_key);
	free_array(data->so_key);
	free_array(data->w_key);
	free_array(data->e_key);
	free_array(data->s_key);
	free_array(data->f_key);
	free_array(data->c_key);
	free_array(data->map_key);
}

int		get_rows(t_game *data)
{
	int i;

	i = 0;
	while (data->map_key[i] != 0)
		i++;
	return (i);
}

int		get_cols(t_game *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map_key[0][i] != 0)
	{
		if (data->map_key[0][i] == '1')
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
	if (!line)
		return (NULL);
	while (line[j])
	{
		if (line[j] != ' ')
			i++;
		j++;
	}
	clean_line = (char*)malloc(sizeof(char) * (i + 1));
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
