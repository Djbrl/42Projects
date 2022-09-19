/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:15:31 by dsy               #+#    #+#             */
/*   Updated: 2020/12/07 18:10:42 by user42           ###   ########.fr       */
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
# define RUNNING 1
# define HOME "/mnt/nfs/homes/dsy"
# define PROMPTLINE "minishell-4.2$ > "

typedef struct s_msh	t_msh;
typedef struct s_cmd_list
{
	char				*data;
	struct s_cmd_list	*next;
}						t_cmd_list;

typedef struct s_env_var
{
	char				*name;
	char				*data;
	struct s_env_var	*next;
}						t_env_var;

typedef struct s_cmd
{
	int			(*ptr[8])(t_env_var*, t_msh *msh);
	char		*name[8];
}				t_cmd;

typedef struct s_msh
{
	t_cmd		cmd;
	t_env_var	*env;
	t_cmd_list	*input;
	char		*prompt;
	char		**tokens;
	char		g_buffer[BUF];
}				t_msh;

/*
** INIT
*/
void	init_env(t_msh *msh);
void	init_msh(t_msh *msh);
void	init_cmd(t_msh *msh);

/*
** BUILTINS
*/
int		msh_cd(t_env_var *env, t_msh *msh);
int		msh_pwd(t_env_var *env, t_msh *msh);
int		msh_env(t_env_var *env, t_msh *msh);
int		msh_echo(t_env_var *env, char *s, t_msh *msh);
int		msh_help(t_env_var *env, t_msh *msh);
int		msh_exit(t_env_var *env, t_msh *msh);
int		msh_unset(t_env_var *env, t_msh *msh);
int		msh_export(t_env_var *env, char *arg, t_msh *msh);
int		msh_echo_runner(t_env_var *env, t_msh *msh);
int		msh_export_runner(t_env_var *env, t_msh *msh);

/*
** DISPLAY
*/
int		display_error(char *error, t_msh *msh);
void	display_prompt(int mode, t_msh *msh);
void	display_cmd_error(char *cmd, char *error, char **args);


/*
** CONTROL
*/
char	*get_currentdir(t_msh *msh);
char	*get_data_from_env(t_env_var *env, char *name);
int		add_var_to_env(t_env_var *env, char *name, char *data);
int		add_cmd_to_list(t_cmd_list *input, char *data);
void	evaluate_commands(char **args, t_msh *t_msh);
void	signal_handler(int sig_n);
void	read_buffer(t_msh *msh);
void	exit_cmd(t_msh *msh);
void	exit_shell(int status, t_msh *msh);

/*
** UTILS
*/
void	free_split(char **array);
void	flush_buffer(t_msh *msh);
int		is_builtin(char *s, t_msh *msh);
#endif
