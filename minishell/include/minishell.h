/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <dsy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:15:31 by dsy               #+#    #+#             */
/*   Updated: 2020/09/23 15:11:26 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "libft.h"
#include <string.h>
#include <errno.h>
#include <limits.h>
#define BUF 4096
char buffer[BUF];

#define MODE_DEFAULT 1
#define MODE_DIR 2
#define CWD_ERROR " :couldn't retrieve current directory.\n"
#define CMD_ERROR ":command not found\n"

void flush_buffer();
void sanitize_args(char **args);
void evaluate_commands(char **args);
void signalHandler(int sig_n);
void displayPrompt(int mode);
char *getCurrentDir();
void displayError(char *error);