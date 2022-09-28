/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:19:12 by dsy               #+#    #+#             */
/*   Updated: 2020/10/26 14:55:24 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int static	var_name_len(char *name)
{
	int	i;

	i = 0;
	while (name[i] != '$' && name[i])
		i++;
	return (i);
}

int	msh_echo(t_env_var *env, char *arg, t_msh *msh)
{
	int		i;
	char	*var;
	char	*tmp;

	i = 0;
	(void)msh;
	if (arg[0] == '$')
	{
		while (arg[i])
		{
			if (arg[i] == '$' && arg[i + 1] == '$')
				write(1, "$", 1);
			else
			{
				if (arg[i] == '$' && ft_isalpha(arg[i + 1]))
				{
					var = ft_substr(arg, i + 1, var_name_len(arg + i + 1));
					tmp = ft_strdup(get_data_from_env(env, var));
					if (tmp != NULL)
						ft_putstr(tmp);
					else
						write(1, "\n", 1);
					free(tmp);
				}
			}
			i++;
		}
	}
	else
		ft_putstr(arg);
	return (1);
}

int	msh_cd(t_env_var *env, t_msh *msh)
{
	int	ret;
	char	*path;

	path = NULL;
	if (msh->tokens[1])
	{
		if (msh->tokens[1][0] == '$')
			path = expand_var(msh, msh->tokens[1]);
		else
			path = ft_strdup(msh->tokens[1]);
	}
	if (!msh->tokens[1])
	{
		if (msh->home != NULL)
			ret = chdir(msh->home);
		else
			ret = chdir("/");
	}
	else
		ret = chdir(path);
	if (ret < 0)
		display_cmd_error("cd", PATH_ERROR, msh->tokens);
	if (path)
		free(path);
	exit_cmd(msh);
	return (1);
}

int	msh_pwd(t_env_var *env, t_msh *msh)
{
	char	cwd[1024];

	(void)msh;
	ft_putnstr(getcwd(cwd, sizeof(cwd)), "\n", NULL, NULL);
	exit_cmd(msh);
	return (1);
}

int	msh_help(t_env_var *env, t_msh *msh)
{
	(void)msh;
	ft_putstr("\nminishell-4.2 commands: \n\necho\t\t: a clone of bash echo\n");
	ft_putstr("cd\t\t: a clone of bash cd\n");
	ft_putstr("pwd\t\t: a clone of bash pwd\n");
	ft_putstr("export\t\t: a clone of bash export\n");
	ft_putstr("env\t\t: a clone of bash env\n");
	ft_putstr("unset\t\t: a clone of bash unset\n");
	ft_putstr("help\t\t: show this list\n");
	exit_cmd(msh);
	return (1);
}
