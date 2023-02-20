/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:57:12 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/02/14 18:57:40 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	join_tokens(t_msh *msh)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	msh->clean_prompt = ft_strdup("");
	while (msh->tokens[i])
	{
		tmp = ft_strjoin(msh->clean_prompt, msh->tokens[i]);
		tmp2 = ft_strjoin(tmp, " ");
		free(tmp);
		free(msh->clean_prompt);
		msh->clean_prompt = ft_strdup(tmp2);
		free(tmp2);
		i++;
	}
}
