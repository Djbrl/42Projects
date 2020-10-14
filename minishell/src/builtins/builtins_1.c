/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:19:12 by dsy               #+#    #+#             */
/*   Updated: 2020/10/14 06:51:29 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		msh_echo(t_env_var *env, char *arg)
{
	int i;
	char *var;
	char *tmp;

	i = 0;

	if (arg[0] != '$')
		while (arg[i])
			write(1, &arg[i++], 1);
	else
	{
		var = ft_substr(arg, 1, (ft_strlen(arg) - 1));
		tmp = ft_strdup(get_data_from_env(env, var));
		if (tmp != NULL)
			while (tmp[i])
				write(1, &tmp[i++], 1);
		else
			write(1, "\n", 1);
		free(tmp);
		//look up in the env list
		//echo the data
		/* code */
	}
	
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
