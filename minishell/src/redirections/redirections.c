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

int	which_redir(char *redir, char *which, char dir, int mode)
{
	if (mode == 1)
		if (ft_strncmp(redir, which, ft_strlen(which)) == 0 || \
			((ft_strlen(redir) >= 2 && redir[ft_strlen(redir) - 2] == dir) && \
			(ft_strlen(redir) >= 1 && redir[ft_strlen(redir) - 1] == dir)))
			return (1);
	if (mode == 2)
		if (ft_strncmp(redir, which, ft_strlen(which)) == 0 || \
			(ft_strlen(redir) >= 1 && redir[ft_strlen(redir) - 1] == dir))
			return (1);
	if (mode == 3)
		if (ft_strncmp(redir, which, ft_strlen(which)) == 0 || \
			((ft_strlen(redir) >= 2 && redir[ft_strlen(redir) - 2] == dir) && \
			(ft_strlen(redir) >= 1 && redir[ft_strlen(redir) - 1] == dir)))
			return (1);
	if (mode == 4)
		if (ft_strncmp(redir, which, ft_strlen(which)) == 0 || \
			(ft_strlen(redir) >= 1 && redir[ft_strlen(redir) - 1] == dir))
			return (1);
	return (0);
}

static int	check_quotes(char *redir, int *i)
{
	int	ret;

	ret = 0;
	if (redir && has_quote(redir))
		ret = 1;
	if (ret == 1)
	{
		*i = *i + 1;
		return (1);
	}
	return (0);
}

static int	handle_redir(char *expr, int *fds[2], int *i, t_msh *msh)
{
	char	**redir;
	int		ret;

	ret = 0;
	redir = ft_split(expr, ' ');
	if (which_redir(redir[*i], ">>", '>', 1))
		output_redirection(ft_split_charset(expr, ">"), 2, fds[1]);
	else if (which_redir(redir[*i], ">", '>', 2))
		output_redirection(ft_split_charset(expr, ">"), 1, fds[1]);
	else if (which_redir(redir[*i], "<<", '<', 3))
		heredoc_redirection(redir, ft_split_charset(expr, "<<"), msh);
	else if (which_redir(redir[*i], "<", '<', 4))
		input_redirection(ft_split_charset(expr, "<"), fds[0], expr, msh);
	else
		ret = 1;
	free_split(redir);
	if (ret == 0)
		return (0);
	return (1);
}

void	apply_redirections(char *expr, int *fd_in, int *fd_out, t_msh *msh)
{
	int		i;
	char	**redirs;
	int		*fds[2];

	i = 0;
	fds[0] = fd_in;
	fds[1] = fd_out;
	redirs = ft_split(expr, ' ');
	while (redirs[i])
	{
		check_quotes(redirs[i + 1], &i);
		if (is_redir_token(redirs[i]))
			handle_redir(expr, fds, &i, msh);
		else
		{
			if (is_sneaky_token(expr, &i, fds, msh) == 0)
			{
				i++;
				continue ;
			}
		}
		i++;
	}
	free_split(redirs);
}
