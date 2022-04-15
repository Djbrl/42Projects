/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:01:49 by dsy               #+#    #+#             */
/*   Updated: 2022/04/11 11:32:43 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//roadmap
// -do initial conditions for each function
// implement each operation
int	main(int ac, char *av[])
{
	int		i;
	t_node	*head;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	i = ac - 1;
	while (i > 0)
	{
		stack_a = (t_node *)malloc(sizeof(t_node));
		stack_a->data = ft_atoi(av[i]);
		stack_a->next = head;
		head = stack_a;
		i--;
	}
	print_stacks(stack_a, stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	push(&stack_a, 5);
	swap_a(&stack_a);
	swap_a(&stack_a);
	swap_a(&stack_a);
	print_stacks(stack_a, stack_b);
	s_swap(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
