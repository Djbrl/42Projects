/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 05:20:02 by dsy               #+#    #+#             */
/*   Updated: 2020/05/11 18:41:30 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **array)
{
	int i;

	i = 0;
	if (array != NULL)
	{
		while (array[i] != 0 && array[i] != NULL)
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
