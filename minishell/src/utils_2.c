#include <minishell.h>

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
				display_error(CMD_ERROR);
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

void signal_handler(int sig_n)
{
	write(1, "\n> ", 3);
	//flush_buffer(buffer);
}