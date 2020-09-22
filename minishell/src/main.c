#include "minishell.h"

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