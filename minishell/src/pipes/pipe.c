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
	if (cur->fd_out != 1)
	{
		dup2(cur->fd_out, 1);
		close(cur->fd_out);
	}
	if (cur->fd_in != 0)
	{
		dup2(cur->fd_in, 0);
		close(cur->fd_in);
	}
	cmd = ft_split(cur->data, ' ');
	check_paths(msh, cmd, cur->data);
	free_split(cmd);
}

static void	check_pid_status(t_expr **cmd, t_msh *msh, int tabpid[100], int count)
{
	t_expr	*curr;
	int		j;

	curr = *cmd;
	if (curr->fd_out != STDOUT_FILENO)
		close(curr->fd_out);
	if (WIFSIGNALED(g_status) && WTERMSIG(g_status) == SIGINT)
	{
		update_exit_status(msh, 130);
		write(1, "\n", 1);
	}
	else
		update_exit_status(msh, g_status);
	if (curr->next == NULL)
	{
		j = 0;
		while (j < count)
		{
			waitpid(tabpid[j], &g_status, WUNTRACED);
			j++;
		}
	}			
}

static int	execute_multi_pipe(t_expr *commands, t_msh *msh)
{
	t_expr	*curr;
	int		count;
	int		tabpid[100];

	count = 0;
	curr = commands;
	connect_fds(&curr, commands);
	while (curr != NULL)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		tabpid[count] = fork();
		if (tabpid[count] == 0)
		{
			execute_commands(&curr, msh);
			if (curr->fd_in != 1)
				close(curr->fd_in);
			temp_exit(msh);
			exit(EXIT_SUCCESS);
		}
		else if (tabpid[count] < 0)
		{
			temp_exit(msh);
			exit(EXIT_FAILURE);
		}
		else
		{
			check_pid_status(&curr, msh, tabpid, count);
			count++;
			curr = curr->next;
		}
	}
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
