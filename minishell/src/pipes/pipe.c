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

static void	fail_command(char **expr)
{
	if (!is_redir(expr[0]))
		display_cmd_error(expr[0], CMD_ERROR, NULL);
	else
		display_cmd_error(expr[1], PATH_ERROR, NULL);
}

static void	exec_command(char *path, char *tmp, char **re, char **env)
{
	if (access(path, X_OK) == 0)
		execve(path, re, env);
	free(tmp);
	free(path);
}

static void	ftn_exec_paths(t_msh *msh, char **expr, char **re)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	reload_path(msh);
	while (msh->paths[i])
	{
		if (!ft_isalpha(expr[0][0]))
			break ;
		if (access(expr[0], X_OK) == 0)
			execve(expr[0], re, msh->envp);
		tmp = ft_strjoin(msh->paths[i++], "/");
		path = ft_strjoin(tmp, expr[0]);
		exec_command(path, tmp, re, msh->envp);
	}
}

static void	exec_paths(t_msh *msh, char **re, char **cmd, char *field)
{
	char	**expr;

	expr = remove_array_quotes(cmd);
	if (re == NULL)
		re = expr;
	if (is_builtin(expr[0], msh) >= 0)
		exec_builtin(msh, field);
	else
	{
		ftn_exec_paths(msh, expr, re);
		fail_command(expr);
	}
	free_split(expr);
}

static void	check_paths(t_msh *msh, char **cmd, int redir, char *field)
{
	char	**res;
	char	**re;

	if (redir == 0)
		exec_paths(msh, NULL, cmd, field);
	else
	{
		res = ft_split_charset(field, "<>");
		re = ft_split(res[0], ' ');
		free_split(res);
		exec_paths(msh, re, cmd, field);
		free_split(re);
	}
}

static void	dup_command(t_expr **commands)
{
	t_expr	*cur;

	cur = *commands;
	write(1, "ayo?\n", 5);
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
}

static void	execute_commands(t_expr **curr_command, t_msh *msh)
{
	t_expr	*cur;
	char	**cmd;
	int		i;
	int		redir;

	i = 0;
	redir = 0;
	cur = *curr_command;
	while (msh->tokens[i])
	{
		if (msh->tokens[i][0] == '>' || msh->tokens[i][0] == '<')
		{
			apply_redirections(cur->data, &cur->fd_in, &cur->fd_out, msh);
			redir = 1;
			break ;
		}
		i++;
	}
	dup_command(curr_command);
	cmd = ft_split(cur->data, ' ');
	check_paths(msh, cmd, redir, cur->data);
	free_split(cmd);
}

static void	check_pid_status(t_expr **cmd, t_msh *msh, int pid[100], int count)
{
	t_expr	*curr;
	int		j;

	curr = *cmd;
	if (curr->fd_in != STDIN_FILENO)
		close(curr->fd_in);
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
			waitpid(pid[j], &g_status, WUNTRACED);
			j++;
		}
	}
}

static void	child_pipe(t_expr *curr, t_msh *msh)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	execute_commands(&curr, msh);
	temp_exit(msh);
	exit(EXIT_SUCCESS);
}

static void	exit_fork(t_msh *msh)
{
	temp_exit(msh);
	exit(EXIT_FAILURE);
}

static int	execute_multi_pipe(t_expr *commands, t_msh *msh)
{
	t_expr	*curr;
	int		count;
	int		pid[100];

	count = 0;
	curr = commands;
	while (curr != NULL && count < 100)
	{
		pid[count] = fork();
		if (pid[count] == 0)
			child_pipe(curr, msh);
		else if (pid[count] < 0)
			exit_fork(msh);
		else
		{
			check_pid_status(&curr, msh, pid, count);
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
