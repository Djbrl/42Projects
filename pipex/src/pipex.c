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

char	*path(char *cmd)
{
	char	*str;
	char	**args;

	args = ft_split(cmd, ' ');
	str = ft_strjoin("/usr/bin/", args[0]);
	free_split(args);
	return (str);
}

void	exec_child(int tube[2], char *cmd, char **env)
{
	int		status;
	char	**args;
	char	*pth;

	args = ft_split(cmd, ' ');
	close(tube[0]);
	dup2(tube[1], STDOUT_FILENO);
	pth = path(cmd);
	status = execve(pth, args, env);
	if (status == -1)
		free(pth);
	perror("execve error");
}

void	pipex(int fd[2], char *cmd1, char *cmd2, char **env)
{
	pid_t	pid;
	int		tube[2];
	char	**args;
	int		status;
	char	*pth;

	args = ft_split(cmd1, ' ');
	dup2(fd[0], 0);
	dup2(fd[1], 1);
	pipe(tube);
	pid = fork();
	if (!pid)
		exec_child(tube, cmd1, env);
	else
	{
		args = ft_split(cmd2, ' ');
		close(tube[1]);
		dup2(tube[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
		pth = path(cmd2);
		status = execve(pth, args, env);
		if (status == -1)
			free(pth);
		perror("execve error");
	}
	return ;
}
