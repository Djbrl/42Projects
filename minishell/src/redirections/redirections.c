/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:40:28 by dsy               #+#    #+#             */
/*   Updated: 2022/11/04 18:40:30 by dsy              ###   ########.fr       */
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

static void	heredoc(char *expr)
{
	char	*tmp;

	tmp = NULL;
	while (1)
	{
		get_next_line(0, &tmp);
		if (ft_strncmp(tmp, expr, ft_strlen(tmp)) == 0)
			break ;
		free(tmp);
	}
}

static void	input_redirection(char **field, int mode, int *fd_in)
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
			fd = open(expr[0], O_RDONLY);
		if (mode == 2)
			heredoc(expr[0]);
		free_split(expr);
		j++;
	}
	*fd_in = fd;
	free_split(field);
}

void	apply_redirections(char *expr, int *fd_in, int *fd_out)
{
	int		i;
	char	**redirs;

	i = 0;
	(void)redirs;
	redirs = ft_split(expr, ' ');
	while (redirs[i])
	{
		if (ft_strncmp(redirs[i], ">", ft_strlen(redirs[i])) == 0)
			output_redirection(ft_split_charset(expr, ">"), 1, fd_out);
		if (ft_strncmp(redirs[i], ">>", ft_strlen(redirs[i])) == 0)
			output_redirection(ft_split_charset(expr, ">"), 2, fd_out);
		// if (ft_strncmp(redirs[i], "<<", ft_strlen(redirs[i])) == 0)
		// 	input_redirection(ft_split_charset(expr, "<<"), 2, fd_in);
		if (ft_strncmp(redirs[i], "<", ft_strlen(redirs[i])) == 0)
			input_redirection(ft_split_charset(expr, "<"), 1, fd_in);
		i++;
	}
}
