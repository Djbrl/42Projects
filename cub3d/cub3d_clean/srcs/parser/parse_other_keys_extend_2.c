/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_other_keys_extend_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:52:49 by dsy               #+#    #+#             */
/*   Updated: 2020/03/05 01:15:20 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		go_through_valid_keys(char **valid_keys, char *key)
{
	int i;

	i = 0;
	while (valid_keys[i])
	{
		if (!(ft_strncmp(valid_keys[i], key, ft_strlen(valid_keys[i]))))
			return (1);
		i++;
	}
	return (0);
}

int		go_through_file(char *keys[9], t_game *file)
{
	if ((go_through_valid_keys(keys, file->r_key[0])) &&
		(go_through_valid_keys(keys, file->n_key[0])) &&
		(go_through_valid_keys(keys, file->so_key[0])) &&
		(go_through_valid_keys(keys, file->w_key[0])) &&
		(go_through_valid_keys(keys, file->e_key[0])) &&
		(go_through_valid_keys(keys, file->s_key[0])) &&
		(go_through_valid_keys(keys, file->f_key[0])) &&
		(go_through_valid_keys(keys, file->c_key[0])))
		return (1);
	return (0);
}

int		check_keys_exist(t_game *file)
{
	int		i;
	char	*keys[9];

	keys[0] = "R";
	keys[1] = "NO";
	keys[2] = "SO";
	keys[3] = "WE";
	keys[4] = "EA";
	keys[5] = "S";
	keys[6] = "F";
	keys[7] = "C";
	keys[8] = 0;
	i = 0;
	if (!(go_through_file(keys, file)))
	{
		file->error = 2;
		return (0);
	}
	return (1);
}
