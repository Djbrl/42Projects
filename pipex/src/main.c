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
	path = ft_strjoin("/bin/", tmp);
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

int	check_args(int f1, int f2, int ac, char **av)
{
	int	cmd1;
	int	cmd2;

	if (ac != 5)
		return (0);
	f1 = open(av[1], O_RDONLY);
	f2 = open(av[4], O_WRONLY | O_TRUNC);
	cmd1 = check_cmd(av[2]);
	cmd2 = check_cmd(av[3]);
	if (f1 < 0 || f2 < 0 || cmd1 < 0 || cmd2 < 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int	f1;
	int	f2;

	f1 = 0;
	f2 = 0;
	if (!check_args(f1, f2, ac, av))
	{
		write(1, "Error.\n", 7);
		return (0);
	}
	pipex(f1, f2, av[2], av[3]);
	return (0);
}
