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

/*
****************************STATIC FUNCTIONS****************************
*/

static void	ftn_echo_runner(t_msh **msh, t_env_var **var, int i)
{
	t_msh		*m;
	t_env_var	*v;

	m = *msh;
	v = *var;
	while (m->tokens[i])
	{
		if (i > 1)
			write(1, " ", 1);
		msh_echo(v, m->tokens[i++], m);
	}
	write(1, "\n", 1);
}

static int	check_n_option(char *opt)
{
	int	i;

	i = 1;
	while (opt[i])
	{
		if (opt[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static int	run_echo(t_msh **msh, t_env_var **env)
{
	t_env_var	*e;
	t_msh		*m;
	int			i;
	int			exit;

	i = 1;
	exit = 0;
	m = *msh;
	e = *env;
	while (m->tokens[i])
	{
		if (i > 2)
			write(1, " ", 1);
		if (i != 1)
			exit = msh_echo(e, m->tokens[i], m);
		i++;
	}
	return (exit);
}

/*
****************************STATIC FUNCTIONS****************************
*/

int	msh_echo_runner(t_env_var *env, t_msh *msh)
{
	int	i;
	int	exit_status;

	i = 1;
	exit_status = 0;
	(void)msh;
	if (!msh->tokens[1])
		write(1, "\n", 1);
	else if (ft_strncmp(msh->tokens[1], "-n", ft_strlen(msh->tokens[1])) == 0)
		run_echo(&msh, &env);
	else if (ft_strncmp(msh->tokens[1], "-n", ft_strlen(msh->tokens[1])) != 0 \
		&& check_n_option(msh->tokens[1]))
		run_echo(&msh, &env);
	else
		ftn_echo_runner(&msh, &env, i);
	exit_cmd(msh);
	return (update_exit_status(msh, exit_status));
}
