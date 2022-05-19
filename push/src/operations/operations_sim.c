/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_sim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:06:08 by dsy               #+#    #+#             */
/*   Updated: 2022/04/11 11:29:37 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rot(t_node **stack_a, t_node **stack_b)
{
	rot_a(stack_a);
	rot_b(stack_b);
	write(1, "rr\n", 3);
}

void	s_swap(t_node **stack_a, t_node **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	write(1, "ss\n", 3);
}

void	r_rev_rot(t_node **stack_a, t_node **stack_b)
{
	rev_rot_a(stack_a);
	rev_rot_b(stack_b);
	write(1, "rrr\n", 3);
}
