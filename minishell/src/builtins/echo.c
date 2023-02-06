/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:19:12 by dsy               #+#    #+#             */
/*   Updated: 2023/01/10 16:27:22 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	more_than_one_word(char *echo)
{
	char	**expr;
	int		i;

	i = 0;
	if (!echo)
		return (0);
	expr = ft_split(echo, ' ');
	while (expr[i] != NULL)
		i++;
	if (i > 1)
	{
		free_split(expr);
		return (1);
	}
	free_split(expr);
	return (0);
}

/*
****************************STATIC FUNCTIONS****************************
*/

static int	var_name_len(char *name)
{
	int	i;

	i = 0;
	while (name[i] != '$' && name[i])
		i++;
	return (i);
}

static void	ftn_msh_echo(char **var, char **arg, t_env_var **env, int i)
{
	char		*t;
	char		*v;
	char		*a;
	t_env_var	*e;

	a = *arg;
	v = *var;
	e = *env;
	v = ft_substr(a, i + 1, var_name_len(a + i + 1));
	t = ft_strdup(get_data_from_env(e, v));
	if (t != NULL)
		ft_putstr(t);
	else
		write(1, "\n", 1);
	free(t);
}

/*
****************************STATIC FUNCTIONS****************************
*/

/*
** MSH ECHO is ran by msh_echo_runner
*/
static int echo_dollar_check(char *arg, t_env_var *env)
{
	int i;
	char *var;

	i = 0;
	if (arg[0] == '$')
	{
		while (arg[i])
		{
			if (arg[i] == '$' && (ft_isalpha(arg[i + 1]) \
				|| arg[i + 1] == '?'))
				ftn_msh_echo(&var, &arg, &env, i);
			i++;
		}
	}
	else
		ft_putstr(arg);
	return (0);
}

int msh_echo(t_env_var *env, char *arg, t_msh *msh)
{
	char **args;
	int i;

	(void)msh;
	if (more_than_one_word(arg) == 1)
	{

		args = ft_split(arg, ' ');
		i = 0;
		while (args[i])
		{
			echo_dollar_check(args[i], env);
			if (args[i + 1])
				ft_putchar(' ');
			i++;
		}
		free_split(args);
	}
	else
		echo_dollar_check(arg, env);
	free(arg);
	return (0);
}
