/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 10:56:56 by dsy               #+#    #+#             */
/*   Updated: 2020/09/27 02:07:16 by dsy              ###   ########.fr       */
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
void	shell_loop(t_msh *msh)
{
	pid_t	pid;
	pid_t	wpid;
	char	*line;
	char	**args;//to free
	int		status;
	char	cwd[PATH_MAX];

	ft_putstr("Welcome in minishell.\n");
	pid = fork();
	if (pid == 0)
	{
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
			evaluate_commands(args, msh);
			flush_buffer(g_buffer);
			free(line);
		}	
	}
	else if (pid < 0)
		perror("failed fork");
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while(!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);	
	}
}

int		main(int ac, char **av)
{
	int		done;
	int		i = 0;
	t_msh	msh;

	done = 0;
	init_msh(&msh);
	shell_loop(&msh);
	return (0);
}
