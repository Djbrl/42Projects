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

static void	init_fn_ptr(t_msh *msh)
{
	msh->cmd.name[0] = "echo";
	msh->cmd.name[1] = "help";
	msh->cmd.name[2] = "cd";
	msh->cmd.name[3] = "pwd";
	msh->cmd.name[4] = "export";
	msh->cmd.name[5] = "env";
	msh->cmd.name[6] = "unset";
	msh->cmd.name[7] = "exit";
	msh->cmd.ptr[0] = msh_echo_runner;
	msh->cmd.ptr[1] = msh_help;
	msh->cmd.ptr[2] = msh_cd_runner;
	msh->cmd.ptr[3] = msh_pwd;
	msh->cmd.ptr[4] = msh_export_runner;
	msh->cmd.ptr[5] = msh_env;
	msh->cmd.ptr[6] = msh_unset;
	msh->cmd.ptr[7] = msh_exit;
}

void	init_msh(t_msh *msh, char **envp)
{
	init_fn_ptr(msh);
	msh->prompt = NULL;
	msh->tokens = NULL;
	if (!envp)
		msh->envp = NULL;
	msh->envp = envp;
	msh->paths = NULL;
	msh->home = NULL;
	msh->user = NULL;
	msh->default_path = NULL;
	msh->full_path = NULL;
	parse_envp(msh);
}

void	init_ast(t_msh *msh)
{
	msh->ast = (malloc(sizeof(t_ast)));
	msh->ast->data = NULL;
	msh->ast->left = NULL;
	msh->ast->right = NULL;
}

void	init_env(t_msh *msh)
{
	msh->env = (malloc(sizeof(t_env_var)));
	msh->env->name = ft_strdup("init");
	msh->env->data = ft_strdup("init");
	msh->env->next = NULL;
}
