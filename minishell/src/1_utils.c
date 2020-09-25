/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:17:48 by dsy               #+#    #+#             */
/*   Updated: 2020/09/25 16:44:36 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	evaluate_commands(char **args, t_msh *msh)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;
	int		i;

	pid = fork();
	i = is_builtin(args[0], msh);
	if (pid == 0)
	{//this is what the son is up to
		if (i >= 0)
			msh->cmd.ptr[i](args);
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
		wpid = waitpid(pid, &status, WUNTRACED);
		while(!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
}

void	init_msh(t_msh *msh)
{
	msh->cmd.name[0] = "echo"; 
	msh->cmd.name[1] = "help";
	msh->cmd.name[2] = "cd";
	msh->cmd.ptr[0] = msh_echo;
	msh->cmd.ptr[1] = msh_help;
	msh->cmd.ptr[2] = msh_cd;
}

int		is_builtin(char *s, t_msh *msh)
{
	int i;

	i = 0;
	while (msh->cmd.name[i])
	{
		if (!ft_strcmp(msh->cmd.name[i], s))
			return (i);
		i++;
	}
	return (-1);
}

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
