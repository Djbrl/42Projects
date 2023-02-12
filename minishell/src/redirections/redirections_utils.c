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
	dup_heredoc(tmp, heredoc_buf, msh);
}
