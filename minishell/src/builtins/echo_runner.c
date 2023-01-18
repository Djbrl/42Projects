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

static int	is_redir(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>' || str[i] == '<')
			return (1);
		i++;
	}
	return (0);
}

static void	ftn_echo_runner(t_msh **msh, t_env_var **var, int i, char **tokens)
{
	i = 1;
	(void)msh;
	(void)var;
	while (tokens[i] != NULL)
	{
		if (is_redir(tokens[i]))
			break ;
		if (i > 1)
			write(1, " ", 1);
		if (tokens[i] != NULL)
			msh_echo(*var, remove_spaces(tokens[i]), *msh);
		i++;
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

static int	run_echo(t_msh **msh, t_env_var **env, char **tokens)
{
	t_env_var	*e;
	t_msh		*m;
	int			i;
	int			exit;

	i = 1;
	exit = 0;
	m = *msh;
	e = *env;
	while (tokens[i])
	{
		if (is_redir(tokens[i]))
			break ;
		if (i > 2)
			write(1, " ", 1);
		if (i != 1)
			exit = msh_echo(e, remove_spaces(tokens[i]), m);
		i++;
	}
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
	int		free;

	free = 0;
	i = 1;
	exit_status = 0;
	if (field == NULL)
		tokens = msh->tokens;
	else
	{
		tokens = ft_split(field, ' ');
		free = 1;
	}
	if (!tokens[1])
		write(1, "\n", 1);
	else if (ft_strncmp(tokens[1], "-n", ft_strlen(tokens[1])) == 0)
		run_echo(&msh, &env, tokens);
	else if (ft_strncmp(tokens[1], "-n", ft_strlen(tokens[1])) != 0 \
			&& check_n_option(tokens[1]))
		run_echo(&msh, &env, tokens);
	else
		ftn_echo_runner(&msh, &env, i, tokens);
	exit_cmd(msh);
	if (free)
		free_split(tokens);
	return (update_exit_status(msh, exit_status));
}
