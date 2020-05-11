/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 06:31:50 by dsy               #+#    #+#             */
/*   Updated: 2020/05/11 18:41:18 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	report_error(t_game *data)
{
	if (data->error == 0)
		write(1, "Error\n[Path]Couldn't find map file.\n", 36);
	if (data->error == 1)
		write(1, "Error\n[Bad Map Keys] Map Keys are incorrect.\n", 45);
	if (data->error == 2)
		write(1, "Error\n[Bad Map Keys] Missing or extra keys.\n", 45);
	if (data->error == 3)
		write(1, "Error\n[Invalid map] Invalid map borders.\n", 42);
	if (data->error == 4)
		write(1, "Error\n[Invalid map] Invalid number of POV in the map.\n", 54);
	if (data->error == 5)
		write(1, "Error\n[Invalid map] Wrong value inside map.\n", 44);
}

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
