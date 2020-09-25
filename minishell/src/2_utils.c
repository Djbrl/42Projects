/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:17:24 by dsy               #+#    #+#             */
/*   Updated: 2020/09/25 15:47:21 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	display_error(char *error)
{
	if (!ft_strcmp(error, CWD_ERROR))
	{
		ft_putstr("minishell: ");
		ft_putstr(error);
	}
	else if (!(ft_strcmp(error, CMD_ERROR)))
	{
		ft_putstr("minishell: ");
		ft_putstr(g_buffer);
		ft_putstr(CMD_ERROR);
	}
	else
	{
		ft_putstr("minishell: ");
		ft_putstr("unknown error");
	}
	exit_shell(EXIT_FAILURE);
}

void	display_prompt(int mode)
{
	char *path;

	if (mode == MODE_DIR)
	{
		path = get_currentdir();
		write(1, path, ft_strlen(path));
		write(1, "$ > ", 4);
		free(path);
	}
	else
	{
		write(1, "minishell-4.2$ > ", 17);
	}
}

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

void	flush_buffer(void)
{
	int i;

	i = 0;
	ft_memset(g_buffer, 0, BUF);
}