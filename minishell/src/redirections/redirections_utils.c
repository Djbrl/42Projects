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
}

static void	find_path(t_msh *msh, char **arg)
{
	int		i;
	char	*tmp;
	char	*path;

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

static void	exec_heredoc(t_msh *msh, char *cmd)
{
	char	**arg;

	arg = ft_split(cmd, ' ');
	free(cmd);
	if (arg[0] != NULL)
	{
		if (access(arg[0], X_OK) == 0)
			execve(arg[0], arg, msh->envp);
		find_path(msh, arg);
	}
	free_split(arg);
	temp_exit(msh);
	exit(EXIT_FAILURE);
}

static void	child_heredoc(int pipefd[2], char *buf[HEREDOC_LIMIT], \
	t_msh *msh, char *cmd)
{
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	print_heredoc(buf);
	free(cmd);
	temp_exit(msh);
	exit(EXIT_SUCCESS);
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
		child_heredoc(pipefd, buf, msh, cmd);
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		waitpid(pid, &g_status, WUNTRACED);
		while (buf[i] != NULL)
			free(buf[i++]);
		exec_heredoc(msh, cmd);
	}
}

static int	check_rkey(char tmp[HEREDOC_BUF_SIZE], char **field, \
	char *heredoc_buf[HEREDOC_BUF_SIZE], int i)
{
	char	*rkey;

	rkey = NULL;
	if (field[1])
		rkey = remove_spaces(field[1]);
	else
		rkey = remove_spaces(field[0]);
	if (ft_strncmp(tmp, rkey, ft_strlen(rkey)) == 0)
	{
		free(rkey);
		free(heredoc_buf[i]);
		return (1);
	}
	free(rkey);
	return (0);
}

static void	get_heredoc_lines(char **field, char *heredoc_buf[HEREDOC_LIMIT])
{
	char	tmp[HEREDOC_BUF_SIZE];
	int		i;
	int		ret;

	i = 0;
	while (i < HEREDOC_LIMIT - 1)
	{
		write(1, "> ", 2);
		ret = read(0, tmp, HEREDOC_BUF_SIZE - 1);
		if (ret <= 0)
			break ;
		tmp[ret - 1] = '\0';
		if (ret == 0)
			heredoc_buf[i] = ft_strdup("");
		else
			heredoc_buf[i] = ft_strdup(tmp);
		if (check_rkey(tmp, field, heredoc_buf, i))
			break ;
		ft_memset(tmp, 0, HEREDOC_BUF_SIZE);
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
	while (i < HEREDOC_LIMIT)
		heredoc_buf[i++] = NULL;
	get_heredoc_lines(field, heredoc_buf);
	tmp = ft_strdup(field[0]);
	free_split(field);
	ftn_heredoc(tmp, heredoc_buf, msh);
}
