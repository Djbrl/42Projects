/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 03:15:12 by dsy               #+#    #+#             */
/*   Updated: 2023/02/15 17:13:08 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**remove_array_quotes(char **cmd)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	j = 0;
	result = NULL;
	while (cmd[i] != NULL)
	{
		int		len;
		int		k;
		int		l;
		int		m;
		char	*new_str;
		char	**new_result;

		k = 0;
		l = 0;
		m = 0;
		len = strlen(cmd[i]);
		new_str = malloc(sizeof(char) * (len + 1));
		while (l < len)
		{
			if (cmd[i][l] != '"' && cmd[i][l] != '\'')
			{
				new_str[k] = cmd[i][l];
				k++;
			}
			l++;
		}
		new_str[k] = '\0';
		new_result = malloc(sizeof(char *) * (j + 2));
		if (new_result == NULL)
			exit(EXIT_FAILURE);
		while (m < j)
		{
			new_result[m] = result[m];
			m++;
		}
		new_result[j] = new_str;
		new_result[j + 1] = NULL;
		if (result != NULL)
			free(result);
		result = new_result;
		i++;
		j++;
	}
	return (result);
}

static void	exec_paths(t_msh *msh, char **cmds)
{
	int		i;
	char	*cmd;
	char	*path;
	char	**expr;

	expr = remove_array_quotes(cmds);
	i = 0;
	if (access(expr[0], X_OK) == 0)
		execve(expr[0], expr, msh->envp);
	while (msh->paths[i])
	{
		cmd = ft_strjoin(msh->paths[i++], "/");
		path = ft_strjoin(cmd, expr[0]);
		if (access(path, X_OK) == 0)
			execve(path, expr, msh->envp);
		free(cmd);
		free(path);
	}
}

static void	exec_path(t_msh *msh, char **expr)
{
	if (msh->paths == NULL && access(expr[0], X_OK) == 0)
		execve(expr[0], expr, msh->envp);
	exec_paths(msh, expr);
	if (!is_redir(msh->tokens[0]))
		display_error(CMD_ERROR, msh);
	else
		display_cmd_error(expr[0], PATH_ERROR, NULL);
	exit_cmd(msh);
	free_env(msh);
	free_split(expr);
	free_expr(&msh);
	clear_history();
	exit(EXIT_FAILURE);
}

static int	exec_env(t_msh *msh)
{
	int		status;
	char	*tmp;
	char	**redir;
	char	**expr;

	tmp = ft_strdup("PATH");
	if ((!msh->paths || get_data_from_env(msh->env, tmp) == NULL) \
			&& access(msh->tokens[0], X_OK) == -1)
		return (-1);
	status = 0;
	if (msh->exp == NULL || expr_len(msh->exp) == 1)
	{
		check_redirections(msh);
		redir = ft_split_charset(msh->prompt, "<>");
		expr = ft_split(redir[0], ' ');
		free_split(redir);
		exec_path(msh, expr);
		free_split(expr);
	}
	else
		status = pipe_exec(msh);
	return (status);
}

static void	fork_cmd(t_msh *msh)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (exec_env(msh) == -1)
		{
			display_error(CMD_ERROR, msh);
			exit_cmd(msh);
			free_env(msh);
			free_expr(&msh);
			clear_history();
			exit(EXIT_FAILURE);
		}
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

void	evaluate_commands(t_msh *msh)
{
	if (is_builtin(msh->tokens[0], msh) >= 0 && expr_len(msh->exp) == 1)
		exec_builtin(msh, NULL);
	else
		fork_cmd(msh);
}
