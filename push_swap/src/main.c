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

char	**compare_sort(int size, char **sorted)
{
	int		k;
	int		j;
	char	*temp;

	j = 0;
	k = 0;
	while (k < size - 1)
	{
		while (sorted[j] && sorted[j + 1])
		{
			temp = ft_strdup(sorted[j]);
			if (ft_atoi(sorted[j]) > ft_atoi(sorted[j + 1]))
			{
				strcpy(temp, sorted[j]);
				strcpy(sorted[j], sorted[j + 1]);
				strcpy(sorted[j + 1], temp);
			}
			j++;
			free(temp);
		}
		k++;
		j = 0;
	}
	return (sorted);
}

char	**sort(char **array, int size)
{
	int		i;
	int		j;
	char	**sorted;

	j = 0;
	i = 0;
	sorted = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		sorted[j] = ft_strdup(array[i]);
		i++;
		j++;
	}
	sorted[j] = 0;
	i = 0;
	while (i < size)
		free(array[i++]);
	free(array);
	return (compare_sort(size, sorted));
}

int	check_dup(char **args, int size)
{
	char	**sorted;
	int		i;
	int		j;

	i = 0;
	j = 0;
	sorted = sort(args, size);
	while (sorted[i] && sorted[i + 1])
	{
		if (!strcmp(sorted[i], sorted[i + 1]))
		{
			while (sorted[j])
				free(sorted[j++]);
			free(sorted);
			return (1);
		}
		else
			i++;
	}
	j = 0;
	free_split(sorted);
	return (0);
}

int	count_args(char *av, int count)
{
	int		j;
	char	**split;

	j = 0;
	split = ft_split(av, ' ');
	while (split[j] != 0)
	{
		count++;
		j++;
	}
	free_split(split);
	return (count);
}

int	get_nb_args(int ac, char **av)
{
	int		i;
	int		j;
	int		count;

	i = 1;
	j = 0;
	count = 0;
	while (i < ac)
	{
		if (((int)ft_strlen(av[i])) > 1)
		{
			count = count_args(av[i], count);
		}
		else
			count++;
		i++;
		j = 0;
	}
	return (count);
}

int	check_args(char **args, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if ((ft_atoi(args[i]) == 0 && strcmp(args[i], "0")) \
			|| (ft_atoi(args[i]) > INT_MAX))
		{
			while (j < size)
				free(args[j++]);
			free(args);
			return (0);
		}
		i++;
	}
	return (1);
}

int	input_checker(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	**in;
	char	**args;

	i = 1;
	j = 0;
	k = 0;
	args = (char **)malloc(sizeof(char *) * get_nb_args(ac, av));
	while (i < ac)
	{
		in = ft_split(av[i], ' ');
		while (in[j])
			args[k++] = ft_strdup(in[j++]);
		free_split(in);
		j = 0;
		i++;
	}
	if (!check_args(args, get_nb_args(ac, av)))
		return (0);
	check_dup(args, get_nb_args(ac, av));
	return (get_nb_args(ac, av));
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
	ptr_move_up = &rot_a;
	ptr_move_down = &rev_rot_a;
	while (stack_a)
		sort_desc(&stack_a, &stack_b, ptr_move_up, ptr_move_down);
	ptr_move_up = &rot_b;
	ptr_move_down = &rev_rot_b;
	while (stack_b)
		push_a(&stack_a, &stack_b);
	//print_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
