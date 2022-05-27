/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:17:33 by dsy               #+#    #+#             */
/*   Updated: 2022/05/17 16:23:27 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

void	pipex(int f1, int f2, char *cmd1, char *cmd2);
int		exec_parent(int fd, char *cmd, int tube[2]);
int		exec_child(int fd, char *cmd, int tube[2]);

//UTILITY
void	free_split(char **array);
#endif
