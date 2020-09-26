/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:15:31 by dsy               #+#    #+#             */
/*   Updated: 2020/09/27 00:01:08 by dsy              ###   ########.fr       */
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

# define PATH_ERROR ": No such file or directory\n"
# define CWD_ERROR ": couldn't retrieve current directory.\n"
# define CMD_ERROR ": command not found\n"
# define MODE_DEFAULT 1
# define MODE_DIR 2
# define BUF 4096

char	g_buffer[BUF];

typedef struct	s_cmd {
		void	(*ptr[4])(char **);
		char	*name[4];
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
void	display_cmd_error(char *cmd, char *error, char **args);
void	msh_echo(char **args);
void	msh_help(char **args);
void	msh_cd(char **args);
void	msh_pwd(char **args);
void	exit_shell(int status);
char	*get_currentdir();
#endif
