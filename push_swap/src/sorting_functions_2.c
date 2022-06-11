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
	index = (size(sorted) / 2) + *last_mid / 2;
	if (size(sorted + *last_mid) + 1 < 3)
		return (INT_MIN);
	if (!sorted[index + 1])
		return (ft_atoi(sorted[index - 1]));
	mid = ft_atoi(sorted[index]);
	*last_mid = index + 1;
	return (mid);
}

int	is_stack_sorted(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->data > (stack->next)->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
