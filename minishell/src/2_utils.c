/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:17:24 by dsy               #+#    #+#             */
/*   Updated: 2020/09/27 03:20:07 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_currentdir(void)
{
	char	*path;
	char	cwd[1024];
	int		i;
	int		last_slash;

	i = 0;
	last_slash = 0;
	path = ft_strdup(getcwd(cwd, sizeof(cwd)));
	if (!path)
	{
		display_error(CWD_ERROR);
		return (NULL);
	}
	while (path[i])
	{
		if (path[i] == '/')
			last_slash = i;
		i++;
	}
	return (ft_strdup(path + last_slash + 1));
}

int		is_builtin(char *s, t_msh *msh)
{
	int i;

	i = 0;
	while (msh->cmd.name[i])
	{
		if (!ft_strcmp(msh->cmd.name[i], s))
			return (i);
		i++;
	}
	return (-1);
}

void	flush_buffer(void)
{
	int i;

	i = 0;
	ft_memset(g_buffer, 0, BUF);
}