/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 03:10:39 by dsy               #+#    #+#             */
/*   Updated: 2020/12/07 17:55:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_msh(t_msh *msh)
{
	msh->cmd.name[0] = "echo";
	msh->cmd.name[1] = "help";
	msh->cmd.name[2] = "cd";
	msh->cmd.name[3] = "pwd";
	msh->cmd.name[4] = "export";
	msh->cmd.name[5] = "env";
	msh->cmd.name[6] = "unset";
	msh->cmd.ptr[0] = msh_echo_runner;
	msh->cmd.ptr[1] = msh_help;
	msh->cmd.ptr[2] = msh_cd;
	msh->cmd.ptr[3] = msh_pwd;
	msh->cmd.ptr[4] = msh_export_runner;
	msh->cmd.ptr[5] = msh_env;
	msh->cmd.ptr[6] = msh_unset;
}

void	init_env(t_msh *msh)
{
	msh->env.next = NULL;
	if (!(msh->env.next = (t_env_var*)(malloc(sizeof(t_env_var*)))))
	{
		display_error(ENV_ERROR, msh);
		free(msh->env.next);
	}
	msh->env.name = ft_strdup("init");
	msh->env.data = ft_strdup("init");
	msh->env.next = NULL;
}
