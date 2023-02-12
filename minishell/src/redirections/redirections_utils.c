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

static void	exec_heredoc_aux(t_msh *msh, char *path, char **arg)
{
	if (access(path, X_OK) == 0)
		execve(path, arg, msh->envp);
}

static void	exec_heredoc(t_msh *msh, char *cmd)
{
	char	**arg;
	char	*tmp;
	char	*path;
	int		i;

	arg = ft_split(cmd, ' ');
	free(cmd);
	if (arg[0] != NULL)
	{
		i = 0;
		while (msh->paths[i])
		{
			exec_heredoc_aux(msh, arg[0], arg);
			tmp = ft_strjoin(msh->paths[i++], "/");
			path = ft_strjoin(tmp, arg[0]);
			exec_heredoc_aux(msh, path, arg);
			free(tmp);
			free(path);
		}
	}
	free_split(arg);
	temp_exit(msh);
	exit(EXIT_FAILURE);
}

static void	run_heredoc_child(char *buf[HEREDOC_LIMIT], \
	int pipefd[2], t_msh *msh)
{
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	print_heredoc(buf);
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
		run_heredoc_child(buf, pipefd, msh);
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

static void	get_heredoc_input(char tmp[HEREDOC_BUF_SIZE])
{
	int	ret;

	ret = 0;
	write(1, "> ", 2);
	ret = read(0, tmp, HEREDOC_BUF_SIZE - 1);
	tmp[ret - 1] = '\0';
}

static char	*get_rkey(char **field)
{
	char	*rkey;

	rkey = remove_spaces(field[0]);
	if (field[1])
	{
		free(rkey);
		rkey = remove_spaces(field[1]);
	}
	return (rkey);
}

static void	get_heredoc_lines(char **field, char *heredoc_buf[HEREDOC_LIMIT])
{
	char	tmp[HEREDOC_BUF_SIZE];
	char	*rkey;
	int		i;

	i = 0;
	rkey = get_rkey(field);
	while (i < HEREDOC_LIMIT - 1)
	{
		get_heredoc_input(tmp);
		if (ft_strlen(tmp) == 0)
			heredoc_buf[i] = ft_strdup("");
		else
			heredoc_buf[i] = ft_strdup(tmp);
		if (ft_strncmp(tmp, rkey, ft_strlen(rkey)) == 0)
		{
			free(rkey);
			free(heredoc_buf[i]);
			break ;
		}
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
