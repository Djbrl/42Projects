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
	int				index;
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
void	free_split(char **array);
t_node	*find_element(t_node *stack, int data);
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
void	move_to_top(t_node **head, int to_move, \
	void ptr_move_up(t_node **stack), \
	void ptr_move_down(t_node **stack));
void	sort_desc(t_node **stack_a, t_node **stack_b, \
	void ptr_move_up(t_node **stack), \
	void ptr_move_down(t_node **stack));
void	sort_algo(t_node **a_stack, t_node **b_stack, int max_bits, int size);
void	fill_index(t_node *stack_a, char **sorted);
void	radix_sort(t_node **stack_a, t_node **stack_b);
int		get_index(int data, char **sorted);
int		find_mid_value(char **sorted, int *last_mid);
int		range_mid_value(char **sorted, int start, int stop);
int		size(char **sorted);
int		stack_len(t_node *stack);
int		find_stack_min(t_node *stack);

//LA NORME MDR
int		check_num(char *str);
void	compare_sort_norme(char **s1, char **s2);
void	compare_sort(int size, char **sorted);
char	**sort(char **array, int size);
char	**check_dup(char **args, int size);
int		count_args(char *av, int count);
int		get_nb_args(int ac, char **av);
char	**input_checker(int ac, char **av);

#endif
