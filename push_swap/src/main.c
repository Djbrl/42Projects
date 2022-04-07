/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:01:49 by dsy               #+#    #+#             */
/*   Updated: 2022/04/05 15:56:43 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	print_stack(t_node *top)
{
	t_node	*read;

	read = top;
	write(1, "-----\n", 6);
	while (read != NULL)
	{
		ft_putstr("| ");
		ft_putstr(read->data);
		ft_putstr(" |\n");
		read = read->next;
	}
	write(1, "-----\n", 6);
}

int	main(int ac, char *av[])
{
	int		i;
	t_node	*head;
	t_node	*stack_a;

	head = NULL;
	i = ac - 1;
	while (i > 0)
	{
		stack_a = (t_node *)malloc(sizeof(t_node));
		stack_a->data = av[i];
		stack_a->next = head;
		head = stack_a;
		i--;
	}
	print_stack(head);
	return (0);
}
