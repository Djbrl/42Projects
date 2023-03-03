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

static int	check_rkey(char tmp[HEREDOC_BUF_SIZE], char **field, \
	char *heredoc_buf[HEREDOC_BUF_SIZE], int i)
{
	char	*rkey;

	rkey = NULL;
	if (field[1])
		rkey = remove_spaces(field[1]);
	else
		rkey = remove_spaces(field[0]);
	if (ft_strncmp(tmp, rkey, ft_strlen(rkey)) == 0 \
		&& ft_strlen(tmp) == ft_strlen(rkey))
	{
		free(rkey);
		free(heredoc_buf[i]);
		return (1);
	}
	free(rkey);
	return (0);
}

static char	*check_expand(char *tmp, t_msh *msh)
{
	int		i;
	int		j;
	char	**tokens;
	char	*ret;

	i = 0;
	j = 0;
	tokens = ft_split(tmp, ' ');
	ret = NULL;
	while (tokens[i])
	{
		while (tokens[i][j])
		{
			if (tokens[i][j] == '$')
			{
				char *tmp2 = ft_strdup(get_data_from_env(msh->env, ft_strdup(tokens[i] + j + 1)));
				tokens[i][j] = '\0';
				char *pr = ft_strjoin(tokens[i], tmp2);
				printf("[%s]\n", pr);
				free(tmp2);
				free(pr);
			}
			j++;
		}
		j = 0;
		i++;
	}
	free_split(tokens);
	return (NULL);
}

static void	get_heredoc_lines(char **field, char *heredoc_buf[HEREDOC_LIMIT], t_msh *msh)
{
	char	tmp[HEREDOC_BUF_SIZE];
	int		i;
	int		ret;

	i = 0;
	while (i < HEREDOC_LIMIT - 1)
	{
		write(1, "> ", 2);
		ret = read(0, tmp, HEREDOC_BUF_SIZE - 1);
		if (ret <= 0)
			break ;
		tmp[ret - 1] = '\0';
		if (ret == 0)
			heredoc_buf[i] = ft_strdup("");
		else
			heredoc_buf[i] = ft_strdup(tmp);
		check_expand(tmp, msh);
		if (check_rkey(tmp, field, heredoc_buf, i))
			break ;
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
	get_heredoc_lines(field, heredoc_buf, msh);
	tmp = ft_strdup(field[0]);
	free_split(field);
	ftn_heredoc(tmp, heredoc_buf, msh);
}
