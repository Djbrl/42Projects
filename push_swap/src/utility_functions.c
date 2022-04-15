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

void	print_stack(t_node *top)
{
	t_node	*read;

	read = top;
	write(1, "-----\n", 6);
	while (read != NULL)
	{
		ft_putstr("| ");
		ft_putnbr(read->data);
		ft_putstr(" |\n");
		read = read->next;
	}
	write(1, "-----\n", 6);
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
