/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:17:24 by dsy               #+#    #+#             */
/*   Updated: 2020/12/07 17:48:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_currentdir(t_msh *msh)
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
		display_error(CWD_ERROR, msh);
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

void	flush_buffer(t_msh *msh)
{
	int i;

	i = 0;
	ft_memset(msh->g_buffer, 0, BUF);
}
