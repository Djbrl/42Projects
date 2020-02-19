/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:15:56 by dsy               #+#    #+#             */
/*   Updated: 2020/02/19 22:14:14 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

//Parsing map done, now parse keys
int main()
{
	t_map map;

	map = parse_map_file(PATH_MAP, map);
	free_map_struct(map);
	return (0);
}
