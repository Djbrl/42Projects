/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:40:28 by dsy               #+#    #+#             */
/*   Updated: 2022/11/04 18:40:30 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int connect_fds(t_expr **curr_command, t_expr *commands)
{
	t_expr		*cur;
	int			pipefd[2];

	cur = *curr_command;
	while (cur->next != NULL)
	{
		if (pipe(pipefd) == -1)
		{
			perror("connect fd pipe: ");
			return (-1);
		}
		cur->fd_out = pipefd[1];
		cur->next->fd_in = pipefd[0];
		cur = cur->next;
	}
	cur->fd_out = 1;
	cur = commands;
	return (-1);
}

void close_fds(t_expr **curr_command)
{
	t_expr *cur;

	cur = *curr_command;
	if (cur->fd_in != 0)
		close(cur->fd_in);
	if (cur->fd_out != 1)
		close(cur->fd_out);
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
		if (pipe(pipefd) == -1)
		{
			perror("init fd pipe: ");
			return (-1);
		}
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
	cur->fd_out = 1;
	return (0);
}
