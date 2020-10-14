/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 00:15:15 by dsy               #+#    #+#             */
/*   Updated: 2020/10/14 06:56:44 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_data_from_env(t_env_var *env, char *name)
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