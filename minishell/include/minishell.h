/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:15:31 by dsy               #+#    #+#             */
/*   Updated: 2020/09/25 16:04:44 by dsy              ###   ########.fr       */
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

typedef struct	s_cmd {
		void	(*ptr[2])(char **);
		char	*name[2];
}		t_cmd;

typedef struct	s_msh{
		t_cmd cmd;
}		t_msh;

int		is_builtin(char *s, t_msh *msh);
void	init_msh(t_msh *msh);
void	flush_buffer();
void	evaluate_commands(char **args, t_msh *t_msh);
void	signal_handler(int sig_n);
void	display_prompt(int mode);
void	display_error(char *error);
void	msh_echo(char **s);
void	msh_help(char **s);
void	exit_shell(int status);
char	*get_currentdir();
#endif
