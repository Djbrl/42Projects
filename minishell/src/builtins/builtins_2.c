/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 03:49:17 by dsy               #+#    #+#             */
/*   Updated: 2020/09/27 06:57:19 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_export(t_env_var *env, char **args)
{
	t_env_var *new ;

	new = env;
	while (new->next != NULL)
		new = new->next;
	new->next = (t_env_var*)malloc(sizeof(t_env_var*));
	new->next->data = ft_strdup(args[2]);
	ft_putnstr(new->next->data, "\n", NULL, NULL);
	new->next->name = ft_strdup(args[1]);
	ft_putnstr(new->next->name, "\n", NULL, NULL);
	ft_putnstr(new->next->data, "\t", new->next->name, "\n");
	new->next->next = NULL;
}

void	msh_env(t_env_var *env, char **args)
{
	t_env_var *cur;

	cur = env;
	while (cur->next != NULL)
	{
		ft_putnstr(cur->name, "\t", cur->data, "\n");
		cur = cur->next;
	}
	ft_putnstr(cur->name, "\t", cur->data, "\n");	
}