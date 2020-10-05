/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 03:49:17 by dsy               #+#    #+#             */
/*   Updated: 2020/10/05 16:23:51 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_export(t_env_var *env, char *arg)
{
	t_env_var	*new;
	char		*name;
	char		*tmp;
	char		*data;
	int			i;

	new = env;
	i = 0;

	if (arg == NULL || !ft_isalpha(arg[i]))
	{
		ft_putstr("error\n");
		return ;
	}
	while (arg[i])
	{
		if(arg[i] == '=')
		{
			if (arg[i + 1] == 0)
				data = ft_strdup("\0");
			else
				data = ft_strdup(arg + i + 1);
			tmp = ft_strdup(arg);
			tmp[i] = 0;
			name = ft_strdup(tmp);
			free(tmp);
			break;
		}
		i++;
	}
	while (new->next != NULL)
	{
		if (!ft_strcmp(new->next->name, name))
		{
			free(new->next->data);
			new->next->data = ft_strdup(data);
			return ;
		}
		else
			new = new->next;
	}
	new->next = (t_env_var*)malloc(sizeof(t_env_var));
	new->next->data = ft_strdup(data);
	new->next->name = ft_strdup(name);
	new->next->next = NULL;
	free(data);
	free(name);
}


void	msh_env(t_env_var *env, char **args)
{
	t_env_var *cur;

	cur = env;
	while (cur->next != NULL)
	{
		if (cur->name && cur->data)
			ft_putnstr(cur->name, "=", cur->data, "\n");
		cur = cur->next;
	}
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