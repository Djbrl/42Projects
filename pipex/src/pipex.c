/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:13:56 by dsy               #+#    #+#             */
/*   Updated: 2022/05/27 15:59:20 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int f1, int f2, char *cmd1, char *cmd2)
{
	pid_t	pid;
	int		tube[2];
	char	**args;

	args = ft_split(cmd1, ' ');
	dup2(f1, 0);
	dup2(f2, 1);
	pipe(tube);
	pid = fork();
	if (!pid)
	{
		close(tube[0]);
		dup2(tube[1], STDOUT_FILENO);
		execvp(args[0], args);
	}
	else
	{
		args = ft_split(cmd2, ' ');
		close(tube[1]);
		dup2(tube[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
		execvp(args[0], args);
	}
	return ;
}
