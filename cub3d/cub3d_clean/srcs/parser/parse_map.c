/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:13:18 by dsy               #+#    #+#             */
/*   Updated: 2020/02/16 03:58:49 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_map_keys(char **loaded_file)
{
	int i;


	i = 0;
	while (loaded_file[i] != 0)
	{
	//	
	}
}

int	parse_map_file(char *path)
{
	char **loaded_file;

	loaded_file = load_map_file(path); //free later
	check_keys(loaded_file);
	free(loaded_file);
	return (1);
}
