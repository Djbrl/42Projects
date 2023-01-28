/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:40:28 by dsy               #+#    #+#             */
/*   Updated: 2023/01/28 03:15:19 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	output_redirection(char **field, int mode, int *fd_out)
{
	int		j;
	int		fd;
	char	**expr;

	j = 1;
	fd = -1;
	while (field[j])
	{
		expr = ft_split(field[j], ' ');
		if (mode == 1)
			fd = open(expr[0], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (mode == 2)
			fd = open(expr[0], O_RDWR | O_CREAT | O_APPEND, 0644);
		free_split(expr);
		j++;
	}
	*fd_out = fd;
	free_split(field);
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

static void	exec_heredoc(char *cmd, char **buf, t_msh *msh, int size)
{
	int		pipefd[2];
	char	**arg;
	int		pid;

	arg = NULL;
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
		arg = ft_split(cmd, ' ');
		if (arg[0] != NULL)
		{
			int i = 0;

			while (msh->paths[i])
			{
				char *tmp;
				char *path;
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
}

static void	heredoc(char **field, t_msh *msh)
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
	exec_heredoc(field[0], heredoc_buf, msh, i);
}

static void	input_redirection(char **field, int *fd_in, \
	char *prompt, t_msh *msh)
{
	int		j;
	int		fd;
	char	**expr;

	(void)msh;
	j = 1;
	fd = -1;
	(void)prompt;
	while (field[j])
	{
		expr = ft_split(field[j], ' ');
		fd = open(expr[0], O_RDONLY);
		free_split(expr);
		j++;
	}
	*fd_in = fd;
	free_split(field);
}

static void	heredoc_redirection(char **field, t_msh *msh)
{
	heredoc(field, msh);
	free_split(field);
}

void	apply_redirections(char *expr, int *fd_in, int *fd_out, t_msh *msh)
{
	int		i;
	char	**redirs;

	i = 0;
	redirs = ft_split(expr, ' ');
	while (redirs[i])
	{
		if (ft_strncmp(redirs[i], ">>", ft_strlen(">>")) == 0)
			output_redirection(ft_split_charset(expr, ">"), 2, fd_out);
		else if (ft_strncmp(redirs[i], ">", ft_strlen(">")) == 0)
			output_redirection(ft_split_charset(expr, ">"), 1, fd_out);
		else if (ft_strncmp(redirs[i], "<<", ft_strlen("<<")) == 0)
			heredoc_redirection(ft_split_charset(expr, "<<"), msh);
		else if (ft_strncmp(redirs[i], "<", ft_strlen("<")) == 0)
			input_redirection(ft_split_charset(expr, "<"), fd_in, expr, msh);
		else
			(void)redirs;
		i++;
	}
	free_split(redirs);
}
