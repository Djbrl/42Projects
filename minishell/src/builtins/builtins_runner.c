/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_runner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:13:26 by dsy               #+#    #+#             */
/*   Updated: 2020/12/07 18:10:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_echo_runner(t_env_var *env, char **args)
{
	int i;

	i = 1;
	if (!args[1])
		write(1, "\n", 1);
	else if (!ft_strcmp(args[1], "-n"))
	{
		i = 2;
		while (args[i])
		{
			if (i > 2)
				write(1, " ", 1);
			msh_echo(env, args[i++]);
		}
	}
	else
	{
		while (args[i])
		{
			if (i > 1)
				write(1, " ", 1);
			msh_echo(env, args[i++]);
		}
		write(1, "\n", 1);
	}
	return (1);
}

int	msh_export_runner(t_env_var *env, char **args, t_msh *msh)
{
	int i;

	i = 1;
	if (args[1] == NULL)
		msh_env(env, args);
	while (args[i])
	{
		msh_export(env, args[i], msh);
		i++;
	}
	return (1);
}
