/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 00:15:15 by dsy               #+#    #+#             */
/*   Updated: 2020/10/19 11:05:42 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_data_from_list(t_env_var *env, char *name)
{
	t_env_var *cur;

	cur = env;
	while (cur->next != NULL)
	{
		ft_putstr("loopin \n");
		if (!ft_strcmp(cur->name, name))
		{
			ft_putnstr(cur->data, " was found\n", 0, 0);
			return (cur->data);
		}
		else
			cur = cur->next;
	}
	if (!ft_strcmp(cur->name, name))
		return (cur->data);
	return (NULL);
}

int		add_var_to_list(t_env_var *env, char *name, char *data)
{
	t_env_var *new;

	new = env;
	if (!env || !name || !data)
		return (0);
	while (new->next != NULL)
	{
		if (!ft_strcmp(new->next->name, name))
		{
			free(new->next->data);
			new->next->data = ft_strdup(data);
			return (1);
		}
		else
			new = new->next;
	}
	if (!(new->next = (t_env_var*)malloc(sizeof(t_env_var))))
		return (0);
	new->next->data = ft_strdup(data);
	new->next->name = ft_strdup(name);
	new->next->next = NULL;
	free(data);
	free(name);
	return (1);
}
