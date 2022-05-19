/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:35:14 by dsy               #+#    #+#             */
/*   Updated: 2022/05/19 14:27:54 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//find a mid value in the sorted array
//push everything lower than mid to stack b until we are stopped by a big number - first chunk
//also check bottom val and if its less than mid value, bring to top
//when hitting val equal or higher than mid, RA stack until find smaller than mid val, while i < len/2
//when everything under mid has been moved, create a new mid value with and repeat
//stop when 2 elements are left, if unsorted, swap
//
//in stack b
//repeat this algorithm, but move everything higher than mid
//keep track of rb and undo them after treating chunk

int	size(char **sorted)
{
	int	i;

	i = 0;
	while (sorted[i])
		i++;
	return (i);
}

int	find_mid_value(char **sorted, int *last_mid)
{
	int	mid;
	int	index;

	mid = 0;
	index = 0;
	index = (size(sorted) / 2) + *last_mid / 2;
	mid = ft_atoi(sorted[index]);
	*last_mid = index + 1;
	return (mid);
}
