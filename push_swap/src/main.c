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

void	raditz(t_node **stack_a, t_node **stack_b, char **sorted)
{
	int	size;
	int	max_num;
	int	max_bits;

	size = stack_len(*stack_a);
	max_num = size - 1;
	max_bits = 0;
	fill_index(*stack_a, sorted);
	while ((max_num >> max_bits) != 0)
		max_bits++;
	sort_algo(stack_a, stack_b, max_bits, size);
}

int	bye(t_node **stack_a, t_node **stack_b, char ***sorted, int mode)
{
	if (mode != 3)
	{
		free_split(*sorted);
		free_stack(*stack_a);
		if (mode == 2)
			free_stack(*stack_b);
		return (0);
	}
	write(1, "Error\n", 6);
	return (0);
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
	head = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (sorted == NULL)
		return (bye(&stack_a, &stack_b, &sorted, 3));
	init_stacks(av, ac, &head, &stack_a);
	if (is_stack_sorted(stack_a))
		return (bye(&stack_a, &stack_b, &sorted, 1));
	if (stack_len(stack_a) == 3)
		sort_three(&stack_a);
	else if (stack_len(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
	else
		raditz(&stack_a, &stack_b, sorted);
	return (bye(&stack_a, &stack_b, &sorted, 2));
}
