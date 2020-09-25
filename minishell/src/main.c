/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 10:56:56 by dsy               #+#    #+#             */
/*   Updated: 2020/09/25 12:22:57 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	AUTORISED FUNCTIONS
	malloc, free, write, open, read, close, fork, wait,
	waitpid, wait3, wait4, signal, kill, exit, getcwd,
	chdir, stat, lstat, fstat, execve, dup, dup2, pipe,
	opendir, readdir, closedir, strerror, errno

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

//variables to free
void	shell_loop(void)
{
	char	*line;
	char	**args;//to free
	int		status;
	char	cwd[PATH_MAX];

	printf("Welcome in minishell.\n");
	signal(SIGINT, signal_handler);
	while (1)
	{
		display_prompt(MODE_DEFAULT);
		flush_buffer();
		read(0, g_buffer, BUF);
		g_buffer[ft_strlen(g_buffer) - 1] = 0;
		if (!(ft_strcmp(g_buffer, "exit")))
			exit_shell(EXIT_SUCCESS);
		line = strdup(g_buffer);
		args = ft_split(line, ' ');
		sanitize_args(args);
		evaluate_commands(args);
		flush_buffer(g_buffer);
		free(line);
	}
}

int		main(int ac, char **av)
{
	int	done;
	int	i = 0;

	done = 0;
	shell_loop();
	return (0);
}
