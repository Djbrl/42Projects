/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:40:28 by dsy               #+#    #+#             */
/*   Updated: 2023/01/10 16:29:14 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define HEREDOC_BUF_SIZE 1024
#define HEREDOC_LIMIT 100

static void	print_heredoc(char *heredoc_buf[HEREDOC_LIMIT])
{
	int	i;

	i = 0;
	while (heredoc_buf[i] != NULL)
	{
		printf("%s\n", heredoc_buf[i]);
		free(heredoc_buf[i++]);
	}
	free(heredoc_buf[i]);
}

static void	exec_heredoc(t_msh *msh, char *cmd)
{
	char	**arg;
	char	*tmp;
	char	*path;
	int		i;

	i = 0;
	arg = ft_split(cmd, ' ');
	free(cmd);
	if (arg[0] != NULL)
	{
		i = 0;
		while (msh->paths[i])
		{
			if (access(arg[0], X_OK) == 0)
				execve(arg[0], arg, msh->envp);
			tmp = ft_strjoin(msh->paths[i++], "/");
			path = ft_strjoin(tmp, arg[0]);
			if (access(path, X_OK) == 0)
				execve(path, arg, msh->envp);
			free(tmp);
			free(path);
		}
	}
	free_split(arg);
	exit_cmd(msh);
	free_env(msh);
	free_expr(&msh);
	exit(EXIT_FAILURE);
}

static void	ftn_heredoc(char *cmd, char *buf[HEREDOC_LIMIT], t_msh *msh)
{
	int		pipefd[2];
	int		pid;
	int		i;

	i = 0;
	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		print_heredoc(buf);
		free(cmd);
		exit_cmd(msh);
		free_env(msh);
		free_expr(&msh);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		waitpid(pid, &g_status, WUNTRACED);
		while (buf[i] != NULL)
			free(buf[i++]);
		free(buf[i]);
		exec_heredoc(msh, cmd);
	}
}

static void	get_heredoc_lines(char **field, char *heredoc_buf[HEREDOC_LIMIT])
{
	char	tmp[HEREDOC_BUF_SIZE];
	char	*rkey;
	int		i;

	i = 0;
	while (i < HEREDOC_LIMIT - 1)
	{
		write(1, "> ", 2);
		if (!fgets(tmp, HEREDOC_BUF_SIZE, stdin))
			break;
		heredoc_buf[i] = ft_strdup(tmp);
		if (field[1])
			rkey = remove_spaces(field[1]);
		else
			rkey = remove_spaces(field[0]);
		if (ft_strncmp(tmp, rkey, ft_strlen(rkey)) == 0)
		{
			free(rkey);
			break ;
		}
		free(rkey);
		i++;
	}
	heredoc_buf[i] = NULL;
}

void	heredoc(char **field, t_msh *msh)
{
	char	*heredoc_buf[HEREDOC_LIMIT];
	char	*tmp;
	int		i;

	i = 0;
	while (i < 15)
		heredoc_buf[i++] = NULL;
	get_heredoc_lines(field, heredoc_buf);
	tmp = ft_strdup(field[0]);
	free_split(field);
	ftn_heredoc(tmp, heredoc_buf, msh);
}
