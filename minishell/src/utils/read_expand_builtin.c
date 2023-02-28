/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_expand_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:17:24 by dsy               #+#    #+#             */
/*   Updated: 2023/02/15 17:26:34 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 ** The 'ft_strlen() + 1' is meant to check if there 
 ** are any extra characters after the builtin name string
 */
int	is_redir(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>' || str[i] == '<')
			return (1);
		i++;
	}
	return (0);
}

int	is_builtin(char *s, t_msh *msh)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!ft_strncmp(msh->cmd.name[i], s, ft_strlen(msh->cmd.name[i]) + 1))
			return (i);
		i++;
	}
	return (-1);
}

char	*expand_var(t_msh *msh, char *var)
{
	char	*ret;
	char	*find;

	find = ft_substr(var, 1, ft_strlen(var) - 1);
	ret = get_data_from_env(msh->env, find);
	if (ret == NULL)
		return (ft_strdup(var));
	else
		return (ft_strdup(ret));
}

void	flush_buffer(t_msh *msh)
{
	ft_memset(msh->g_buffer, 0, BUF);
}

/*
 ** void	read_buffer(t_msh *msh)
 ** {
 ** 	int	signal;
 **
 ** 	flush_buffer(msh);
 ** 	if (g_status == CTRL_C_EXIT)
 ** 		g_status = STATUS_RESET;
 ** 	else
 ** 		display_prompt(MODE_DEFAULT, msh);
 ** 	signal = read(0, msh->g_buffer, BUF);
 ** 	if (signal == CTRL_D_SIGNAL)
 ** 	{
 ** 		flush_buffer(msh);
 ** 		exit_cmd(msh);
 ** 		exit_shell(msh, NULL);
 ** 	}
 ** 	msh->g_buffer[ft_strlen(msh->g_buffer) - 1] = 0;
 ** }
 */

int	has_odd_quotes(char *str)
{
	int	i;
	int	unclosed_q;
	int	unclosed_dq;
	int	unclosed;

	unclosed = 0;
	unclosed_q = 0;
	unclosed_dq = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			unclosed_q = 1;
		if (str[i] == '\"' && unclosed_q == 1)
			unclosed_q = 0;
		if (str[i] == '\'')
			unclosed_dq = 1;
		if (str[i] == '\'' && unclosed_dq == 1)
			unclosed_dq = 0;
		i++;
	}
	if (unclosed_q || unclosed_dq)
		unclosed = 1;
	return (unclosed);
}

int	is_pipe_or_redir(char *str)
{
	int	len;

	if (str)
	{
		len = ft_strlen(str);
		if ((len == 1 && (str[0] == '>' || str[0] == '<' || str[0] == '|')) \
			|| (len == 2 && (ft_strcmp(str, ">>") == 0 \
			|| ft_strcmp(str, "<<") == 0)))
			return (1);
	}
	return (0);
}

int	has_unexpected_token(char *str)
{
	char	**res;
	int		i;

	res = ft_split(str, ' ');
	i = 0;
	while (res[i])
	{
		if (is_pipe_or_redir(res[i]))
		{
			if (res[i + 1] == NULL)
			{
				free_split(res);
				return (1);
			}
		}
		else if (i == 0 && ft_strlen(res[i]) == 2 && !ft_strcmp(res[i], "<<"))
		{
			free_split(res);
			return (1);
		}
		i++;
	}
	free_split(res);
	return (0);
}

static char	*get_current_user(char *user)
{
	char	**username;
	char	*name;
	int		i;

	i = 0;
	username = ft_split(user, '/');
	while (username[i])
		i++;
	name = ft_strdup(username[i - 1]);
	free_split(username);
	return (name);
}

void	get_prompt_line(t_msh *msh, char *user, char **promptline)
{
	char	*curdir;
	char	*tmp[6];
	char	*dir;
	char	*name;

	name = get_current_user(user);
	tmp[0] = ft_strjoin(KGRN, name);
	free(name);
	tmp[1] = ft_strjoin(tmp[0], "\033[0m");
	curdir = get_currentdir(msh);
	tmp[2] = ft_strjoin(KBLU, curdir);
	free(curdir);
	tmp[3] = ft_strjoin(tmp[2], "\033[0m");
	tmp[4] = ft_strjoin("./", tmp[3]);
	dir = ft_strjoin("@minishell-4.2$ ", tmp[4]);
	tmp[5] = ft_strjoin(dir, "> ");
	*promptline = ft_strjoin(tmp[1], tmp[5]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp[3]);
	free(tmp[4]);
	free(dir);
	free(tmp[5]);
	free(user);
}

void	check_prompt(t_msh *msh, char *s)
{
	int	i;

	i = -1;
	if (ft_strlen(s) != 0)
		add_history(s);
	if (has_odd_quotes(s) || has_unexpected_token(s))
	{
		printf(SYNTAX_ERR_QUOTES);
		flush_buffer(msh);
		return ;
	}
	if (ft_strlen(s) == 0)
		flush_buffer(msh);
	else
	{
		while (s[++i] && s[i] != '\n')
			msh->g_buffer[i] = s[i];
	}
}

static void	build_promptline(char *user, char **promptline, t_msh *msh)
{
	if (user != NULL && ft_strlen(user) > 0)
		get_prompt_line(msh, user, promptline);
	else
	{
		get_prompt_line(msh, ft_strdup("user42"), promptline);
		if (user != NULL)
			free(user);
	}
}

void	exit_failure(t_msh *msh)
{
	(void)msh;
	flush_buffer(msh);
	free_env(msh);
	free_expr(&msh);
	exit(EXIT_SUCCESS);
}

void	read_buffer(t_msh *msh)
{
	char	*s;
	char	*user;
	char	*promptline;

	dup2(msh->std_in, 0);
	user = ft_strdup(get_data_from_env(msh->env, ft_strdup("USER")));
	promptline = NULL;
	build_promptline(user, &promptline, msh);
	s = readline(promptline);
	free(promptline);
	if (s != NULL)
		check_prompt(msh, s);
	else
		exit_failure(msh);
	if (g_status == CTRL_D_SIGNAL)
	{
		flush_buffer(msh);
		g_status = 0;
	}
	free(s);
}
