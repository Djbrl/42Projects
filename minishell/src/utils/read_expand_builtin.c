/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_expand_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:17:24 by dsy               #+#    #+#             */
/*   Updated: 2023/01/10 16:29:53 by dsy              ###   ########.fr       */
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
	int	quotes;
	int	i;

	quotes = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			quotes++;
		i++;
	}
	return (quotes % 2 == 1);
}

int	has_unexpected_token(char *str)
{
	char	**res;
	int		i;
	int		len;

	res = ft_split(str, ' ');
	i = 0;
	while (res[i])
	{
		len = ft_strlen(res[i]);
		if ((len == 1 && (res[i][0] == '>' || res[i][0] == '<' \
			|| res[i][0] == '|')) \
			|| (len == 2 && (ft_strcmp(res[i], ">>") == 0 \
			|| ft_strcmp(res[i], "<<") == 0)))
		{
			if (res[i + 1] == NULL)
			{
				free_split(res);
				return (1);
			}
		}
		else if (i == 0 && len == 2 && ft_strcmp(res[i], "<<") == 0)
		{
			free_split(res);
			return (1);
		}
		i++;
	}
	free_split(res);
	return (0);
}

char	*get_colored_user(t_msh *msh)
{
	char	*user;
	char	*colored_user;
	char	*green_user;

	user = get_data_from_env(msh->env, ft_strdup("USER"));
	colored_user = NULL;
	if (user != NULL)
	{
		green_user = ft_strjoin(KGRN, user);
		colored_user = ft_strjoin(green_user, "\033[0m");
		free(green_user);
		free(user);
	}	
	return (colored_user);
}

char	*get_colored_curdir(t_msh *msh)
{
	char	*curdir;
	char	*colored_curdir;
	char	*blue_curdir;

	colored_curdir = NULL;
	curdir = get_currentdir(msh);
	if (curdir != NULL)
	{
		blue_curdir = ft_strjoin(KBLU, curdir);
		colored_curdir = ft_strjoin(blue_curdir, "\033[0m");
		free(blue_curdir);
		free(curdir);
	}
	return (colored_curdir);
}

char	*get_prompt_prefix(char *colored_user)
{
	if (colored_user != NULL)
		return (ft_strjoin(colored_user, "@minishell-4.2$ "));
	else
		return (ft_strdup("guest@minishell-4.2$ "));
}

void	build_prompt_line(t_msh *msh, char **promptline)
{
	char	*colored_user;
	char	*colored_curdir;
	char	*prompt_prefix;
	char	*full_curdir;
	char	*dir;

	colored_user = get_colored_user(msh);
	colored_curdir = get_colored_curdir(msh);
	prompt_prefix = get_prompt_prefix(colored_user);
	full_curdir = ft_strjoin("./", colored_curdir);
	dir = ft_strjoin(prompt_prefix, full_curdir);
	*promptline = ft_strjoin(dir, "> ");
	free(colored_user);
	free(colored_curdir);
	free(full_curdir);
	free(dir);
	free(prompt_prefix);
}

char	*get_input_from_user(char *promptline)
{
	char	*s;

	s = readline(promptline);
	free(promptline);
	return (s);
}

int	check_input_validity(char *s)
{
	if (s == NULL)
		return (0);
	if (has_odd_quotes(s))
	{
		printf(SYNTAX_ERR_QUOTES);
		return (0);
	}
	if (has_unexpected_token(s))
	{
		printf(SYNTAX_ERR_QUOTES);
		return (0);
	}
	return (1);
}

void	process_input(t_msh *msh, char *s)
{
	int		i;

	if (ft_strlen(s) == 0)
		flush_buffer(msh);
	else
	{
		i = -1;
		while (s[++i] && s[i] != '\n')
			msh->g_buffer[i] = s[i];
	}
	free(s);
}

void	read_buffer(t_msh *msh)
{
	char	*promptline;
	char	*s;

	build_prompt_line(msh, &promptline);
	s = get_input_from_user(promptline);
	if (check_input_validity(s))
		process_input(msh, s);
	else
		flush_buffer(msh);
}
