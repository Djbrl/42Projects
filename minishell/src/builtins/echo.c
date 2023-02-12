/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:19:12 by dsy               #+#    #+#             */
/*   Updated: 2023/01/10 16:27:22 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_echo_multiple_words(t_env_var *env, t_msh *msh)
{
	char	**tmp;
	int		j;

	j = 1;
	tmp = ft_split(msh->prompt, '\"');
	while (tmp[j])
	{
		msh_echo_dollar_check(tmp[j], env, msh);
		j++;
	}
	free_split(tmp);
	return (0);
}

int	msh_echo(t_env_var *env, char *arg, t_msh *msh)
{
	if (more_than_one_word(arg) == 1)
		msh_echo_multiple_words(env, msh);
	else
		msh_echo_dollar_check(arg, env, msh);
	free(arg);
	return (0);
}
