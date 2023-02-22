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

static int sneaky_redir(char *expr)
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
		if (ft_strncmp(redirs[i], ">>", ft_strlen(">>")) == 0)
			output_redirection(ft_split_charset(expr, ">"), 2, fd_out);
		else if (ft_strncmp(redirs[i], ">", ft_strlen(">")) == 0)
			output_redirection(ft_split_charset(expr, ">"), 1, fd_out);
		else if (ft_strncmp(redirs[i], "<<", ft_strlen("<<")) == 0)
			heredoc_redirection(redirs, ft_split_charset(expr, "<<"), msh);
		else if (ft_strncmp(redirs[i], "<", ft_strlen("<")) == 0)
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
