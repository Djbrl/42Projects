/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:17:33 by dsy               #+#    #+#             */
/*   Updated: 2022/04/11 09:34:21 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_node{
	int				data;
	struct s_node	*next;
}				t_node;

//STACK FUNCTIONS
int		pop(t_node **root);
int		push(t_node **head_ref, int new_data);
int		peek(t_node *root);
int		list_len(t_node *node);
int		is_empty(t_node *root);
void	push_end(t_node **head, t_node *new);
void	print_list(t_node *node);
void	print_stacks(t_node *a, t_node *b);
void	free_stack(t_node *node);
t_node	*new_node(int data);

//OPERATIONS
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
void	rot_a(t_node **stack_a);
void	rot_b(t_node **stack_b);
void	rev_rot_a(t_node **stack_a);
void	rev_rot_b(t_node **stack_b);
void	r_rot(t_node **stack_a, t_node **stack_b);
void	s_swap(t_node **stack_a, t_node **stack_b);
void	r_rev_rot(t_node **stack_a, t_node **stack_b);

//ALGORITHMS
void	merge_sort(t_node **headRef);
void	front_back_split(t_node *source, t_node **frontRef, t_node **backRef);
t_node	*sorted_merge(t_node *a, t_node *b);

#endif
