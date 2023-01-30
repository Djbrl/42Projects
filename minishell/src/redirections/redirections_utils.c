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

char	**check_redirections(t_msh *msh)
{
	int		in;
	int		out;
	char	**expr;
	char	**tmp;

	in = -1;
	out = -1;
	tmp = ft_split_charset(msh->prompt, "<>");
	expr = ft_split(tmp[0], ' ');
	apply_redirections(msh->prompt, &in, &out, msh);
	free_split(tmp);
	if (in != -1)
		dup2(in, 0);
	if (out != -1)
		dup2(out, 1);
	return (expr);
}

static void	print_heredoc(char **heredoc_buf, int size)
{
	int	i;

	i = 0;
	while (i < size)
		printf("%s\n", heredoc_buf[i++]);
	i = 0;
	while (i < size)
		free(heredoc_buf[i++]);
}

static void	exec_heredoc(t_msh *msh, char *cmd)
{
	char	**arg;
	char	*tmp;
	char	*path;
	int		i;

	i = 0;
	arg = ft_split(cmd, ' ');
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
	exit(EXIT_FAILURE);
}

static void	ftn_heredoc(char *cmd, char **buf, t_msh *msh, int size)
{
	int		pipefd[2];
	int		pid;

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		print_heredoc(buf, size);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		waitpid(pid, &g_status, WUNTRACED);
		exec_heredoc(msh, cmd);
	}
}

/*
** make sure this pipes into the next command
*/
void	heredoc(char **field, t_msh *msh)
{
	char	**heredoc_buf;
	int		i;
	char	*tmp;
	char	*rkey;

	i = 0;
	heredoc_buf = malloc(sizeof(char *));
	while (1)
	{
		write(1, "> ", 2);
		get_next_line(0, &tmp);
		heredoc_buf[i++] = ft_strdup(tmp);
		heredoc_buf = realloc(heredoc_buf, sizeof(char *) * (i + 1));
		if (field[1])
			rkey = remove_spaces(field[1]);
		else
			rkey = remove_spaces(field[0]);
		if (ft_strncmp(tmp, rkey, ft_strlen(rkey)) == 0)
		{
			free(rkey);
			free(tmp);
			break ;
		}
		free(rkey);
		free(tmp);
	}
	heredoc_buf[i] = NULL;
	ftn_heredoc(field[0], heredoc_buf, msh, i);
}
