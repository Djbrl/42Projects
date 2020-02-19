/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 05:20:02 by dsy               #+#    #+#             */
/*   Updated: 2020/02/17 16:15:38 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_array(char **array)
{
	int i;

	i = 0;
	if (array != NULL)
	{
		while (array[i] != 0)
		{
			free(array[i]);
			i++;
		}
		free(array[i]);
		free(array);
	}
	else
		return ;
}
