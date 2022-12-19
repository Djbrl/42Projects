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

static void	check_paths(t_msh *msh, char **cmd)
{
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	while (msh->paths[i])
	{
		tmp = ft_strjoin(msh->paths[i++], "/");
		path = ft_strjoin(tmp, cmd[0]);
		execve(path, cmd, msh->envp);
		free(tmp);
		free(path);
	}
}

static void execute_commands(t_expr **curr_command, t_msh *msh)
{
	t_expr	*cur;
	char	**cmd;

	cur = *curr_command;
	if (cur->fd_in != 0) {
		dup2(cur->fd_in, 0);
		close(cur->fd_in);
	}
	if (cur->fd_out != 1) {
		dup2(cur->fd_out, 1);
		close(cur->fd_out);
	}
	cmd = ft_split(cur->data, ' ');
	check_paths(msh, cmd);
	free_split(cmd);
	exit(EXIT_FAILURE);
}

static int	execute_multi_pipe(t_expr *commands, t_msh *msh) {
	t_expr	*curr = commands;
	pid_t		pid;
	int			status;

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
	while (wait(&status) > 0){}
	return (0);
}

int	pipe_exec(t_msh *msh)
{
	t_expr	*prev;
	t_expr	*commands;
	int		status;

	i = 0;
	prev = NULL;
	commands = msh->exp;
	if (init_fds(&commands, prev) == - 1)
		return (-1);
	status = execute_multi_pipe(commands, msh);
	return (status);
}
