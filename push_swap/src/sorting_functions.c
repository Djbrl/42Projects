/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:10:48 by dsy               #+#    #+#             */
/*   Updated: 2022/04/11 10:32:28 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_node *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	find_min(t_node *stack)
{
	int	min;

	if (!stack)
		return (INT_MIN);
	min = stack->data;
	while (stack)
	{
		if (min > stack->data)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

void	move_to_top(t_node **head, int to_move, \
	void ptr_move_up(t_node **stack), \
	void ptr_move_down(t_node **stack))
{
	t_node	*cur;
	int		i;
	int		len;
	int		move_dist;
	int		steps;

	i = 1;
	len = stack_len(*head);
	cur = *head;
	if (!cur || cur->data == to_move)
		return ;
	while (cur->data != to_move && cur->next != NULL)
	{
		cur = cur->next;
		i++;
	}
	if (cur->data != to_move)
		return ;
	move_dist = ((len - (len - i)) * 100) / len;
	if (move_dist > 51)
	{
		steps = len - i + 1;
		while (steps--)
			ptr_move_down(head);
	}
	else
	{
		steps = i - 1;
		while (steps--)
			ptr_move_up(head);
	}
}

void	sort_desc(t_node **stack_a, t_node **stack_b, \
	void ptr_move_up(t_node **stack), \
	void ptr_move_down(t_node **stack))
{
	int		min;
	t_node	*cur;

	cur = *stack_a;
	min = find_min(*stack_a);
	move_to_top(stack_a, min, ptr_move_up, ptr_move_down);
	push_b(stack_a, stack_b);
}
