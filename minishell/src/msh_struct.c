/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 03:10:39 by dsy               #+#    #+#             */
/*   Updated: 2020/09/27 03:42:07 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_msh(t_msh *msh)
{
	msh->cmd.name[0] = "echo";
	msh->cmd.name[1] = "help";
	msh->cmd.name[2] = "cd";
	msh->cmd.name[3] = "pwd";
	msh->cmd.ptr[0] = msh_echo;
	msh->cmd.ptr[1] = msh_help;
	msh->cmd.ptr[2] = msh_cd;
	msh->cmd.ptr[3] = msh_pwd;
}
