/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 00:15:15 by dsy               #+#    #+#             */
/*   Updated: 2022/10/05 12:20:21 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_left_to_ast(t_msh *msh, char *data)
{
	t_ast	*ast;

	ast = msh->ast;
	if (!ast || !data)
		return (0);
	while (ast->left != NULL)
		ast = ast->left;
	ast->left = malloc(sizeof(t_ast));
	ast->left->data = ft_strdup(data);
	ast->left->left = NULL;
	free(data);
	return (1);
}

int	add_right_to_ast(t_msh *msh, char *data)
{
	t_ast	*ast;

	ast = msh->ast;
	if (!ast || !data)
		return (0);
	while (ast->right != NULL)
		ast = ast->right;
	ast->right = malloc(sizeof(t_ast));
	ast->right->data = ft_strdup(data);
	ast->right->right = NULL;
	free(data);
	return (1);
}
