/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 02:59:57 by dsy               #+#    #+#             */
/*   Updated: 2020/10/26 15:52:49 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		display_error(char *error)
{
	if (!ft_strcmp(error, CWD_ERROR))
		ft_putnstr("minishell: ", error, NULL, NULL);
	else if (!(ft_strcmp(error, CMD_ERROR)))
		ft_putnstr("minishell: ", g_buffer, CMD_ERROR, NULL);
	else if (!(ft_strcmp(error, FORK_ERROR)))
		ft_putnstr("minishell: ", error, NULL, NULL);
	else if (!(ft_strcmp(error, ENV_ERROR)))
		ft_putnstr("minishell: ", error, NULL, NULL);
	else
		ft_putnstr("minishell: ", "unknown error", NULL, NULL);
	return (0);
}

void	display_cmd_error(char *cmd, char *error, char **args)
{
	if (!ft_strcmp(error, PATH_ERROR))
	{
		ft_putnstr("minishell: ", cmd, " :", args[1]);
		ft_putstr(error);
	}
}

void	display_prompt(int mode)
{
	char *path;

	if (mode == MODE_DIR)
	{
		path = get_currentdir();
		ft_putnstr(path, "$ > ", NULL, NULL);
		free(path);
	}
	else
		ft_putstr("minishell-4.2$ > ");
}
