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

// int	exec_child(int fd, char *cmd)
// {
// 	char	**args;
// 	(void)fd;
// 	(void)cmd;

// 	close(tube[0]);
// 	dup2(tube[1], 1);
// 	args = ft_split(cmd, ' ');
// 	close(fd);
// 	execvp(args[0], args);
// 	free_split(args);
// 	(void)cmd;
// 	(void)tube;
// 	return (0);
// }

// int	exec_parent(int fd, char *cmd)
// {
// 	int		status;
// 	char	**args;

// 	args = ft_split(cmd, ' ');
// 	close(tube[1]);
// 	dup2(tube[0], 0);
// 	waitpid(-1, &status, 0);
// 	//close(fd);
// 	execvp(args[0], args);
// 	free_split(args);
// 	(void)args;
// 	(void)cmd;
// 	(void)fd;
// 	return (0);
// }

void	pipex(int f1, int f2, char *cmd1, char *cmd2)
{
	pid_t	parent;

	dup2(f1, 0);
	dup2(f2, 1);
	int	tube[2];
	pipe(tube);
	parent = fork();
	if (parent < 0)
		return (perror("Fork: "));
	if (!parent)
	{
		char	**args;

		close(tube[0]);
		dup2(tube[1], 1);
		args = ft_split(cmd1, ' ');
		//close(f1);
		if (f1 == STDIN_FILENO)
			exit(1);
		else
			execvp(args[0], args);
		free_split(args);
		(void)tube;

	}
	else
	{
		char	**args;

		args = ft_split(cmd2, ' ');
		close(tube[1]);
		dup2(tube[0], 0);
		waitpid(parent, NULL, 0);
		//close(f2);
		//execvp(args[0], args);
		free_split(args);
		//(void)args;
		(void)cmd2;

	}
	return ;
}
