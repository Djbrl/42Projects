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
		if (expr[i] == '>' && expr[i + 1] != '>')
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

void	apply_sneaky_redir(char **redir, int *fd_in, int *fd_out, t_msh *msh)
{
	int	ret;

	ret = sneaky_redir(*redir);
	if (ret == 1)
		output_redirection(ft_split_charset(*redir, ">"), 1, fd_out);
	else if (ret == 2)
		output_redirection(ft_split_charset(*redir, ">"), 2, fd_out);
	else if (ret == 4)
		input_redirection(ft_split_charset(*redir, "<"), fd_in, *redir, msh);
	else if (ret == 3)
		heredoc_redirection(redirs, ft_split_charset(redirs[i], "<<"), msh);
	else
		(void)ret;
}

void	apply_redirections(char *expr, int *fd_in, int *fd_out, t_msh *msh)
{
	int		i;
	int		ret;
	char	**redirs;

	i = -1;
	redirs = ft_split(expr, ' ');
	while (redirs[++i])
	{
		if (redirs[i + 1] && has_quote(redirs[i + 1]))
			continue ;
		ret = sneaky_redir(redirs[i]);
		else if (ft_strncmp(redirs[i], ">>", ft_strlen(redirs[i])) == 0)
			output_redirection(ft_split_charset(expr, ">"), 2, fd_out);
		else if (ft_strncmp(redirs[i], ">", ft_strlen(redirs[i])) == 0)
			output_redirection(ft_split_charset(expr, ">"), 1, fd_out);
		else if (ft_strncmp(redirs[i], "<<", ft_strlen(redirs[i])) == 0)
			heredoc_redirection(redirs, ft_split_charset(expr, "<<"), msh);
		else if (ft_strncmp(redirs[i], "<", ft_strlen(redirs[i])) == 0)
			input_redirection(ft_split_charset(expr, "<"), fd_in, expr, msh);
		else if (ret)
			apply_sneaky_redir(&redirs[i], fd_in, fd_out, msh);
		else
			(void)ret;
	}
	free_split(redirs);
}
