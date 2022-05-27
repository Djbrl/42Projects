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

int	exec_child(int fd, char *cmd, int tube[2])
{
	char	**args;

	(void)fd;
	(void)cmd;
	dup2(fd, 0);
	dup2(tube[1], 1);
	args = ft_split(cmd, ' ');
	close(tube[0]);
	close(fd);
	execvp(args[0], args);
	free_split(args);
	(void)cmd;
	return (0);
}

int	exec_parent(int fd, char *cmd, int tube[2])
{
	int		status;
	char	**args;

	waitpid(-1, &status, 0);
	args = ft_split(cmd, ' ');
	dup2(fd, 1);
	dup2(tube[0], 0);
	close(tube[1]);
	execvp(args[0], args);
	free_split(args);
	close(fd);
	(void)args;
	(void)cmd;
	return (0);
}

void	pipex(int f1, int f2, char *cmd1, char *cmd2)
{
	pid_t	parent;
	int		tube[2];

	pipe(tube);
	parent = fork();
	if (parent < 0)
		return (perror("Fork: "));
	if (!parent)
		exec_child(f1, cmd1, tube);
	else
		exec_parent(f2, cmd2, tube);
	return ;
}
