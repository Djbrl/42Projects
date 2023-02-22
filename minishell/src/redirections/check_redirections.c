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

static void	dup_fds(int in, int out)
{
	if (in != -1)
	{
		dup2(in, 0);
		close(in);
	}
	if (out != -1)
	{
		dup2(out, 1);
		close(out);
	}
}

int	check_redirections(t_msh *msh)
{
	int		in;
	int		out;
	int		i;
	int		redir;

	i = 0;
	in = -1;
	out = -1;
	redir = 0;
	while (msh->tokens[i])
	{
		if (msh->tokens[i][0] == '>' || msh->tokens[i][0] == '<')
		{
			apply_redirections(msh->prompt, &in, &out, msh);
			redir = 1;
			break ;
		}
		i++;
	}
	dup_fds(in, out);
	if (redir == 1)
		return (1);
	else
		return (0);
}
