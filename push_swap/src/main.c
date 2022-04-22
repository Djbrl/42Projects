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

int input_checker(int ac, char **av)
{
	char	**args;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		//check long for atoi
		//ft_split and atoi each string
		//check if sorted asc
		//check if duplicates
		if (!ft_atoi(av[i]) && ft_strcmp(av[i], "0") != 0)
			return (0);
		if (ft_atoi(av[i]) < INT_MIN || ft_atoi(av[i]) > INT_MAX)
			return (0);
		args = ft_split(av, ' ');
		while (args[j])
		{
			//
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int		i;
	t_node	*head;
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac == 1)
		return (0);
	if (!input_checker(ac, av))
	{
		write(1, "Error\n", 6);
		return (0);
	}
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
	/*print_stacks(stack_a, stack_b);
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
	rot_a(&stack_a);
	push_end(&stack_a, new_node(-1));
	push(&stack_a, -2);
	print_stacks(stack_a, stack_b);
	rot_a(&stack_a);
	print_stacks(stack_a, stack_b);
	rev_rot_a(&stack_a);
	rev_rot_a(&stack_a);
	rev_rot_a(&stack_a);
	rev_rot_a(&stack_a);
	rev_rot_a(&stack_a);
	rev_rot_a(&stack_a);
	rev_rot_a(&stack_a);
	rot_a(&stack_a);
	rot_a(&stack_a);
	print_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);*/
	return (0);
}
