#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "libft.h"
#include <string.h>
#include <limits.h>
#define BUF 4096

/*
Votre shell doit :
• Afficher un prompt en l’attente d’une nouvelle commande

• Chercher et lancer le bon executable (basé sur une variable d’environnement PATH
ou en utilisant un path absolu), comme dans bash

• Vous devez implémenter les builtins suivants :
◦ echo et l’option ’-n’
◦ cd uniquement avec un chemin absolu ou relatif
◦ pwd sans aucune option
◦ export sans aucune option
◦ unset sans aucune option
◦ env sans aucune option ni argument
[DONE ?]◦ exit sans aucune option

• ; dans la ligne de commande doit séparer les commandes

• ’ et " doivent marcher comme dans bash, à l’exception du multiligne.

• Les redirections <, > et “>>” doivent marcher comme dans bash, à l’exception des
aggrégations de fd

• Pipes | doivent marcher comme dans bash

• Les variables d’environnement ($ suivi de caractères) doivent marcher comme dans
bash.

• $? doit marcher comme dans bash

• ctrl-C, ctrl-D et ctrl-\ doivent afficher le même résultat que dans bash.
*/

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

void shell_loop(void)
{
	char *line;
	char **args;
	int status;
	char buffer[BUF];
	char *currentDir;
	char cwd[PATH_MAX];

	printf("Welcome in minishell.\n");
	signal(SIGINT, signalHandler);
	while (1)
	{
		currentDir = ft_strdup(getcwd(cwd, sizeof(cwd)));
		write(1, "> ", 2);
		ft_putstr(currentDir);
		write(1, "$ ", 2);
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