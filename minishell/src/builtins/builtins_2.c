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
		return (display_error(ENV_ERROR, msh));
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
	if (!valid && !add_var_to_list(env, name, data))
		return (display_error(ENV_ERROR, msh));
	return (1);
}

int	msh_env(t_env_var *env, char **args)
{
	t_env_var *cur;

	cur = env;
	while (cur->next != NULL)
	{
		if (cur->name && cur->data && (ft_strcmp(cur->name, "init")))
			ft_putnstr(cur->name, "=", cur->data, "\n");
		cur = cur->next;
	}
	if (cur->name && cur->data && (ft_strcmp(cur->name, "init")))
		ft_putnstr(cur->name, "=", cur->data, "\n");
	return (1);
}

int	msh_unset(t_env_var *env, char **args)
{
	t_env_var *tmp;
	t_env_var *prev;

	tmp = env;
	if (tmp == NULL || !args[1])
		return (0);
	while (tmp->next != NULL && (ft_strcmp(args[1], tmp->name) != 0))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!(ft_strcmp(args[1], tmp->name)))
	{
		if (tmp->next != NULL)
			prev->next = tmp->next;
		else if (tmp->next == NULL)
			prev->next = NULL;
		else
			return (1);
		free(tmp);
	}
	return (1);
}
