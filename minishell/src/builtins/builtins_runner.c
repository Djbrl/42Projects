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

int	msh_echo_runner(t_env_var *env, char **args, t_msh *msh)
{
	int i;

	i = 1;
	(void)msh;
	if (!args[1])
		write(1, "\n", 1);
	else if (!ft_strncmp(args[1], "-n", ft_strlen(args[1])))
	{
		i = 2;
		while (args[i])
		{
			if (i > 2)
				write(1, " ", 1);
			msh_echo(env, args[i++], msh);
		}
	}
	else
	{
		while (args[i])
		{
			if (i > 1)
				write(1, " ", 1);
			msh_echo(env, args[i++], msh);
		}
		write(1, "\n", 1);
	}
	return (1);
}

int	msh_export_runner(t_env_var *env, char **args, t_msh *msh)
{
	int i;

	i = 1;
	(void)msh;
	if (args[1] == NULL)
		msh_env(env, args, msh);
	while (args[i])
	{
		msh_export(env, args[i], msh);
		i++;
	}
	return (1);
}
