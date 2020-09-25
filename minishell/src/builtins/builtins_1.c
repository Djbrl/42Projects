/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:19:12 by dsy               #+#    #+#             */
/*   Updated: 2020/09/25 16:58:07 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_echo_n(char **args)
{
	int i;
	int j;

	i = 2;
	j = 0;
	while (args[i])
	{
		if (i > 2)
			write(1, " ", 1);
		while (args[i][j])
		{
			write(1, &args[i][j], 1);
			j++;
		}
		j = 0;
		i++;
		if (args[i + 1])
			write(1, " ", 1);
	}
}

void	msh_echo(char **args)
{
	int i;
	int j;

	j = 0;
	i = 1;
	if (!ft_strcmp(args[1], "-n"))
		msh_echo_n(args);
	else
	{
		while (args[i])
		{
			if (i > 1)
				write(1, " ", 1);
			while (args[i][j])
				write(1, &args[i][j++], 1);
			j = 0;
			i++;
		}
		write(1, "\n", 1);
	}
}

void	msh_cd(char **args)
{
	    char s[100]; 
  
    // printing current working directory 
    printf("before : %s\n", getcwd(s, 100)); 

	if(chdir(args[1]) == 0)
		printf("current : %s\n", getcwd(s, 100)); 
	else
	{
		printf("%s\ncurrent directory is : %s\n", strerror(errno), getcwd(s, 100));
	}
}

void	msh_help(char **args)
{

	ft_putstr("\nminishell-4.2 commands: \n\necho\t\t: a clone of bash echo\n");
	ft_putstr("cd\t\t: a clone of bash cd\n");	
	ft_putstr("help\t\t: show this list\n");	
}