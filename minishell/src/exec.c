/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 03:15:12 by dsy               #+#    #+#             */
/*   Updated: 2023/01/10 16:28:21 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**check_redirections(t_msh *msh)
{
	int		in;
	int		out;
	char	**expr;
	char	**tmp;

	in = -1;
	out = -1;
	tmp = ft_split_charset(msh->prompt, "<>");
	expr = ft_split(tmp[0], ' ');
	apply_redirections(msh->prompt, &in, &out);
	free_split(tmp);
	if (in != -1)
		dup2(in, 0);
	if (out != -1)
		dup2(out, 1);
	return (expr);
}

static void	exec_path(t_msh *msh, char **expr)
{
	int		i;
	char	*cmd;
	char	*path;

	i = 0;
	if (msh->paths == NULL)
		execve(expr[0], expr, msh->envp);
	while (msh->paths[i])
	{
		if (access(msh->tokens[0], X_OK) == 0)
			execve(expr[0], expr, msh->envp);
		cmd = ft_strjoin(msh->paths[i++], "/");
		path = ft_strjoin(cmd, expr[0]);
		if (access(path, X_OK) == 0)
			execve(path, expr, msh->envp);
		free(cmd);
		free(path);
	}
	display_error(CMD_ERROR, msh);
	free_split(expr);
	exit(EXIT_FAILURE);
}

static int	exec_env(t_msh *msh)
{
	int		status;
	char	*tmp;

	tmp = ft_strdup("PATH");
	if ((!msh->paths || get_data_from_env(msh->env, tmp) == NULL) \
		&& access(msh->tokens[0], X_OK) == -1)
		return (-1);
	status = 0;
	if (msh->exp == NULL || expr_len(msh->exp) == 1)
		exec_path(msh, check_redirections(msh));
	else
		status = pipe_exec(msh);
	return (status);
}

/*
** change builtin arguement to take current prompt
*/
void	exec_builtin(t_msh *msh, char *field)
{
	int	in;
	int	out;

	in = -1;
	out = -1;
	apply_redirections(msh->prompt, &in, &out);
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
	(void)field;
	msh->cmd.ptr[is_builtin(msh->tokens[0], msh)](msh->env, msh, NULL);
	dup2(msh->std_in, 0);
	dup2(msh->std_out, 1);
}

void	evaluate_commands(t_msh *msh)
{
	pid_t	pid;

	if (is_builtin(msh->tokens[0], msh) >= 0 && expr_len(msh->exp) == 1)
		exec_builtin(msh, NULL);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (exec_env(msh) == -1)
			{
				display_error(CMD_ERROR, msh);
				exit(EXIT_FAILURE);
			}
			else
				exit(13);
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
