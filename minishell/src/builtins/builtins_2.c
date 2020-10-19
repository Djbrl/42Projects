/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 03:49:17 by dsy               #+#    #+#             */
/*   Updated: 2020/10/19 11:41:19 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_export(t_env_var *env, char *arg)
{
	char		*name;
	char		*tmp;
	char		*data;
	int			i;

	i = 0;
	if (arg == NULL || !ft_isalpha(arg[0]))
		return (display_error(ENV_ERROR));
	while (arg[i++])
		if (arg[i] == '=')
		{
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
	if (!add_var_to_list(env, name, data))
		return (display_error(ENV_ERROR));
	return (1);
}

void	msh_env(t_env_var *env, char **args)
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
}

//FIX UNSET
void	msh_unset(t_env_var *env, char **args)
{
	t_env_var *tmp;
	t_env_var *prev;

	tmp = env;
	if (tmp == NULL || !args[1])
		return ;
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
			return ;
		free(tmp);
	}
}
