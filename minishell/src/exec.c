/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 03:15:12 by dsy               #+#    #+#             */
/*   Updated: 2022/10/13 12:24:06 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	pipe_cmd(t_msh *msh, int i, int j)
{
	char	**expr;
	char	*tmp;
	char	*cmd;
	char	*path;

	tmp = "/";
	expr = ft_split(msh->expr[i], ' ');
	if (access(expr[0], X_OK & F_OK) == 0)
		execve(expr[0], expr, msh->envp);
	cmd = ft_strjoin(msh->paths[j], tmp);
	path = ft_strjoin(cmd, expr[0]);
	execve(path, expr, msh->envp);
	free(cmd);
	free(path);
	free_split(expr);
	//un fork par proocess dans le while
	return (0);
}

static int	pipe_exec(t_msh *msh)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (msh->expr[i])
	{
		while (msh->paths[j])
			pipe_cmd(msh, i, j++);
		j = 0;
		i++;
	}
	return (0);
}

static int	exec_env(t_msh *msh)
{
	int		i;
	char	*tmp;
	char	*cmd;
	char	*path;
	int		status;

	i = 0;
	status = access(msh->tokens[0], X_OK & F_OK);
	tmp = "/";
	if (!msh->paths)
		return (-1);
	if (msh->expr == NULL)
	{
		while (msh->paths[i])
		{
			if (status == 0)
				execve(msh->tokens[0], msh->tokens, msh->envp);
			cmd = ft_strjoin(msh->paths[i], tmp);
			path = ft_strjoin(cmd, msh->tokens[0]);
			execve(path, msh->tokens, msh->envp);
			free(cmd);
			free(path);
			i++;
		}
	}
	else
		pipe_exec(msh);
	return (-1);
}

void	signal_handler(int sig_n)
{
	if (sig_n == SIGINT)
	{
		write(1, "\n", 1);
		write(1, PROMPTLINE, ft_strlen(PROMPTLINE));
	}
	else
		return ;
}

void	evaluate_commands(t_msh *msh)
{
	pid_t	pid;

	if (is_builtin(msh->tokens[0], msh) >= 0)
		msh->cmd.ptr[is_builtin(msh->tokens[0], msh)](msh->env, msh);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (exec_env(msh) == -1)
				display_error(CMD_ERROR, msh);
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
			display_error(FORK_ERROR, msh);
		else
		{
			waitpid(pid, &g_status, WUNTRACED);
			while (!WIFEXITED(g_status) && !WIFSIGNALED(g_status))
				waitpid(pid, &g_status, WUNTRACED);
			update_exit_status(msh, g_status);
		}
	}
}
