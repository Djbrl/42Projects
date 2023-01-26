/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:26:32 by dsy               #+#    #+#             */
/*   Updated: 2023/01/26 14:16:26 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_envar(t_msh *msh)
{
	if (msh->home != NULL)
		free(msh->home);
	if (msh->user != NULL)
		free(msh->user);
	if (msh->full_path != NULL)
		free(msh->full_path);
	if (msh->default_path != NULL)
		free(msh->default_path);
	if (msh->paths != NULL)
		free_split(msh->paths);
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
	free_envar(msh);
}

static void	ftn_exit(t_msh *msh, int status, char **arr)
{
	exit_cmd(msh);
	free_env(msh);
	if (msh->exp != NULL)
	{
		free(msh->exp->data);
		free(msh->exp);
	}
	if (arr != NULL)
		free_split(arr);
	clear_history();
	exit(status);
}

int	exit_shell(t_msh *msh, char *field)
{
	char	**arr;
	int		exit_status;

	arr = NULL;
	exit_status = 0;
	if (field == NULL)
		ftn_exit(msh, g_status, NULL);
	else
		arr = ft_split(field, ' ');
	if ((arr[1] && ft_atoi(arr[1]) == 0 && ft_strncmp(arr[1], "0", 1) != 0) \
		|| !ft_isnum(arr[1]) || (ft_isnum(arr[1]) && ft_strlen(arr[1]) > 9))
	{
		ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
		ftn_exit(msh, 2, arr);
	}
	if (arr_len(arr) == 2 && ft_isnum(arr[1]))
		exit_status = ft_atoi(arr[1]);
	if (arr_len(arr) > 2 && ft_isnum(arr[1]))
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		free_split(arr);
		return (1);
	}
	ftn_exit(msh, exit_status, arr);
	return (0);
}
/**
 ** clear_history();
 **/
