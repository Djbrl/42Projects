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
		if (f1 == STDIN_FILENO)
			exit(1);
		else
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
	// pipe(tube);
	// parent = fork();
	// if (parent < 0)
	// 	return (perror("Fork: "));
	// if (parent ==  0)
	// {
	// 	char	**args;

	// 	close(tube[0]);
	// 	dup2(tube[1], 1);
	// 	args = ft_split(cmd1, ' ');
	// 	//close(f1);
	// 	if (f1 == STDIN_FILENO)
	// 		exit(1);
	// 	else
	// 		execvp(args[0], args);
	// 	free_split(args);
	// 	(void)tube;

	// }
	// else
	// {
	// 	char	**args;

	// 	args = ft_split(cmd2, ' ');
	// 	close(tube[1]);
	// 	dup2(tube[0], 0);
	// 	waitpid(parent, NULL, 0);
	// 	//close(f2);ze
	// 	execvp(args[0], args);
	// 	free_split(args);
	// 	//(void)args;
	// 	(void)cmd2;
	//}
	return ;
}
