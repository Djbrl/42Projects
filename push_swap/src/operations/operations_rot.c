/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:06:08 by dsy               #+#    #+#             */
/*   Updated: 2022/04/11 11:29:44 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_a(t_node **stack_a)
{
	t_node	*head;
	t_node	*first;

	if (list_len(*stack_a) < 2)
		return ;
	first = *stack_a;
	head = *stack_a;
	while (head->next != NULL)
		head = head->next;
	head->next = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rot_b(t_node **stack_b)
{
	t_node	*head;
	t_node	*first;

	if (list_len(*stack_b) < 2)
		return ;
	first = *stack_b;
	head = *stack_b;
	while (head->next != NULL)
		head = head->next;
	head->next = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rev_rot_a(t_node **stack_a)
{
	t_node	*head;
	t_node	*last;

	if (list_len(*stack_a) < 2)
		return ;
	head = *stack_a;
	while (head->next != NULL)
	{
		last = head;
		head = head->next;
	}
	last->next = NULL;
	push(stack_a, head->data);
	free(head);
	write(1, "rra\n", 4);
}

void	rev_rot_b(t_node **stack_b)
{
	t_node	*head;
	t_node	*last;

	if (list_len(*stack_b) < 2)
		return ;
	head = *stack_b;
	while (head->next != NULL)
	{
		last = head;
		head = head->next;
	}
	last->next = NULL;
	push(stack_b, head->data);
	free(head);
	write(1, "rrb\n", 4);
}
