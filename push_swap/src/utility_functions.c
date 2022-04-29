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

	if (!node)
		return ;
	while (node->next != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	if (node)
		free(node);
}

int	list_len(t_node *node)
{
	int	i;

	i = 0;
	if (!node)
		return (0);
	while (node != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}

t_node	*new_node(int data)
{
	t_node	*head;

	if (data < -2147483648 || data > 2147483647)
	{
		head = NULL;
		return (head);
	}
	head = (t_node *)malloc(sizeof(t_node));
	if (head == NULL)
		return (0);
	head->data = data;
	head->next = NULL;
	return (head);
}
