/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:01:49 by dsy               #+#    #+#             */
/*   Updated: 2022/04/11 10:21:41 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_node *a, t_node *b)
{
	t_node	*read_a;
	t_node	*read_b;

	read_a = a;
	read_b = b;
	while (read_a != NULL || read_b != NULL)
	{
		if (read_a)
		{
			ft_putnbr(read_a->data);
			read_a = read_a->next;
		}
		write(1, "\t|\t", 3);
		if (read_b)
		{
			ft_putnbr(read_b->data);
			read_b = read_b->next;
		}
		write(1, "\n", 1);
	}
	ft_putstr("-------------------\n");
}

void	print_list(t_node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

void	free_stack(t_node *node)
{
	t_node	*tmp;

	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}
