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

static void	heredoc_redirection(char **redirs, char **field, t_msh *msh)
{
	free_split(redirs);
	heredoc(field, msh);
	free_split(field);
}

static int	sneaky_redir(char *expr)
{
	int	i;

	i = 0;
	while (expr[i])
	{
		if (expr[i] == '>' && (expr[i + 1] != '>' || expr[i + 1] == 0))
			return (1);
		if (expr[i] == '<' && expr[i + 1] != '<')
			return (4);
		if (expr[i] == '>' && expr[i + 1] == '>' && expr[i + 2] != '>')
			return (2);
		if (expr[i] == '<' && expr[i + 1] == '<' && expr[i + 2] != '<')
			return (3);
		i++;
	}
	return (0);
}

static int	has_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

static int	which_redir(char *redir, char *which, char dir, int mode)
{
	if (mode == 1)
		if (ft_strncmp(redir, which, ft_strlen(which)) == 0 || \
			(redir[ft_strlen(redir) - 2] == dir && \
			redir[ft_strlen(redir) - 1] == dir))
			return (1);
	if (mode == 2)
		if (ft_strncmp(redir, which, ft_strlen(which)) == 0 || \
			redir[ft_strlen(redir) - 1] == dir)
			return (1);
	if (mode == 3)
		if (ft_strncmp(redir, which, ft_strlen(which)) == 0 || \
			(redir[ft_strlen(redir) - 2] == dir && \
			redir[ft_strlen(redir) - 1] == dir))
			return (1);
	if (mode == 4)
		if (ft_strncmp(redir, which, ft_strlen(which)) == 0 || \
			redir[ft_strlen(redir) - 1] == dir)
			return (1);
	return (0);
}

void	apply_redirections(char *expr, int *fd_in, int *fd_out, t_msh *msh)
{
	int		i;
	int		ret;
	char	**redirs;

	i = 0;
	ret = 0;
	redirs = ft_split(expr, ' ');
	while (redirs[i])
	{
		if (redirs[i + 1] && has_quote(redirs[i + 1]))
		{
			i++;
			continue ;
		}
		if (which_redir(redirs[i], ">>", '>', 1))
			output_redirection(ft_split_charset(expr, ">"), 2, fd_out);
		else if (which_redir(redirs[i], ">", '>', 2))
			output_redirection(ft_split_charset(expr, ">"), 1, fd_out);
		else if (which_redir(redirs[i], "<<", '<', 3))
			heredoc_redirection(redirs, ft_split_charset(expr, "<<"), msh);
		else if (which_redir(redirs[i], "<", '<', 4))
			input_redirection(ft_split_charset(expr, "<"), fd_in, expr, msh);
		else
		{
			ret = sneaky_redir(redirs[i]);
			if (ret == 1)
				output_redirection(ft_split_charset(redirs[i], ">"), 1, fd_out);
			else if (ret == 2)
				output_redirection(ft_split_charset(redirs[i], ">"), 2, fd_out);
			else if (ret == 3)
				heredoc_redirection(redirs, ft_split_charset(redirs[i], "<<"), msh);
			else if (ret == 4)
				input_redirection(ft_split_charset(redirs[i], "<"), fd_in, redirs[i], msh);
			else
			{
				i++;
				continue ;
			}
		}
		i++;
	}
	free_split(redirs);
}
