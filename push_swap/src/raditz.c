/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raditz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:25:14 by dsy               #+#    #+#             */
/*   Updated: 2022/06/10 15:25:25 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int data, char **sorted)
{
	int	i;

	i = 0;
	while (sorted[i])
	{
		if (ft_atoi(sorted[i]) == data)
			return (i);
		i++;
	}
	return (-1);
}

void	fill_index(t_node *stack_a, char **sorted)
{
	t_node	*cur;

	cur = stack_a;
	while (cur)
	{
		cur->index = get_index(cur->data, sorted);
		cur = cur->next;
	}
}

void	sort_three(t_node **stack_a)
{
	t_node	*cur;

	cur = *stack_a;
	if (cur->data < (cur->next)->data && cur->data != find_stack_min(*stack_a))
		rev_rot_a(stack_a);
	else if (cur->data < (cur->next)->data && \
		cur->data == find_stack_min(*stack_a))
	{
		rev_rot_a(stack_a);
		swap_a(stack_a);
	}
	else
		swap_a(stack_a);
	if (!is_stack_sorted(*stack_a))
		sort_three(stack_a);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	void	(*ptr_move_up)(t_node **);
	void	(*ptr_move_down)(t_node **);
	int		min;

	ptr_move_up = &rot_a;
	ptr_move_down = &rev_rot_a;
	min = find_stack_min(*stack_a);
	move_to_top(stack_a, min, ptr_move_up, ptr_move_down);
	push_b(stack_a, stack_b);
	min = find_stack_min(*stack_a);
	move_to_top(stack_a, min, ptr_move_up, ptr_move_down);
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_algo(t_node **a_stack, t_node **b_stack, int max_bits, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a_stack)->index >> i) & 1) == 1)
				rot_a(a_stack);
			else
				push_b(a_stack, b_stack);
			j++;
		}
		while (*b_stack)
			push_a(a_stack, b_stack);
		i++;
	}
}
