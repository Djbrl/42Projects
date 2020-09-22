#include "minishell.h"

void flush_buffer(char *buffer)
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
			echo(args[1]);
		else if (!ft_strcmp(args[0], "echo") && !ft_strcmp(args[1], "-n"))
			echo_n(args[2]);
		else 
			if (execvp(args[0], args) == -1)
				perror("minishell");
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