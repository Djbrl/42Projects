#include "minishell.h"

//REMOVE slash n at the end of buffer
void	displayError(char *error)
{
	if (!strcmp(error, CWD_ERROR))
	{
		ft_putstr("minishell: ");
		ft_putstr(error);
	}
	else if (!(strcmp(error, CMD_ERROR)))
	{
		ft_putstr("minishell: ");
		ft_putstr(buffer);
		ft_putstr(CMD_ERROR);
	}
	else
	{
		ft_putstr("minishell: ");
		ft_putstr("unknown error");
	}
	exit(EXIT_FAILURE);
}

void	displayPrompt(int mode)
{
	char *path;

	if (mode == MODE_DIR)
	{
		path = getCurrentDir();
		write(1, path, ft_strlen(path));
		write(1, "$ > ", 4);
		free(path);
	}
	else
	{
		write(1, "minishell-4.2$ > ", 17);
	}
}

char	*getCurrentDir()
{
	char *path;
	char cwd[1024];
	int i = 0;
	int last_slash = 0;

	path = ft_strdup(getcwd(cwd, sizeof(cwd)));
	if (!path)
	{
		displayError(CWD_ERROR);
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
	ft_memset(buffer, 0, BUF);
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

void echo(char *s)
{
	int i;
	i = 0;

	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void echo_n(char *s)
{
	int i;
	i = 0;
	
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void evaluate_commands(char **args)
{
	pid_t pid; 
	pid_t wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (!ft_strcmp(args[0], "echo") && !args[2])
		{
			flush_buffer();
			echo(args[1]);
		}
		else if (!ft_strcmp(args[0], "echo") && !ft_strcmp(args[1], "-n"))
			echo_n(args[2]);
		else 
			if (execvp(args[0], args) == -1)
				displayError(CMD_ERROR);
		exit(EXIT_FAILURE);
	}
	else if(pid < 0)
		perror("fork error");
	else
	{
		do
			wpid = waitpid(pid, &status, WUNTRACED);
		while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

void signalHandler(int sig_n)
{
	write(1, "\n> ", 3);
	//flush_buffer(buffer);
}