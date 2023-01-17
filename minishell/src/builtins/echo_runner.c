/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_runner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:13:26 by dsy               #+#    #+#             */
/*   Updated: 2023/01/16 16:37:46 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 ****************************STATIC FUNCTIONS****************************
 * refactor these functions to read expri] properly
 */

static void	ftn_echo_runner(t_msh **msh, t_env_var **var, int i, char *field)
{
	t_msh		*m;
	t_env_var	*v;
	char		**tmp;
	char		**expr;

	m = *msh;
	v = *var;
	
	tmp = ft_split_charset(m->prompt, "<>");
	expr = ft_split(field, ' ');
	free_split(tmp);
	i = 1;
	while (expr[i])
	{
		if (i > 1)
			write(1, " ", 1);
		if (expr[i] != NULL)
			msh_echo(v, remove_spaces(expr[i]), m);
		i++;
	}
	write(1, "\n", 1);
	free_split(expr);
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

static int	run_echo(t_msh **msh, t_env_var **env, char *field)
{
	t_env_var	*e;
	t_msh		*m;
	int			i;
	int			exit;
	char		**expr;
	char		**tokens;

	i = 1;
	exit = 0;
	m = *msh;
	e = *env;
	tokens = ft_split(field, ' ');
	while (tokens[i])
	{
		expr = ft_split_charset(tokens[i], "<>");
		if (i > 2)
			write(1, " ", 1);
		if (i != 1)
			exit = msh_echo(e, remove_spaces(expr[0]), m);
		i++;
		free_split(expr);
	}
	free_split(tokens);
	return (exit);
}

/*
 ****************************STATIC FUNCTIONS****************************
 */

//only if field isnt NULL
int	msh_echo_runner(t_env_var *env, t_msh *msh, char *field)
{
	int		i;
	int		exit_status;
	char	**tokens;

	i = 1;
	exit_status = 0;
	if (field == NULL)
		tokens = msh->tokens;
	else
		tokens = ft_split(field, ' ');
	if (!tokens[1])
		write(1, "\n", 1);
	else if (ft_strncmp(tokens[1], "-n", ft_strlen(tokens[1])) == 0)
		run_echo(&msh, &env, field);
	else if (ft_strncmp(tokens[1], "-n", ft_strlen(tokens[1])) != 0 \
			&& check_n_option(tokens[1]))
		run_echo(&msh, &env, field);
	else
		ftn_echo_runner(&msh, &env, i, field);
	exit_cmd(msh);
	free_split(tokens);
	return (update_exit_status(msh, exit_status));
}
