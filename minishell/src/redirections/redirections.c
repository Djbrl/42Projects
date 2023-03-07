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
	int	q;

	q = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			q++;
		i++;
	}
	if ((q % 2) != 0)
		return (1);
	return (0);
}

static int	check_quotes(char **redir, int *i)
{
	int	ret;
	int	j;

	j = *i;
	ret = 0;
	if (j - 1 < 0)
		return (0);
	if (redir[*i - 1] && has_quote(redir[*i]))
		ret = 1;
	if (ret == 1)
	{
		*i = *i + 1;
		return (1);
	}
	return (0);
}

static int	is_heredoc(char *token, char **redirs)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = ft_split_charset(token, "<<");
	while (tmp[i])
		i++;
	free_split(tmp);
	if (i > 1)
	{
		while (token[j + 1])
		{
			if (token[j] == '<' && (token[j + 1] == '<'))
			{
				free_split(redirs);
				return (1);
			}
			j++;
		}
	}
	return (0);
}

static int	skip_quoted_redir(int quotes, int *i)
{
	if (quotes)
	{
		*i = *i + 1;
		return (1);
	}
	return (0);
}

void	apply_redirections(char *expr, int *fd_in, int *fd_out, t_msh *msh)
{
	int		i;
	char	**redirs;
	int		*fds[2];
	int		quotes;

	i = 0;
	fds[0] = fd_in;
	fds[1] = fd_out;
	redirs = ft_split(expr, ' ');
	while (redirs[i])
	{
		quotes = check_quotes(redirs, &i);
		if (skip_quoted_redir(quotes, &i))
			continue ;
		if (is_redir_token(redirs[i], redirs) && !quotes)
			handle_redir(expr, fds, &i, msh);
		else
		{
			is_heredoc(redirs[i], redirs);
			is_sneaky_token(expr, &i, fds, msh);
		}
		i++;
	}
	free_split(redirs);
}
