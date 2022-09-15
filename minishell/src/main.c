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
Partie obligatoire

Nom du programme : 
   - minishell

Fichiers de rendu :
   - Makefile, *.h, *.c
   - Makefile : NAME, all, clean, fclean, re

Arguments : Aucun

Fonctions externes autorisées
   -  readline, rl_clear_history, rl_on_new_line,
      rl_replace_line, rl_redisplay, add_history,
      printf, malloc, free, write, access, open, read,
      close, fork, wait, waitpid, wait3, wait4, signal,
      sigaction, sigemptyset, sigaddset, kill, exit,
      getcwd, chdir, stat, lstat, fstat, unlink, execve,
      dup, dup2, pipe, opendir, readdir, closedir,
      strerror, perror, isatty, ttyname, ttyslot, ioctl,
      getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
      tgetnum, tgetstr, tgoto, tputs
   -  Libft autorisée Oui

Description
   Votre shell doit :
   • Afficher un prompt en l’attente d’une nouvelle commande.
   • Posséder un historique fonctionnel.
   • Chercher et lancer le bon exécutable (en se basant sur la variable d’environnement
   PATH, ou sur un chemin relatif ou absolu).
   • Ne pas utiliser plus d’une variable globale. Réfléchissez-y car vous devrez justifier son utilisation.
   • Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non
   demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).
   • Gérer ’ (single quote) qui doit empêcher le shell d’interpréter les méta-caractères
   présents dans la séquence entre guillemets.
   • Gérer " (double quote) qui doit empêcher le shell d’interpréter les méta-caractères
   présents dans la séquence entre guillemets sauf le $ (signe dollar).
   

   Minishell Aussi mignon qu’un vrai shell
   • Implémenter les redirections :
   ◦ < doit rediriger l’entrée.
   ◦ > doit rediriger la sortie.
   ◦ << doit recevoir un délimiteur et lire l’input donné jusqu’à rencontrer une ligne
   contenant le délimiteur. Cependant, l’historique n’a pas à être mis à jour !
   ◦ >> doit rediriger la sortie en mode append.
   • Implémenter les pipes (caractère |). La sortie de chaque commande de la pipeline
   est connectée à l’entrée de la commande suivante grâce à un pipe.
   • Gérer les variables d’environnement (un $ suivi d’une séquence de caractères)
   qui doivent être substituées par leur contenu.
   • Gérer $? qui doit être substitué par le statut de sortie de la dernière pipeline
   exécutée au premier plan.
   • Gérer ctrl-C, ctrl-D et ctrl-\ qui doivent fonctionner comme dans bash.
   • En mode interactif :
   ◦ ctrl-C affiche un nouveau prompt sur une nouvelle ligne.
   ◦ ctrl-D quitte le shell.
   ◦ ctrl-\ ne fait rien.
   • Votre shell doit implémenter les builtins suivantes :
   ◦ echo et l’option -n
   ◦ cd uniquement avec un chemin relatif ou absolu
   ◦ pwd sans aucune option
   ◦ export sans aucune option
   ◦ unset sans aucune option
   ◦ env sans aucune option ni argument
   ◦ exit sans aucune option
   La fonction readline() peut causer des fuites de mémoire. Vous n’avez pas à les
   gérer. Attention, cela ne veut pas pour autant dire que votre code, oui celui que
   vous avez écrit, peut avoir des fuites de mémoire.
   Tenez-vous en à ce qui est demandé dans le sujet. Ce qui n’est pas
   demandé n’est pas obligatoire.
   Si vous avez un doute sur une consigne du sujet, prenez bash comme
   référence.
*/

static void	shell_loop(t_msh *msh)
{
	char	*prompt;
	char	**tokens;

   /*
   ** SET SIGNAL HANDLER FOR CTRL+C
   */
	signal(SIGINT, signal_handler);
	/*
   ** MAIN LOOP
   */
   while (RUNNING)
	{
		display_prompt(MODE_DEFAULT, msh);
		flush_buffer(msh);
		read_buffer(msh);
		if ((ft_strncmp(msh->g_buffer, "exit", ft_strlen(msh->g_buffer))) == 0)
			exit_shell(EXIT_SUCCESS, msh);
		prompt = ft_strdup(msh->g_buffer);
		if (prompt != NULL)
		{
         /*
         ** PARSING HERE
         */
			tokens = ft_split(prompt, ';');
         /*
         ** PARSING HERE
         */
			msh->input->data = ft_strdup(tokens[0]);
			evaluate_commands(ft_split(msh->input->data, ' '), msh);
			flush_buffer(msh);
         free(prompt);
			free_split(tokens);
		}
	}
}

int		main(int ac, char **av)
{
	t_msh	msh;

	init_msh(&msh);
   init_cmd(&msh);
   init_env(&msh);
	shell_loop(&msh);
	return (0);
}
