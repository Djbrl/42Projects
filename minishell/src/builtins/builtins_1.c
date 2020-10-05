/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:19:12 by dsy               #+#    #+#             */
/*   Updated: 2020/10/05 16:27:49 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		msh_echo(t_env_var *env, char *arg)
{
	int i;

	i = 0;
	while (arg[i])
		write(1, &arg[i++], 1);
}

void		msh_cd(t_env_var *env, char **args)
{
	int ret;

	ret = chdir(args[1]);
	if (ret < 0)
		display_cmd_error("cd", PATH_ERROR, args);
}

void		msh_pwd(t_env_var *env, char **args)
{
	char cwd[1024];

	ft_putnstr(getcwd(cwd, sizeof(cwd)), "\n", NULL, NULL);
}

void		msh_help(t_env_var *env, char **args)
{
	ft_putstr("\nminishell-4.2 commands: \n\necho\t\t: a clone of bash echo\n");
	ft_putstr("cd\t\t: a clone of bash cd\n");
	ft_putstr("pwd\t\t: a clone of bash pwd\n");
	ft_putstr("export\t\t: a clone of bash export\n");
	ft_putstr("env\t\t: a clone of bash env\n");
	ft_putstr("unset\t\t: a clone of bash unset\n");
	ft_putstr("help\t\t: show this list\n");
}
