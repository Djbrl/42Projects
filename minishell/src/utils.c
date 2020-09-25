#include <minishell.h>

void	display_error(char *error)
{
	if (!strcmp(error, CWD_ERROR))
	{
		ft_putstr("minishell: ");
		ft_putstr(error);
	}
	else if (!(strcmp(error, CMD_ERROR)))
	{
		ft_putstr("minishell: ");
		ft_putstr(g_buffer);
		ft_putstr(CMD_ERROR);
	}
	else
	{
		ft_putstr("minishell: ");
		ft_putstr("unknown error");
	}
	exit(EXIT_FAILURE);
}

void	display_prompt(int mode)
{
	char *path;

	if (mode == MODE_DIR)
	{
		path = get_currentdir();
		write(1, path, ft_strlen(path));
		write(1, "$ > ", 4);
		free(path);
	}
	else
	{
		write(1, "minishell-4.2$ > ", 17);
	}
}

char	*get_currentdir()
{
	char *path;
	char cwd[1024];
	int i = 0;
	int last_slash = 0;

	path = ft_strdup(getcwd(cwd, sizeof(cwd)));
	if (!path)
	{
		display_error(CWD_ERROR);
		return (NULL);
	}

	while (path[i])
	{
		if (path[i] == '/')
			last_slash = i;
		i++;
	}
	return (ft_strdup(path + last_slash + 1));
}

void flush_buffer()
{
	int i;

	i = 0;
	ft_memset(g_buffer, 0, BUF);
}

void sanitize_args(char **args)
{
	int i = 0;
	int j = 0;

	while (args[i])
	{
		while(args[i][j])
		{
			if(args[i][j] == '\n')
				args[i][j] = 0;
			j++;
		}
		i++;
	}
}