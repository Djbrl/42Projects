/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 03:15:12 by dsy               #+#    #+#             */
/*   Updated: 2020/10/19 11:04:43 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(int status)
{
	//FREE RIOT POINTS HERE
	exit(status);
}

void	signal_handler(int sig_n)
{
	write(1, "\n", 1);
	display_prompt(MODE_DEFAULT);
	flush_buffer(g_buffer);
}

void	evaluate_commands(char **args, t_msh *msh)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	//fuck norminette
	if (is_builtin(args[0], msh) >= 0)
		msh->cmd.ptr[is_builtin(args[0], msh)](&msh->env, args);
	else
	{
		pid = fork();
		if (pid == 0) //son
		{
			if (execvp(args[0], args) == -1)
				display_error(CMD_ERROR);
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)//fork error
			display_error(FORK_ERROR);
		else
		{//this is what the parent is doing
			wpid = waitpid(pid, &status, WUNTRACED);
			while (!WIFEXITED(status) && !WIFSIGNALED(status))
				wpid = waitpid(pid, &status, WUNTRACED);
		}
	}
}
