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
	free(path);
	return (ft_strdup(path + last_slash + 1));
}

/*
** The 'ft_strlen() + 1' is meant to check if there are any extra characters after the builtin name string
*/
int	is_builtin(char *s, t_msh *msh)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!ft_strncmp(msh->cmd.name[i], s, ft_strlen(msh->cmd.name[i]) + 1))
			return (i);
		i++;
	}
	return (-1);
}

void	flush_buffer(t_msh *msh)
{
	ft_memset(msh->g_buffer, 0, BUF);
}

void	read_buffer(t_msh *msh)
{
	int	signal;

	signal = read(0, msh->g_buffer, BUF);
	if (signal == CTRL_D_SIGNAL)
	{
		flush_buffer(msh);
		exit_cmd(msh);
		exit_shell(SUCCESS, msh);
	}
	msh->g_buffer[ft_strlen(msh->g_buffer) - 1] = 0;
}
