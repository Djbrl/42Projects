/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:11:20 by dsy               #+#    #+#             */
/*   Updated: 2022/09/20 16:11:23 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_char(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || ft_strlen(str) == 0)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

void parse_envp(t_msh *msh)
{
	int		i;
	int		j;
	char	*var;

	i = 0;
	j = 0;
	if (msh->envp == NULL)
		return ;
	while (msh->envp[i])
	{
		var = ft_substr(msh->envp[i], 0, find_char(msh->envp[i], '='));
		if (!var)
			return ;
		if (ft_strncmp(var, "HOME", ft_strlen(var)) == 0)
		{
			msh->home = ft_substr(msh->envp[i], \
				find_char(msh->envp[i], '=') + 1, find_char(msh->envp[i], '0'));
			add_var_to_env(msh->env, "HOME", msh->home);
		}
		if (ft_strncmp(var, "USER", ft_strlen(var)) == 0)
		{
			msh->user = ft_substr(msh->envp[i], \
				find_char(msh->envp[i], '=') + 1, find_char(msh->envp[i], '0'));
			add_var_to_env(msh->env, "USER", msh->user);
		}
		if (ft_strncmp(var, "PATH", ft_strlen(var)) == 0)
		{
			msh->full_path = ft_substr(msh->envp[i], \
				find_char(msh->envp[i], '=') + 1, find_char(msh->envp[i], '0'));
			msh->default_path = ft_substr(msh->envp[i], \
				find_char(msh->envp[i], '=') + 1, find_char(msh->full_path, ':'));
			add_var_to_env(msh->env, "HOME", msh->full_path);
		}
		free(var);
		i++;
	}
	return ;
}