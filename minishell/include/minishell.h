/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:15:31 by dsy               #+#    #+#             */
/*   Updated: 2020/10/14 02:44:05 by dsy              ###   ########.fr       */
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
# include "../libft/libft.h"
# include <string.h>
# include <errno.h>
# include <limits.h>

# define ENV_ERROR ": couldn't setup environment\n"
# define FORK_ERROR ": couldn't start process\n"
# define PATH_ERROR ": no such file or directory\n"
# define CWD_ERROR ": couldn't retrieve current directory\n"
# define CMD_ERROR ": command not found\n"
# define MODE_DEFAULT 1
# define MODE_DIR 2
# define BUF 4096

char	g_buffer[BUF];

typedef struct	s_env_var{
				char *name;
				char *data;
				struct s_env_var	*next;
}				t_env_var;

typedef struct	s_cmd{
				void	(*ptr[7])(t_env_var*, char **);
				char	*name[7];
}				t_cmd;

typedef struct	s_msh{
				t_cmd		cmd;
				t_env_var	env;
}				t_msh;

int		is_builtin(char *s, t_msh *msh);
char	*get_currentdir();
char	*get_data_from_env(t_env_var *env, char *name);
void	init_msh(t_msh *msh);
void	init_env(t_msh *msh);
void	flush_buffer();
void	exit_shell(int status);
void	evaluate_commands(char **args, t_msh *t_msh);
void	signal_handler(int sig_n);
void	display_prompt(int mode);
void	display_error(char *error);
void	display_cmd_error(char *cmd, char *error, char **args);

void	msh_echo_runner(t_env_var *env, char **args);
void	msh_export_runner(t_env_var *env, char **args);

void	msh_echo(t_env_var *env, char *s);
void	msh_export(t_env_var *env, char *arg);
void	msh_help(t_env_var *env, char **args);
void	msh_cd(t_env_var *env, char **args);
void	msh_pwd(t_env_var *env, char **args);
void	msh_env(t_env_var *env, char **args);
void	msh_unset(t_env_var *env, char **args);
#endif
