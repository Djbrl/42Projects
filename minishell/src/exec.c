/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 03:15:12 by dsy               #+#    #+#             */
/*   Updated: 2023/02/20 17:11:44 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_quotes(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (i < (int)ft_strlen(str))
	{
		if (str[i] != '"' && str[i] != '\'')
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

static void	copy_result(char **new_result, char **result, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		new_result[i] = result[i];
		i++;
	}
}

char	**remove_array_quotes(char **cmd)
{
	int		i;
	int		j;
	char	*new_str;
	char	**result;
	char	**new_result;

	i = 0;
	j = 0;
	result = NULL;
	while (cmd[i])
	{
		new_result = malloc(sizeof(char *) * (j + 2));
		new_str = remove_quotes(cmd[i]);
		if (new_result == NULL)
			exit(EXIT_FAILURE);
		copy_result(new_result, result, j);
		new_result[j] = new_str;
		new_result[j + 1] = NULL;
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
		if (!ft_isalpha(expr[0][0]))
			break ;
		cmd = ft_strjoin(msh->paths[i++], "/");
		path = ft_strjoin(cmd, expr[0]);
		if (access(path, X_OK) == 0)
			execve(path, expr, msh->envp);
		free(cmd);
		free(path);
	}
	free_split(expr);
}

static void	exec_path(t_msh *msh, char **expr)
{
	int	free_tokens;

	free_tokens = 0;
	if (expr != NULL)
		free_tokens = 1;
	else
		expr = msh->tokens;
	if (msh->paths == NULL && access(expr[0], X_OK) == 0)
		execve(expr[0], expr, msh->envp);
	exec_paths(msh, expr);
	if (!is_redir(msh->tokens[0]))
		display_cmd_error(msh->tokens[0], CMD_ERROR, NULL);
	else
		display_cmd_error(expr[0], PATH_ERROR, NULL);
	temp_exit(msh);
	if (free_tokens)
		free_split(expr);
	exit(EXIT_FAILURE);
}

static int	exec_env(t_msh *msh)
{
	int		status;
	char	*tmp;
	char	**redir;
	char	**expr;

	expr = NULL;
	tmp = ft_strdup("PATH");
	if ((!msh->paths || get_data_from_env(msh->env, tmp) == NULL) \
			&& access(msh->tokens[0], X_OK) == -1)
		return (-1);
	status = 0;
	if (check_redirections(msh) == 0)
		exec_path(msh, expr);
	else
	{
		redir = ft_split_charset(msh->prompt, "<>");
		expr = ft_split(redir[0], ' ');
		free_split(redir);
		exec_path(msh, expr);
		free_split(expr);
	}
	return (status);
}

static void	close_process(t_msh *msh, int pid)
{
	waitpid(pid, &g_status, WUNTRACED);
	if (WIFSIGNALED(g_status) && WTERMSIG(g_status) == SIGINT)
	{
		update_exit_status(msh, 130);
		write(1, "\n", 1);
	}
	else
		update_exit_status(msh, g_status);
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
			temp_exit(msh);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		display_error(FORK_ERROR, msh);
	else
		close_process(msh, pid);
}

void	evaluate_commands(t_msh *msh)
{
	if (is_builtin(msh->tokens[0], msh) >= 0 && expr_len(msh->exp) == 1)
		exec_builtin(msh, NULL);
	else if (msh->exp == NULL || expr_len(msh->exp) == 1)
		fork_cmd(msh);
	else
		pipe_exec(msh);
}
