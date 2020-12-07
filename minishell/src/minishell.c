/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:58:00 by user42            #+#    #+#             */
/*   Updated: 2020/12/07 17:47:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_loop(t_msh *msh)
{
	char	*line;
	char	**args;

	ft_putstr("Welcome in minishell.\n");
	init_env(msh);
	signal(SIGINT, signal_handler);
	while (1)
	{
		display_prompt(MODE_DEFAULT, msh);
		flush_buffer(msh);
		read(0, msh->g_buffer, BUF);
		msh->g_buffer[ft_strlen(msh->g_buffer) - 1] = 0;
		if (!(ft_strcmp(msh->g_buffer, "exit")))
			exit_shell(EXIT_SUCCESS);
		line = strdup(msh->g_buffer);
		if (line[0] != 0)
		{
			args = ft_split(line, ' ');
			evaluate_commands(args, msh);
			flush_buffer(msh);
			free(line);
		}
	}
}