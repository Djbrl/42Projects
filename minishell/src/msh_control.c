/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 03:15:12 by dsy               #+#    #+#             */
/*   Updated: 2020/12/07 17:54:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(int status)
{
	//FREE RIOT POINTS HERE
	exit(status);
}

void	signal_handler(int sig_n, t_msh *msh)
{
	write(1, "\n", 1);
	display_prompt(MODE_DEFAULT, msh);
	flush_buffer(msh);
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
				display_error(CMD_ERROR, msh);
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)//fork error
			display_error(FORK_ERROR, msh);
		else
		{//this is what the parent is doing
			wpid = waitpid(pid, &status, WUNTRACED);
			while (!WIFEXITED(status) && !WIFSIGNALED(status))
				wpid = waitpid(pid, &status, WUNTRACED);
		}
	}
}
