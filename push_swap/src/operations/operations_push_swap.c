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

//swap the top 2 elements of a
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
	}
	else
		return ;
}

//swap the top 2 elements of b
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
	}
	else
		return ;
}

//put top of b in a
void	push_a(t_node **stack_a, t_node **stack_b)
{
	if (*stack_b)
	{
		push(stack_a, pop(stack_b));
		write(1, "pa\n", 3);
	}
	else
		return ;
}

//put top of a in b
void	push_b(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a)
	{
		write(1, "pb\n", 3);
		push(stack_b, pop(stack_a));
	}
	else
		return ;
}
