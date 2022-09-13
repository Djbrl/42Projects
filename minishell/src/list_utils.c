/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 00:15:15 by dsy               #+#    #+#             */
/*   Updated: 2020/12/07 17:41:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_data_from_env(t_env_var *env, char *name)
{
	t_env_var *cur;

	cur = env;
	while (cur->next != NULL)
	{
		if (!ft_strcmp(cur->name, name))
			return (cur->data);
		else
			cur = cur->next;
	}
	if (!ft_strcmp(cur->name, name))
		return (cur->data);
	return (NULL);
}

int		add_var_to_env(t_env_var *env, char *name, char *data)
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

int		add_cmd_to_list(t_cmd_list *input, char *data)
{
	t_cmd_list *new;

	new = input;
	if (!input || !data)
		return (0);
	while (new->next != NULL)
			new = new->next;
	if (!(new->next = (t_cmd_list*)malloc(sizeof(t_cmd_list))))
		return (0);
	new->next->data = ft_strdup(data);
	new->next->next = NULL;
	free(data);
	return (1);
}
