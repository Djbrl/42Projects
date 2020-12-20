/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 10:56:56 by dsy               #+#    #+#             */
/*   Updated: 2020/12/07 17:01:02 by user42           ###   ########.fr       */
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


int		main(int ac, char **av)
{
	t_msh	msh;

	init_msh(&msh);
   init_cmd(&msh);
	shell_loop(&msh);
	return (0);
}
