/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:01:49 by dsy               #+#    #+#             */
/*   Updated: 2022/04/11 11:04:50 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_node **head_ref, int new_data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
	return (new_data);
}

void	push_end(t_node **head, t_node *new)
{
	t_node	*current;

	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

int	pop(t_node **root)
{
	int		popped;
	t_node	*temp;

	if (is_empty(*root))
		return (INT_MIN);
	temp = *root;
	*root = (*root)->next;
	popped = temp->data;
	free(temp);
	return (popped);
}

int	peek(t_node *root)
{
	if (is_empty(root))
		return (0);
	return (root->data);
}

int	is_empty(t_node *root)
{
	return (!root);
}
