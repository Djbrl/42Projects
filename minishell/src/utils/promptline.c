/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_expand_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:17:24 by dsy               #+#    #+#             */
/*   Updated: 2023/01/10 16:29:53 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_colored_user(t_msh *msh)
{
	char	*user;
	char	*colored_user;
	char	*green_user;

	user = ft_strdup(get_data_from_env(msh->env, ft_strdup("USER")));
	colored_user = NULL;
	if (user != NULL)
	{
		green_user = ft_strjoin(KGRN, user);
		colored_user = ft_strjoin(green_user, "\033[0m");
		free(green_user);
		free(user);
	}	
	return (colored_user);
}

static char	*get_colored_curdir(t_msh *msh)
{
	char	*curdir;
	char	*colored_curdir;
	char	*blue_curdir;

	colored_curdir = NULL;
	curdir = get_currentdir(msh);
	if (curdir != NULL)
	{
		blue_curdir = ft_strjoin(KBLU, curdir);
		colored_curdir = ft_strjoin(blue_curdir, "\033[0m");
		free(blue_curdir);
		free(curdir);
	}
	return (colored_curdir);
}

static char	*get_prompt_prefix(char *colored_user)
{
	if (colored_user != NULL)
		return (ft_strjoin(colored_user, "@minishell-4.2$ "));
	else
		return (ft_strdup("guest@minishell-4.2$ "));
}

void	build_prompt_line(t_msh *msh, char **promptline)
{
	char	*colored_user;
	char	*colored_curdir;
	char	*prompt_prefix;
	char	*full_curdir;
	char	*dir;

	colored_user = get_colored_user(msh);
	colored_curdir = get_colored_curdir(msh);
	prompt_prefix = get_prompt_prefix(colored_user);
	full_curdir = ft_strjoin("./", colored_curdir);
	dir = ft_strjoin(prompt_prefix, full_curdir);
	*promptline = ft_strjoin(dir, "> ");
	free(colored_user);
	free(colored_curdir);
	free(full_curdir);
	free(dir);
	free(prompt_prefix);
}
