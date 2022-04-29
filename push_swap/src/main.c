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

char	**sort(char **array, int size)
{
	int	i;
	int	j;
	int	k;
	char	**sorted;
	char	*temp;

	j = 0;
	k = 0;
	i = 1;


	sorted = (char **)malloc(sizeof(char *) * size);
	while (array[i])
	{
		sorted[j] = ft_strdup(array[i]);
		i++;
		j++;
	}
	sorted[i] = 0;
	
	j = 0;
	while (k < size)
	{
		while (sorted[j] && sorted[j+1])
		{
			temp = ft_strdup(sorted[j]);
			if(ft_atoi(sorted[j]) > ft_atoi(sorted[j+1])){
				strcpy(temp, sorted[j]);
				strcpy(sorted[j], sorted[j+1]);
				strcpy(sorted[j+1], temp);
			}
			j++;
			free(temp);
		}
		k++;
		j = 0;
	}
	return sorted;
}

int		check_dup(char **av, int size)
{
	char **sorted;
	int		i;
	int		j;

	i = 0;
	j = 0;
	sorted = sort(av, size);
	while (sorted[i] && sorted[i+1])
		if (!strcmp(sorted[i], sorted[i+1]))
		{
			while (sorted[j])
				free(sorted[j++]);
			free(sorted);
			return (1);
		}
		else
			i++;
	j = 0;
	while (sorted[j])
		free(sorted[j++]);
	free(sorted);
	return (0);
}

int input_checker(int ac, char **av)
{
	char	**in;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 1;
	j = 0;
	while (i < ac)
	{
		in = ft_split(av[i], ' ');
		while (in[j])
		{
			while (in[j][k]){
				if (ft_isdigit(in[j][k] == 0 && in[j][k] != '-'))
					return 0;
				k++;
			}
			if (!ft_atoi(in[j]) && ft_strcmp(in[j], "0") != 0)
				return (0);
			if (ft_atoi(in[j]) < INT_MIN || ft_atoi(in[j]) > INT_MAX)
				return (0);
			j++;
		}
		j = 0;
		while (in[j])
			free(in[j++]);
		free(in);
		i++;
	}
	check_dup(av, j + i);

	return (1);
}

int	main(int ac, char *av[])
{
	int		i;
	void	(*ptr_move_up)(t_node **);
	void	(*ptr_move_down)(t_node **);
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
	head = NULL;
	stack_a = NULL;
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
	ptr_move_up = &rot_a;
	ptr_move_down = &rev_rot_a;
	while (stack_a)
		sort_desc(&stack_a, &stack_b, ptr_move_up, ptr_move_down);
	ptr_move_up = &rot_b;
	ptr_move_down = &rev_rot_b;
	print_stacks(stack_a, stack_b);
	while (stack_b)
		push_a(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
