/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:19:12 by dsy               #+#    #+#             */
/*   Updated: 2020/09/27 01:56:03 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_echo_n(char **args)
{
	int i;
	int j;

	i = 2;
	j = 0;
	while (args[i])
	{
		if (i > 2)
			write(1, " ", 1);
		while (args[i][j])
		{
			write(1, &args[i][j], 1);
			j++;
		}
		j = 0;
		i++;
		if (args[i + 1])
			write(1, " ", 1);
	}
}

void	msh_echo(char **args)
{
	int i;
	int j;

	j = 0;
	i = 1;
	if (!ft_strcmp(args[1], "-n"))
		msh_echo_n(args);
	else
	{
		while (args[i])
		{
			if (i > 1)
				write(1, " ", 1);
			while (args[i][j])
				write(1, &args[i][j++], 1);
			j = 0;
			i++;
		}
		write(1, "\n", 1);
	}
}

void	msh_cd(char **args)
{
	int ret;

	ret = chdir(args[1]);
	if(ret < 0)
		display_cmd_error("cd", PATH_ERROR, args);
}

void	msh_pwd(char **args)
{
	char cwd[1024];

	ft_putnstr(getcwd(cwd, sizeof(cwd)), "\n", NULL, NULL);
}

void	msh_help(char **args)
{
	ft_putstr("\nminishell-4.2 commands: \n\necho\t\t: a clone of bash echo\n");
	ft_putstr("cd\t\t: a clone of bash cd\n");	
	ft_putstr("pwd\t\t: a clone of bash pwd\n");
	ft_putstr("help\t\t: show this list\n");
}