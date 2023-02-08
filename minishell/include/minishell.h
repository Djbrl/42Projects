/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:15:31 by dsy               #+#    #+#             */
/*   Updated: 2023/01/10 16:26:41 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include "../libft/libft.h"
# include <string.h>
# include <errno.h>
# include <limits.h>

# define SHELL_PID_ERROR "[SHELL_PID]"
# define SYNTAX_ERR_QUOTES "minishell: syntax error: unclosed quotes\n"
# define PWD_ERR "pwd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory\n"
# define CHDIR_ERR "chdir: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory\n"
# define CD_ARG_ERROR ": too many arguments\n"
# define ENV_ID_ERROR ": not a valid identifier\n"
# define FORK_ERROR ": couldn't start process\n"
# define PATH_ERROR ": No such file or directory\n"
# define CWD_ERROR ": couldn't retrieve current directory\n"
# define CMD_ERROR ": command not found\n"
# define MODE_DEFAULT 1
# define MODE_DIR 2
# define BUF 4096
# define RUNNING 1
# define PROMPTLINE "minishell-4.2$ > "
# define SUCCESS 0
# define FAILURE 1
# define STATUS_RESET 0
# define CTRL_C_EXIT 2
# define CTRL_D_SIGNAL 0
# define BUFFER_SIZE 4096

extern int				g_status;
typedef struct s_msh	t_msh;

typedef struct s_expr{
	char			*data;
	int				fd_in;
	int				fd_out;
	int				redir;
	struct s_expr	*next;
}					t_expr;

typedef struct s_env_var
{
	char				*name;
	char				*data;
	struct s_env_var	*next;
}						t_env_var;

typedef struct s_cmd
{
	int			(*ptr[8])(t_env_var*, t_msh *msh, char *field);
	char		*name[8];
}				t_cmd;

typedef struct s_msh
{
	t_cmd		cmd;
	t_expr		*exp;
	t_env_var	*env;
	char		*last_valid_path;
	char		*home;
	char		*user;
	char		*full_path;
	char		*default_path;
	char		*prompt;
	char		**tokens;
	char		**envp;
	char		**paths;
	char		g_buffer[BUF];
	int			nb_tokens;
	int			single_quote;
	int			exit_status;
	int			std_in;
	int			std_out;
}				t_msh;

/*
** INIT
*/
void	init_env(t_msh *msh);
void	init_msh(t_msh *msh, char **envp);
void	init_expr(t_msh *msh);

/*
** BUILTINS
*/
int		msh_cd(t_env_var *env, t_msh *msh, char *field);
int		msh_pwd(t_env_var *env, t_msh *msh, char *field);
int		msh_env(t_env_var *env, t_msh *msh, char *field);
int		msh_echo(t_env_var *env, char *s, t_msh *msh);
int		msh_help(t_env_var *env, t_msh *msh, char *field);
int		msh_exit(t_env_var *env, t_msh *msh, char *field);
int		msh_unset(t_env_var *env, t_msh *msh, char *field);
int		msh_export(t_env_var *env, char *arg, t_msh *msh);
int		msh_cd_runner(t_env_var *env, t_msh *msh, char *field);
int		msh_echo_runner(t_env_var *env, t_msh *msh, char *field);
int		msh_export_runner(t_env_var *env, t_msh *msh, char *field);

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
void	free_data_from_env(t_env_var *env, char *name);
int		add_var_to_env(t_env_var *env, char *name, char *data);
void	evaluate_commands(t_msh *t_msh);
void	signal_handler(int sig_n);
void	read_buffer(t_msh *msh);
void	parse_envp(t_msh *msh);
void	exit_cmd(t_msh *msh);
int		exit_shell(t_msh *msh, char *field);

/*
** UTILS
*/
int		is_redir(char *str);
int		expr_len(t_expr *expr);
int		load_expr(t_msh *msh);
void	free_expr(t_msh **msh);
char	*expand_var(t_msh *msh, char *var);
void	free_split(char **array);
void	flush_buffer(t_msh *msh);
int		get_next_line(int fd, char **line);
int		update_exit_status(t_msh *msh, int status);
int		is_builtin(char *s, t_msh *msh);
char	**ft_split_charset(const char *s, const char *set);
char	*remove_spaces(const char *str);
void	close_redir(int in, int out);
int		arr_len(char **arr);
void	free_envar(t_msh *msh);
void	free_env(t_msh *msh);
int 	change_dir(t_msh **msh, char **tokens);
int		more_than_one_word(char *echo);

/*
** PIPE
*/
int		pipe_exec(t_msh *msh);
int		init_fds(t_expr **commands, t_expr *prev);
void	close_fds(t_expr **curr_command);
int		connect_fds(t_expr **curr_command, t_expr *commands);

/*
** REDIRECTIONS
*/
void	exec_builtin(t_msh *msh, char *field);
void	apply_redirections(char *expr, int *fd_in, int *fd_out, t_msh *msh);
void	check_redirections(t_msh *msh);
void	heredoc(char **field, t_msh *msh);

/*
** PARSING
*/
char	**parse_prompt(char *str, t_msh *msh);
void	add_to_rt(char **rt, char *tmp);
void	*ft_realloc(void *ptr, size_t cursize, size_t newsize);
int		is_pipe_redir(char c);
int		is_whitespace(char c);
int		dollar(char *str, char **rt, int i, t_msh *msh);
int		double_quote(char *str, char **rt, int i, t_msh *msh);
int		pipe_redir(char *str, char **rt, int i);
int		single_quote(char *str, char **rt, int i);
int		string(char *str, char **rt, int i);

#endif
