/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:26:32 by dsy               #+#    #+#             */
/*   Updated: 2022/09/15 14:26:34 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_struct(t_msh *msh)
{
	t_cmd_list	*cur;

	if (!msh->input)
		return ;
	while (msh->input->next != NULL)
	{
		cur = msh->input;
		free(msh->input->data);
		msh->input = msh->input->next;
		free(cur);
	}
	if (msh->input)
	{
		free(msh->input->data);
		free(msh->input);
	}
}

static void	free_env(t_msh *msh)
{
	t_env_var	*cur;

	if (!msh->env)
		return ;
	while (msh->env->next != NULL)
	{
		cur = msh->env;
		free(msh->env->data);
		free(msh->env->name);
		msh->env = msh->env->next;
		free(cur);
	}
	if (msh->env)
	{
		free(msh->env->data);
		free(msh->env->name);
		free(msh->env);
	}
}

void	free_split(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	exit_cmd(t_msh *msh)
{
	if (msh->prompt != NULL)
		free(msh->prompt);
	if (msh->tokens != NULL)
		free_split(msh->tokens);
}

void	exit_shell(int status, t_msh *msh)
{
	free_struct(msh);
	free_env(msh);
	exit(status);
}
