/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:40:28 by dsy               #+#    #+#             */
/*   Updated: 2023/01/10 16:29:14 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_redirections(t_msh *msh)
{
	int		in;
	int		out;

	in = -1;
	out = -1;
	apply_redirections(msh->prompt, &in, &out, msh);
	if (in != -1)
		dup2(in, 0);
	if (out != -1)
		dup2(out, 1);
	return ;
}
