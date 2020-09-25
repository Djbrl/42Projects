/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:15:31 by dsy               #+#    #+#             */
/*   Updated: 2020/09/25 11:13:33 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include "libft.h"
# include <string.h>
# include <errno.h>
# include <limits.h>

# define CWD_ERROR ": couldn't retrieve current directory.\n"
# define CMD_ERROR ": command not found\n"
# define MODE_DEFAULT 1
# define MODE_DIR 2
# define BUF 4096

char	g_buffer[BUF];

void	flush_buffer();
void	sanitize_args(char **args);
void	evaluate_commands(char **args);
void	signal_handler(int sig_n);
void	display_prompt(int mode);
void	display_error(char *error);
void	echo(char *s);
void	echo_n(char *s);
void	exit_shell(int exit_status);
char	*get_currentdir();
#endif
