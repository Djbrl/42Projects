/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:40:28 by dsy               #+#    #+#             */
/*   Updated: 2023/01/10 16:29:08 by dsy              ###   ########.fr       */
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

static void	print_heredoc(char **heredoc, int size)
{
	int	i;

	i = 0;
	// while (i < size)
	// 	printf("%s\n", heredoc[i++]);
	// i = 0;
	while (i < size)
		free(heredoc[i++]);
}

static void	heredoc(char *expr, t_msh *msh, int fd_in, int fd_out)
{
	char	*tmp;
	char	*str;
	char	*heredoc[100];
	int		i;

	tmp = NULL;
	i = 0;
	while (1)
	{
		write(1, "> ", 2);
		str = remove_spaces(expr);
		get_next_line(0, &tmp);
		heredoc[i++] = ft_strdup(tmp);
		if (ft_strncmp(tmp, str, ft_strlen(tmp)) == 0 && tmp[0] != '\0')
		{
			free(str);
			free(tmp);
			break ;
		}
		free(tmp);
		free(str);
	}
//UNDER CONSTRUCTION
//using a fork pipe to feed the result of heredoc into the associated command
	// close(msh->std_in);
	// close(msh->std_out);
	// msh->std_in = dup(0);
	// msh->std_out = dup(1);
	// //resetting fds
	// int pid = fork();
	// if (pid == 0)
	// {}
	// else
	// //
	// waitpid(pid, &g_status, WUNTRACED);
	// //second fork
	// int pid2 = fork();
	// if (pid2 == 0)
	// {}
	// else
	// //
	// waitpid(pid2, &g_status, WUNTRACED);
	
	print_heredoc(heredoc, i);
}

static void	input_redirection(char **field, int mode, int *fd_in, char *prompt, t_msh *msh)
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
		// if (mode == 1)
		fd = open(expr[0], O_RDONLY);
	if (mode == 2)
	{
		// *fd_in = dup(0);
		// fd = open(, O_RDONLY);
		heredoc(field[1], msh, *fd_in, *fd_out);
	}
		free_split(expr);
		j++;
	}
	*fd_in = fd;
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
		 	input_redirection(ft_split_charset(expr, "<<"), 2, fd_in, expr, msh);
		else if (ft_strncmp(redirs[i], "<", ft_strlen("<")) == 0)
			input_redirection(ft_split_charset(expr, "<"), 1, fd_in, expr, msh);
		else
			(void)redirs;
		i++;
	}
	free_split(redirs);
}
