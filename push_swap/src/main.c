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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	init_stacks(char **av, int ac, t_node **head, t_node **stack_a, char **sorted)
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
			(*stack_a)->index = -1;
			(*stack_a)->next = *head;
			*head = *stack_a;
		}
		free_split(tmp);
		k = 0;
		j = count_args(av[i], k) - 1;
		i--;
	}
	(void)sorted;
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

int	count(char **sorted, int stop)
{
	int	i;

	i = 0;
	while (sorted[i] && ft_atoi(sorted[i]) != stop)
		i++;
	return (i);
}

int	get_index(int data, char **sorted)
{
	int	i;

	i = 0;
	while (sorted[i])
	{
		if (ft_atoi(sorted[i]) == data)
			return i;
		i++;
	}
	return (-1);
}

void fill_index(t_node *stack_a, char **sorted)
{
	t_node *cur = stack_a;

	while (cur)
	{
		cur->index = get_index(cur->data,sorted);
		cur = cur->next;
	}
}
/*
int	mid_point_algorithm(char **sorted, int *last_mid, \
	t_node **stack_a, t_node **stack_b)
{
	void	(*ptr_move_down)(t_node**);
	int		tmp;
	int		mid;
	int		i;

	i = 0;
	tmp = 0;
	ptr_move_down = &rot_b;
	if (*last_mid != 0)
		tmp += (*last_mid * -1) + 1;
	mid = find_mid_value(sorted, last_mid);
	tmp += count(sorted, mid);
	if (stack_len(*stack_a) < 3)
		return (INT_MIN);
	while (i < tmp)
	{
		if ((*stack_a)->data < mid)
		{
			push_b(stack_a, stack_b);
			i++;
		}
		else
			ptr_move_down(stack_a);
	}
	return (tmp);
}

void	sort_s(t_node **stack_a, t_node **stack_b, \
	char **sorted, int *last_mid)
{
	int	i;

	i = 0;
	while (i != INT_MIN)
	{
		i = mid_point_algorithm(sorted, last_mid, stack_a, stack_b);
		push(stack_b, -111222333);
	}
	if ((*stack_a)->data > ((*stack_a)->next)->data)
		swap_a(stack_a);
	*last_mid = 0;
	print_stacks(*stack_a, *stack_b);
}
*/




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

void	raditz(t_node **a_stack, t_node **b_stack, char **sorted)
{
	int	size;
	int	max_num;
	int	max_bits;

	size = stack_len(*a_stack);
	max_num = size - 1;
	max_bits = 0;
	fill_index(*a_stack, sorted);
	while ((max_num >> max_bits) != 0)
		max_bits++;
	sort_algo(a_stack, b_stack, max_bits, size);
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
	init_stacks(av, ac, &head, &stack_a, sorted);
	raditz(&stack_a, &stack_b, sorted);
	print_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free_split(sorted);
	return (0);
}
