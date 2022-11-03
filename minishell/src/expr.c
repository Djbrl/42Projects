/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:06:35 by dsy               #+#    #+#             */
/*   Updated: 2022/10/06 11:31:28 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	free_expr(t_msh *msh)
// {
// 	t_expr	*cur;

// 	if (!msh->expr)
// 		return ;
// 	while (msh->expr)
// 	{
// 		cur = msh->expr;
// 		if (msh->expr->data)
// 			free(msh->expr->data);
// 		msh->expr = msh->expr->next;
// 		free(cur);
// 	}
// 	free(msh->expr);
// }

int	load_expr(t_msh *msh)
{
	int		i;
	int		free_expr;
	// t_expr	*expr;
	// char	*tmp;

	i = 0;
	free_expr = 0;
	// expr = msh->expr;
	// tmp = NULL;
	while (msh->prompt[i])
	{
		if (msh->prompt[i] == '|')
		{
			msh->expr = ft_split(msh->prompt, '|');
			// tmp = ft_substr(msh->prompt, 0, i);
			// // add_var_to_expr(expr, tmp);
			// free(tmp);
			// tmp = ft_strdup(msh->prompt + i + 1);
			// // add_var_to_expr(expr, tmp);
			// free(tmp);
			free_expr = 1;
		}
		i++;
	}
	return (free_expr);
}
