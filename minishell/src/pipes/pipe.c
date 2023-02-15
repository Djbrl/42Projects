/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:40:28 by dsy               #+#    #+#             */
/*   Updated: 2023/01/10 16:28:50 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*reset FDs to standard on error
**fix display cmd format
**check exit status from forks
**handle multipie if builtin is first command
**handle heredoc
*/

static void	exec_paths(t_msh *msh, char **re, char **cmd, char *field)
{
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	if (is_builtin(cmd[0], msh) >= 0)
		exec_builtin(msh, field);
	else
	{
		while (msh->paths[i])
		{
			if (access(cmd[0], X_OK) == 0)
				execve(cmd[0], re, msh->envp);
			tmp = ft_strjoin(msh->paths[i++], "/");
			path = ft_strjoin(tmp, cmd[0]);
			if (access(path, X_OK) == 0)
				execve(path, re, msh->envp);
			free(tmp);
			free(path);
		}
		if (!is_redir(cmd[0]))
			display_error(CMD_ERROR, msh);
		else
			display_cmd_error(cmd[1], PATH_ERROR, NULL);
	}
}

static void	check_paths(t_msh *msh, char **cmd, char *field)
{
	char	**res;
	char	**re;

	res = ft_split_charset(field, "<>");
	re = ft_split(res[0], ' ');
	free_split(res);
	exec_paths(msh, re, cmd, field);
	free_split(re);
}

static void	execute_commands(t_expr **curr_command, t_msh *msh)
{
	t_expr	*cur;
	char	**cmd;
	int		i;

	i = 0;
	cur = *curr_command;
	while (msh->prompt[i])
	{
		if (msh->prompt[i] == '>' || msh->prompt[i] == '<')
		{
			apply_redirections(cur->data, &cur->fd_in, &cur->fd_out, msh);
			break ;
		}
		i++;
	}
	if (cur->fd_in != 0)
		dup2(cur->fd_in, 0);
	if (cur->fd_out != 1)
		dup2(cur->fd_out, 1);
	cmd = ft_split(cur->data, ' ');
	check_paths(msh, cmd, cur->data);
	free_split(cmd);
}

static int	execute_multi_pipe(t_expr *commands, t_msh *msh)
{
	t_expr	*curr;
	pid_t	pid;

	curr = commands;
	connect_fds(&curr, commands);
	while (curr != NULL)
	{
		g_status = -1;
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		pid = fork();
		if (pid == 0)
		{
			execute_commands(&curr, msh);
			temp_exit(msh);
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			temp_exit(msh);
			exit(34);
		}
		close_fds(&curr);
		curr = curr->next;
	}
	waitpid(pid, &g_status, WUNTRACED);
	if (WIFSIGNALED(g_status) && WTERMSIG(g_status) == SIGINT)
		update_exit_status(msh, 130); 
	else 
		update_exit_status(msh, g_status);
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
	exit_cmd(msh);
	free_expr(&msh);
	free_env(msh);
	exit(EXIT_SUCCESS);
	return (status);
}
