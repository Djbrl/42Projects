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

int has_odd_quotes(char *str)
{
    int quotes;
    int i;

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

int		has_unexpected_token(char *str)
{
	char	**res;
	int		i;
	int		len;

	res = ft_split(str, ' ');
	i = 0;
	while (res[i])
	{
		len = ft_strlen(res[i]);
		if ((len == 1 && (res[i][0] == '>' || res[i][0] == '<' || res[i][0] == '|'))
			|| (len == 2 && (ft_strcmp(res[i], ">>") == 0 || ft_strcmp(res[i], "<<") == 0)))
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

void	read_buffer(t_msh *msh)
{
	char	*s;
	int		i;
	char	*user;
	char	*promptline;

	i = -1;
	user = ft_strdup(get_data_from_env(msh->env, ft_strdup("USER")));
	if (user != NULL)
	{
		char *tmp = ft_strjoin(KGRN, user);
		char *tmp2 = ft_strjoin(tmp, "\033[0m");
		char *curdir = get_currentdir(msh);
		char *tmp6 = ft_strjoin(KBLU, curdir);
		char *tmp7 = ft_strjoin(tmp6, "\033[0m");
		char *tmp5 = ft_strjoin("./", tmp7);
		char *dir = ft_strjoin("@minishell-4.2$ ", tmp5);
		free(curdir);
		char *tmp4 = ft_strjoin(dir, "> ");
		promptline = ft_strjoin(tmp2, tmp4);
		free(user);
		free(tmp);
		free(tmp2);
		free(dir);
		free(tmp4);
		free(tmp5);
		free(tmp6);
		free(tmp7);	
	}
	else
		promptline = ft_strjoin("guest", "@minishell-4.2$ > ");
	s = readline(promptline);
	free(promptline);
	if (s != NULL)
	{
		add_history(s);
		if (has_odd_quotes(s))
		{
			printf(SYNTAX_ERR_QUOTES);
			flush_buffer(msh);
			return ;
		}
		if (has_unexpected_token(s))
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
	else
	{
		flush_buffer(msh);
		free_env(msh);
		free_expr(&msh);
		exit(EXIT_FAILURE);
		return ;
	}
	if (g_status == CTRL_D_SIGNAL)
	{
		flush_buffer(msh);
		g_status = 0;
	}
	free(s);
}
