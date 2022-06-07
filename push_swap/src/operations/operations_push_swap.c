/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:06:08 by dsy               #+#    #+#             */
/*   Updated: 2022/04/11 11:29:30 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **stack_a)
{
	int	tmp;
	int	tmp2;

	if (*stack_a)
	{
		tmp = pop(stack_a);
		tmp2 = pop(stack_a);
		push(stack_a, tmp);
		push(stack_a, tmp2);
		write(1, "sa\n", 3);
	}
	else
		return ;
}

void	swap_b(t_node **stack_b)
{
	int	tmp;
	int	tmp2;

	if (*stack_b)
	{
		tmp = pop(stack_b);
		tmp2 = pop(stack_b);
		push(stack_b, tmp);
		push(stack_b, tmp2);
		write(1, "sb\n", 3);
	}
	else
		return ;
}

//put top of b in a
void	push_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (stack_len(*stack_b) > 0)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	else
		return ;
	write(1, "pa\n", 3);
}

//put top of a in b
void	push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (stack_len(*stack_a) > 0)
	{
		if (stack_b == NULL)
		{
			stack_b = malloc(sizeof(t_node));
			if (stack_b == NULL)
				return ;
			(*stack_b)->next = NULL;
		}
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
	else
		return ;
	write(1, "pb\n", 3);
}
