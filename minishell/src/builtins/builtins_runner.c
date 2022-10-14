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

static int	list_exports(t_env_var *env, t_msh *msh)
{
	t_env_var	*e;
	int			l;

	(void)msh;
	e = env;
	l = ft_strlen(e->name);
	while (e->next != NULL)
	{
		if (e->name && e->data && ft_strncmp(e->name, "init", l) != 0 && \
			ft_strncmp(e->name, "?", l))
		{
			write(1, "export ", 7);
			ft_putnstr(e->name, "=", e->data, "\n");
		}
		e = e->next;
	}
	if (e->name && e->data && (ft_strncmp(e->name, "init", l) != 0 && \
		ft_strncmp(e->name, "?", l)))
	{
		write(1, "export ", 7);
		ft_putnstr(e->name, "=", e->data, "\n");
	}
	exit_cmd(msh, 0);
	return (1);
}

int	msh_echo_runner(t_env_var *env, t_msh *msh)
{
	int	i;

	i = 1;
	(void)msh;
	if (!msh->tokens[1])
		write(1, "\n", 1);
	else if (!ft_strncmp(msh->tokens[1], "-n", ft_strlen(msh->tokens[1])))
	{
		i = 2;
		while (msh->tokens[i])
		{
			if (i > 2)
				write(1, " ", 1);
			msh_echo(env, msh->tokens[i++], msh);
		}
	}
	else
		ftn_echo_runner(&msh, &env, i);
	exit_cmd(msh, 0);
	return (1);
}

int	msh_export_runner(t_env_var *env, t_msh *msh)
{
	int	i;

	i = 1;
	(void)msh;
	if (msh->tokens[1] == NULL)
	{
		list_exports(env, msh);
		exit_cmd(msh, 0);
		return (1);
	}
	while (msh->tokens[i])
	{
		msh_export(env, msh->tokens[i], msh);
		i++;
	}
	exit_cmd(msh, 0);
	return (1);
}

int	msh_cd_runner(t_env_var *env, t_msh *msh)
{
	(void)msh;
	if (msh->nb_tokens > 2)
	{
		printf("Too many args for cd command\n");
		exit_cmd(msh, 0);
		return (1);
	}
	else
		msh_cd(env, msh);
	return (1);
}
