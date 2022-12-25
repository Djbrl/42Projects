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

static void	output_redirection(char **field, t_expr *cur, int mode)
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
			fd = open(expr[0], O_RDWR | O_CREAT, 0644);
		if (mode == 2)
			fd = open(expr[0], O_RDWR | O_CREAT | O_APPEND, 0644);
		free_split(expr);
		j++;
	}
	cur->fd_out = fd;
}

static void	input_redirection(char **field, t_expr *cur, int mode)
{
	int		j;
	int		fd;
	char	**expr;
	char	*tmp;

	j = 1;
	fd = -1;
	while (field[j])
	{
		expr = ft_split(field[j], ' ');
		if (mode == 1)
			fd = open(expr[0], O_RDONLY);
		if (mode == 2)
		{
			while (ft_strncmp(tmp, expr[0], ft_strlen(tmp)) != 0)
				get_next_line(0, &tmp);
		}
		free_split(expr);
		j++;
	}
	cur->fd_in = fd;
}

void	apply_redirections(t_expr *cur)
{
	int		i;
	char	**field;
	char	**redirs;

	i = 0;
	(void)redirs;
	field = ft_split(cur->data, '>');
	redirs = ft_split(cur->data, ' ');
	while (redirs[i])
	{
		if (ft_strncmp(redirs[i], ">", ft_strlen(redirs[i])) == 0)
			output_redirection(field, cur, 1);
		if (ft_strncmp(redirs[i], ">>", ft_strlen(redirs[i])) == 0)
			output_redirection(field, cur, 2);
		if (ft_strncmp(redirs[i], "<<", ft_strlen(redirs[i])) == 0)
			input_redirection(field, cur, 2);
		if (ft_strncmp(redirs[i], "<", ft_strlen(redirs[i])) == 0)
			input_redirection(field, cur, 1);
		i++;
	}
	free_split(field);
}
