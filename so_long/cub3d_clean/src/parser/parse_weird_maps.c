/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_weird_maps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:26:32 by dsy               #+#    #+#             */
/*   Updated: 2020/05/11 18:41:21 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_longest_row(t_game *data)
{
	int i;
	int j;
	int max;

	i = 0;
	j = 0;
	max = 0;
	while (data->map_key[i])
	{
		j = 0;
		while (data->map_key[i][j])
			if (data->map_key[i][j] != ' ')
				j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

int	arrange_map(t_game *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("longest row : %i\n", find_longest_row(data));
	//continue lata
	return (1);
}
