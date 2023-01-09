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

static void	exec_paths(t_msh *msh, char **re, char **cmd)
{
	char	*path;
	char	*tmp;
	int		i;
	int		status;

	i = 0;
	if (is_builtin(msh->tokens[0], msh) >= 0)
	{
		int in = -1, out = -1, saved_stdin = dup(0), saved_stdout = dup(0);
		apply_redirections(msh->prompt, &in, &out);
		saved_stdin = dup(0);
		saved_stdout = dup(1);
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
		msh->cmd.ptr[is_builtin(msh->tokens[0], msh)](msh->env, msh);
		dup2(saved_stdin, 0);
		dup2(saved_stdout, 1);
		close(saved_stdin);
		close(saved_stdout);
	}
	else
	{
		// if (is_builtin(cmd[0], msh) >= 0)
		// {
		// 	msh->cmd.ptr[is_builtin(cmd[0], msh)](msh->env, msh);
		// 	return ;
		// }
		status = access(cmd[0], X_OK);
		while (msh->paths[i])
		{
			if (status == 0)
				execve(cmd[0], re, msh->envp);
			tmp = ft_strjoin(msh->paths[i++], "/");
			path = ft_strjoin(tmp, cmd[0]);
			status = access(path, X_OK);
			if (status == 0)
				execve(path, re, msh->envp);
			free(tmp);
			free(path);
		}
	}
}

static void	check_paths(t_msh *msh, char **cmd, char *arg)
{
	char	**res;
	char	**re;

	res = ft_split_charset(arg, "<>");
	re = ft_split(res[0], ' ');
	free_split(res);
	exec_paths(msh, re, cmd);
}

static void	execute_commands(t_expr **curr_command, t_msh *msh)
{
	t_expr	*cur;
	char	**cmd;

	cur = *curr_command;
	apply_redirections(cur->data, &cur->fd_in, &cur->fd_out);
	if (cur->fd_in != 0)
	{
		dup2(cur->fd_in, 0);
		close(cur->fd_in);
	}
	if (cur->fd_out != 1)
	{
		dup2(cur->fd_out, 1);
		close(cur->fd_out);
	}
	cmd = ft_split(cur->data, ' ');
	check_paths(msh, cmd, cur->data);
	free_split(cmd);
	exit(EXIT_FAILURE);
}

static int	execute_multi_pipe(t_expr *commands, t_msh *msh)
{
	t_expr	*curr;
	pid_t	pid;

	curr = commands;
	connect_fds(&curr, commands);
	while (curr != NULL)
	{
		pid = fork();
		if (pid == 0)
			execute_commands(&curr, msh);
		else if (pid < 0)
			exit(EXIT_FAILURE);
		close_fds(&curr);
		curr = curr->next;
	}
	waitpid(pid, &g_status, WUNTRACED);
	return (0);
}

int	pipe_exec(t_msh *msh)
{
	t_expr	*prev;
	t_expr	*commands;
	int		status;

	prev = NULL;
	commands = msh->exp->next;
	if (init_fds(&commands, prev) == -1)
		return (-1);
	status = execute_multi_pipe(commands, msh);
	return (status);
}
