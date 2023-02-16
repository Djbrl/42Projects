/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:40:28 by dsy               #+#    #+#             */
/*   Updated: 2023/01/10 16:28:55 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	connect_fds(t_expr **curr_command, t_expr *commands)
{
	t_expr		*cur;
	int			pipefd[2];

	cur = *curr_command;
	while (cur->next != NULL)
	{
		pipe(pipefd);
		cur->fd_out = pipefd[1];
		cur->next->fd_in = pipefd[0];
		cur = cur->next;
	}
	cur->fd_out = 1;
	cur = commands;
	return (-1);
}

void	close_fds(t_expr **curr_command)
{
	t_expr	*cur;
	int status = 0;
	cur = *curr_command;
	if (cur->fd_in != 0)
		status = close(cur->fd_in);
	if (status == -1)
		perror("close");
	status = 0;
	if (cur->fd_out != 1)
		status = close(cur->fd_out);
	if (status == -1)
		perror("close");
	status = 0;
}

int	init_fds(t_expr **commands, t_expr *prev)
{
	int		pipefd[2];
	t_expr	*cur;

	cur = *commands;
	if (!cur)
		return (-1);
	while (cur->next != NULL)
	{
		pipe(pipefd);
		if (prev != NULL)
			cur->fd_in = prev->fd_out;
		else
			cur->fd_in = STDIN_FILENO;
		cur->fd_out = pipefd[1];
		cur->next->fd_in = pipefd[0];
		prev = cur;
		cur = cur->next;
	}
	if (prev != NULL)
		cur->fd_in = prev->fd_out;
	cur->fd_out = STDOUT_FILENO;
	return (0);
}

void	exec_builtin(t_msh *msh, char *field)
{
	int		in;
	int		out;
	int		free;
	char	**tmp;

	free = 0;
	in = -1;
	out = -1;
	if (!field)
		apply_redirections(msh->prompt, &in, &out, msh);
	else
		apply_redirections(field, &in, &out, msh);
	close_redir(in, out);
	if (field != NULL)
	{
		tmp = ft_split(field, ' ');
		free = 1;
	}
	else
		tmp = msh->tokens;
	msh->cmd.ptr[is_builtin(tmp[0], msh)](msh->env, msh, field);
	if (free)
		free_split(tmp);
	dup2(msh->std_in, 0);
	dup2(msh->std_out, 1);
}
