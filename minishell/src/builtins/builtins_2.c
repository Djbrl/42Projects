/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 03:49:17 by dsy               #+#    #+#             */
/*   Updated: 2020/12/07 18:00:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		msh_export(t_env_var *env, char *arg, t_msh *msh)
{
	char		*name;
	char		*tmp;
	char		*data;
	int			i;
	int			valid;

	i = 0;
	if (arg == NULL || !ft_isalpha(arg[0]))
	{
		// exit_cmd(msh);
		return (display_error(ENV_ERROR, msh));
	}
	while (arg[i++])
		if (arg[i] == '=')
		{
			valid = 1;
			if (arg[i + 1] == 0)
				data = ft_strdup("\0");
			else
				data = ft_strdup(arg + i + 1);
			tmp = ft_strdup(arg);
			tmp[i] = 0;
			name = ft_strdup(tmp);
			free(tmp);
			break ;
		}
	if (!valid || !add_var_to_env(env, name, data))
	{
		// exit_cmd(msh);
		return (display_error(ENV_ERROR, msh));
	}
	// exit_cmd(msh);
	return (1);
}

int	msh_env(t_env_var *env, char **args, t_msh *msh)
{
	t_env_var *cur;

	(void)msh;
	cur = env;
	while (cur->next != NULL)
	{
		if (cur->name && cur->data && (ft_strncmp(cur->name, "init", ft_strlen(cur->name))))
			ft_putnstr(cur->name, "=", cur->data, "\n");
		cur = cur->next;
	}
	if (cur->name && cur->data && (ft_strncmp(cur->name, "init", ft_strlen(cur->name))))
		ft_putnstr(cur->name, "=", cur->data, "\n");
	exit_cmd(msh);
	return (1);
}

int	msh_unset(t_env_var *env, char **args, t_msh *msh)
{
	t_env_var *tmp;
	t_env_var *prev;

	(void)msh;
	tmp = env;
	if (tmp == NULL || !args[1])
	{
		exit_cmd(msh);
		return (0);
	}
	while (tmp->next != NULL && (ft_strncmp(args[1], tmp->name, ft_strlen(args[1])) != 0))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!(ft_strncmp(args[1], tmp->name, ft_strlen(args[1]))))
	{
		if (tmp->next != NULL)
			prev->next = tmp->next;
		else if (tmp->next == NULL)
			prev->next = NULL;
		else
		{
			exit_cmd(msh);
			return (1);
		}
		free(tmp);
	}
	exit_cmd(msh);
	return (1);
}

int	msh_exit(t_env_var *env, char **args, t_msh *msh)
{
	(void)env;
	exit_cmd(msh);
	exit_shell(EXIT_SUCCESS, msh);
	return (1);
}