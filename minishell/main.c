#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"
#include <string.h>
#define BUF 4096

void flush_buffer(char *buffer)
{
	int i;

	i = 0;
	ft_memset(buffer, 0, BUF);
}

void evaluate_commands(char **args)
{
	int i;
	
	i = 0;
	while(args[i])
		ft_putstr(args[i++]);
}

void shell_loop(void)
{
	char *line;
	char **args;
	int status;
	char buffer[BUF];
	printf("Welcome in dsyshell.\n");
	while (1)
	{
		write(1, "> ", 2);
		read(0, buffer, BUF);
		if (!(ft_strcmp(buffer, "exit\n")))
			exit(EXIT_SUCCESS);
		line = strdup(buffer);
		args = ft_split(line, ';');
		evaluate_commands(args);
		flush_buffer(buffer);
		free(line);
	}
	//execute the command
	//free stuff and update status/success/failure
}

int main(int ac, char **av)
{
	int done;
	int i = 0;
	done = 0;
	
	shell_loop();
//	char **s = ft_split("this is a test", ' ');
//	while(s[i])
//		printf("%s\n", s[i++]);
	return (0);
}

