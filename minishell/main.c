#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../libft/libft.h"
#include <string.h>
#define BUF 4096

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

void evaluate_commands(char **args)
{
	pid_t pid; 
	pid_t wpid;
	int status;

	i = 0;
	pid = fork();
	if (pid == 0)
	{
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

void shell_loop(void)
{
	char *line;
	char **args;
	int status;
	char buffer[BUF];

	printf("Welcome in minishell.\n");
	while (1)
	{
		write(1, "> ", 2);
		read(0, buffer, BUF);
		if (!(ft_strcmp(buffer, "exit\n")))
			exit(EXIT_SUCCESS);
		line = strdup(buffer);
		args = ft_split(line, ' ');
	
		sanitize_args(args);
		evaluate_commands(args);
		flush_buffer(buffer);
		free(line);
	}
}

int main(int ac, char **av)
{
	int done;
	int i = 0;
	done = 0;

	shell_loop();
	return (0);
}

