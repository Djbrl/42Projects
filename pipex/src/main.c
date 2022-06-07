/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:29:06 by dsy               #+#    #+#             */
/*   Updated: 2022/05/24 13:29:08 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_cmd(char *cmd)
{
	int		status;
	char	**arg;
	char	*tmp;
	char	*path;

	arg = ft_split(cmd, ' ');
	tmp = ft_strdup(arg[0]);
	path = ft_strjoin("/usr/bin/", tmp);
	status = access(path, X_OK & F_OK);
	if (status < 0)
	{
		free(tmp);
		free(path);
		free_split(arg);
		return (0);
	}
	free(tmp);
	free(path);
	free_split(arg);
	return (1);
}

int	print_error(char *error)
{
	ft_putstr("pipex: ");
	ft_putstr(error);
	perror(" \b");
	return (0);
}

int	check_args(int *f1, int *f2, int ac, char **av)
{
	int	cmd1;
	int	cmd2;

	if (ac != 5)
	{
		ft_putstr("pipex: wrong number of arguments\n");
		return (0);
	}
	*f1 = open(av[1], O_RDONLY);
	*f2 = open(av[4], O_WRONLY | O_TRUNC | O_CREAT);
	cmd1 = check_cmd(av[2]);
	cmd2 = check_cmd(av[3]);
	if (*f1 < 0)
		return (print_error(av[1]));
	if (*f2 < 0)
		return (print_error(av[4]));
	if (!cmd1)
		return (print_error(av[2]));
	if (!cmd2)
		return (print_error(av[3]));
	return (1);
}

int	main(int ac, char **av, char **env)
{
	int		f1;
	int		f2;
	int		fd[2];

	f1 = 0;
	f2 = 0;
	if (!check_args(&f1, &f2, ac, av))
		return (0);
	fd[0] = f1;
	fd[1] = f2;
	pipex(fd, av[2], av[3], env);
	return (0);
}
