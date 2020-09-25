/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:17:48 by dsy               #+#    #+#             */
/*   Updated: 2020/09/25 12:25:28 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	evaluate_commands(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	if (pid == 0)
	{//this is what the son is up to
		if (!ft_strcmp(args[0], "echo") && !args[2])
			echo(args[1]);
		else if (!ft_strcmp(args[0], "echo") && !ft_strcmp(args[1], "-n"))
			echo_n(args[2]);
		else
		{
			if (execvp(args[0], args) == -1)
				display_error(CMD_ERROR);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("fork error");//this is the error case
	else
	{//this is what the parent is doing
		while(!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
}

void	exit_shell(int exit_status)
{
	//FREE STUFF HERE
	exit(EXIT_SUCCESS);
}

void	signal_handler(int sig_n)
{
	write(1, "\n", 1);
	display_prompt(MODE_DEFAULT);
	flush_buffer(g_buffer);
}
