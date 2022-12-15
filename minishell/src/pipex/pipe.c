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

static void connect_fds(t_expr **curr_command, t_expr *prev_command, t_expr *commands)
{
	t_expr *cur;
	int			pipefd[2];

	cur = *curr_command;
	while (cur->next != NULL)
	{
		pipe(pipefd);
		cur->fd_out = pipefd[1];
		cur->next->fd_in = pipefd[0];
		prev_command = cur;
		cur = cur->next;
	}
	cur->fd_out = 1;
	cur = commands;
}


static void execute_commands(t_expr **curr_command)
{
	t_expr *cur;

	cur = *curr_command;
	if (cur->fd_in != 0) {
		dup2(cur->fd_in, 0);
		close(cur->fd_in);
	}
	if (cur->fd_out != 1) {
		dup2(cur->fd_out, 1);
		close(cur->fd_out);
	}
	execlp(cur->data, cur->data, NULL);
	exit(EXIT_FAILURE);
}

static void close_fds(t_expr **curr_command)
{
	t_expr *cur;

	cur = *curr_command;
	if (cur->fd_in != 0) {
		close(cur->fd_in);
	}
	if (cur->fd_out != 1) {
		close(cur->fd_out);
	}
}

static void	execute_multi_pipe(t_expr *commands) {
	t_expr	*prev = NULL;
	t_expr	*curr = commands;
	pid_t		pid;
	int			status;

	connect_fds(&curr, prev, commands);
	while (curr != NULL)
	{
		//Child process
		pid = fork();
		if (pid == 0)
			execute_commands(&curr);
		else if (pid < 0)
			exit(EXIT_FAILURE);
		// Parent process
		close_fds(&curr);
		curr = curr->next;
	}
	// Wait for all child processes to finish
	while (wait(&status) > 0) {}
}

static void	init_fds(t_expr **commands, t_expr *prev)
{
	int		pipefd[2];
	t_expr	*cur;

	cur = *commands;
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
	cur->fd_out = 1;
}

int	pipe_exec(t_msh *msh)
{
	t_expr	*prev = NULL;
	t_expr	*commands = msh->exp;

	init_fds(&commands, prev);
	execute_multi_pipe(commands);
	return (0);
}
