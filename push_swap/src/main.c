/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:01:49 by dsy               #+#    #+#             */
/*   Updated: 2022/04/29 16:15:09 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(char **av, int ac, t_node **head, t_node **stack_a)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	i = ac - 1;
	k = 0;
	while (i > 0)
	{
		k = 0;
		j = count_args(av[i], k) - 1;
		tmp = ft_split(av[i], ' ');
		while (j >= 0)
		{
			*stack_a = (t_node *)malloc(sizeof(t_node));
			(*stack_a)->data = ft_atoi(tmp[j--]);
			(*stack_a)->next = *head;
			*head = *stack_a;
		}
		free_split(tmp);
		k = 0;
		j = count_args(av[i], k) - 1;
		i--;
	}
}

void	sort_stacks(t_node **stack_a, t_node **stack_b)
{
	void	(*ptr_move_up)(t_node **);
	void	(*ptr_move_down)(t_node **);

	ptr_move_up = &rot_a;
	ptr_move_down = &rev_rot_a;
	while (*stack_a)
		sort_desc(stack_a, stack_b, ptr_move_up, ptr_move_down);
	ptr_move_up = &rot_b;
	ptr_move_down = &rev_rot_b;
	while (*stack_b)
		push_a(stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
}

int	main(int ac, char *av[])
{
	char	**sorted;
	t_node	*head;
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac == 1)
		return (0);
	sorted = input_checker(ac, av);
	if (sorted == NULL)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	head = NULL;
	stack_a = NULL;
	stack_b = NULL;
	init_stacks(av, ac, &head, &stack_a);
	sort_stacks(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free_split(sorted);
	return (0);
}
