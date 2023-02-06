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
		{
    		if (more_than_one_word(tokens[i]))
				msh_echo(*var, ft_strdup(tokens[i]), *msh);
			else if (!ft_strncmp(tokens[i], "$", ft_strlen(tokens[i])))
				printf("$");
			else if (!ft_strncmp(tokens[i], "$$", ft_strlen(tokens[i])))
				printf(SHELL_PID_ERROR);
			else
				msh_echo(*var, remove_spaces(tokens[i]), *msh);
		}
		i++;
	}
	write(1, "\n", 1);
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
		if (ft_strcmp(tokens[i], "-n") == 0)
		{
			i++;
			continue ;
		}
		if (i != 1)
		{
			if (more_than_one_word(tokens[i]))
				exit = msh_echo(e, ft_strdup(tokens[i]), m);
			else
				exit = msh_echo(e, remove_spaces(tokens[i]), m);
		}
		if (tokens[i + 1] != NULL && i != 1)
			write(1, " ", 1);
		i++;
	}
	return (exit);
}

static void	check_options(t_msh *msh, t_env_var *env, char **tokens)
{
	int	i;

	//make sure that echo $ works, stop omitting - char too, fix $?+$?
	i = 1;
	if (!tokens[1])
		write(1, "\n", 1);
	else if (ft_strncmp(tokens[1], "-n", ft_strlen("-n")) == 0)
		run_echo(&msh, &env, tokens);
	else
		ftn_echo_runner(&msh, &env, i, tokens);
	exit_cmd(msh);
}

/*
****************************STATIC FUNCTIONS****************************
*/

//only if field isnt NULL
int	msh_echo_runner(t_env_var *env, t_msh *msh, char *field)
{
	int		exit_status;
	int		free_tokens;
	char	**tokens;

	free_tokens = 0;
	exit_status = 0;
	if (field == NULL)
		tokens = msh->tokens;
	else
	{
		tokens = ft_split(field, ' ');
		free_tokens = 1;
	}
	check_options(msh, env, tokens);
	if (free_tokens)
		free_split(tokens);
	return (update_exit_status(msh, exit_status));
}
