/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:19:12 by dsy               #+#    #+#             */
/*   Updated: 2020/09/25 16:36:05 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_echo_n(char **s)
{
	int i;
	int j;

	i = 2;
	j = 0;
	while (s[i])
	{
		if (i > 2)
			write(1, " ", 1);
		while (s[i][j])
		{
			write(1, &s[i][j], 1);
			j++;
		}
		j = 0;
		i++;
		if (s[i + 1])
			write(1, " ", 1);
	}
}

void	msh_echo(char **s)
{
	int i;
	int j;

	j = 0;
	i = 1;
	if (!ft_strcmp(s[1], "-n"))
		msh_echo_n(s);
	else
	{
		while (s[i])
		{
			if (i > 1)
				write(1, " ", 1);
			while (s[i][j])
				write(1, &s[i][j++], 1);
			j = 0;
			i++;
		}
		write(1, "\n", 1);
	}
}

void	msh_help(char **s)
{

	ft_putstr("\nminishell-4.2 commands: \n\necho\t\t: a clone of bash echo\n");
	ft_putstr("help\t\t: show this list\n");	
}