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

int	count (char **sorted, int *stop)
{
	int i = 0;
	while (sorted[i] && ft_atoi(sorted[i]) != *stop)
	{
		i++;
	}
	return (i);
}

void mid_point_algorithm(char **sorted, int *last_mid, \
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
		tmp = *last_mid * -1;
	printf("tmp before count %i \n", tmp);
	mid = find_mid_value(sorted, last_mid);
	tmp += count(sorted, last_mid);
	printf("tmp before count %i \n", tmp);
	printf("mid value found [%i] at index [%i], size of chunk [%i]\n", mid, *last_mid, tmp);
	while (i < tmp)
	{
		print_stacks(*stack_a, *stack_b);
		printf("top element : %i\n", (*stack_a)->data);
		printf("mid element : %i\n", mid);
		printf("count : %i\n", tmp);
		// printf("size of chunk : %i last : %i\n", tmp, *last_mid);
		if ((*stack_a)->data < mid)
		{
			printf("top element is inferior to %i, pushing\n", mid);
			print_stacks(*stack_a, *stack_b);
			push_b(stack_a, stack_b);
			i++;
		}
		else
			ptr_move_down(stack_a);
	}
}

void	sort_s(t_node **stack_a, t_node **stack_b, \
	char **sorted, int *last_mid)
{
	// int		i;
	// int		tmp;
	// int		mid;
	// void	(*ptr_move_up)(t_node**);
	// void	(*ptr_move_down)(t_node**);

	mid_point_algorithm(sorted, last_mid, stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
	mid_point_algorithm(sorted, last_mid, stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
	//mid_point_algorithm(sorted, last_mid, stack_a, stack_b);


	// i = 0;
	// ptr_move_up = &rot_a;
	// ptr_move_down = &rot_b;
	// mid = find_mid_value(sorted, last_mid);
	// tmp = size(sorted + *last_mid) + 1;
	// printf("mid value : %i at index : %i\n", mid, *last_mid);
	// while ((i < *last_mid - 1))
	// {
	// 	print_stacks(*stack_a, *stack_b);
	// 	printf("top element : %i\n", (*stack_a)->data);
	// 	printf("mid element : %i\n", mid);
	// 	if ((*stack_a)->data < mid)
	// 	{
	// 		printf("top element is inferior to %i, pushing\n", mid);
	// 		push_b(stack_a, stack_b);
	// 		print_stacks(*stack_a, *stack_b);
	// 		i++;
	// 	}
	// 	else
	// 		ptr_move_down(stack_a);
	// }
	// i = 0;
	// mid = find_mid_value(sorted, last_mid);
	// tmp = size(sorted + *last_mid) + 1;
	// printf("size of next : %i\n", tmp);
	// printf("mid value : %i at index : %i\n", mid, *last_mid);
	// while (i < tmp)
	// {
	// 	print_stacks(*stack_a, *stack_b);
	// 	printf("top element : %i\n", (*stack_a)->data);
	// 	printf("mid element : %i\n", mid);
	// 	if ((*stack_a)->data < mid)
	// 	{
	// 		printf("top element is inferior to %i, pushing\n", mid);
	// 		push_b(stack_a, stack_b);
	// 		print_stacks(*stack_a, *stack_b);
	// 		i++;
	// 	}
	// 	else
	// 		ptr_move_down(stack_a);
	// }
	// 	i = 0;
	// mid = find_mid_value(sorted, last_mid);
	// tmp = size(sorted + *last_mid) + 1;
	// printf("size of next : %i\n", tmp);
	// printf("mid value : %i at index : %i\n", mid, *last_mid);
	// printf("%i\n", size(sorted + *last_mid));
	// while (i < tmp)
	// {
	// 	print_stacks(*stack_a, *stack_b);
	// 	printf("top element : %i\n", (*stack_a)->data);
	// 	printf("mid element : %i %i\n", mid, tmp);
	// 	if ((*stack_a)->data < mid)
	// 	{
	// 		printf("top element is inferior to %i, pushing\n", mid);
	// 		push_b(stack_a, stack_b);
	// 		print_stacks(*stack_a, *stack_b);
	// 		i++;
	// 	}
	// 	else
	// 		ptr_move_down(stack_a);
	// }
	(void)stack_a;
	(void)stack_b;
}

int	main(int ac, char *av[])
{
	int		last_mid;
	char	**sorted;
	t_node	*head;
	t_node	*stack_a;
	t_node	*stack_b;

	last_mid = 0;
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
	sort_s(&stack_a, &stack_b, sorted, &last_mid);
//	sort_stacks(&stack_a, &stack_b);
	// int last_mid = 0;
	// int mid = find_mid_value(sorted, &last_mid);
	// printf("mid value : %i at index : %i\n", mid, last_mid);
	// mid = find_mid_value(sorted, &last_mid);
	// printf("mid value : %i at index : %i\n", mid, last_mid);
	// mid = find_mid_value(sorted, &last_mid);
	// if (mid != INT_MIN)
	// 	printf("mid value : %i at index : %i\n", mid, last_mid);
	free_stack(stack_a);
	free_stack(stack_b);
	free_split(sorted);
	return (0);
}
