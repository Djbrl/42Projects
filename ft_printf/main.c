/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:44:42 by dsy               #+#    #+#             */
/*   Updated: 2020/02/04 16:13:38 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <stdio.h>

char *GRN="\033[0;32m";
char *RED="\033[0;31m";
char *YLW="\033[0;33m";
char *NC="\033[0m";

int main()
{
	printf("[%d]\n", ft_printf("%d - %i - %u - %x - %X - %c - %s - %%", -5, -5, -5, -5, -5, '\0', NULL));
	printf("[%d]\n", printf("%d - %i - %u - %x - %X - %c - %s - %%", -5, -5, -5, -5, -5, '\0', NULL));

	 printf("[%d]\n", ft_printf("%10s", "hello"));
	 printf("[%d]\n", printf("%10s", "hello"));

	 printf("[%d]\n", ft_printf("%.10s", "hello"));
	 printf("[%d]\n", printf("%.10s", "hello"));

	 printf("[%d]\n", ft_printf("%15.10s", "hello"));
	 printf("[%d]\n", printf("%15.10s", "hello"));

	 printf("[%d]\n", ft_printf("%s%*.*s%s", GRN, -15, -10, "hello", NC));
	 printf("[%d]\n", printf("%*.*s", -15, -10, "hello"));

	 printf("[%d]\n", ft_printf("%s%*.*s%s", GRN, 15, 10, "hello", NC));
	 printf("[%d]\n", printf("%*.*s", 15, 10, "hello"));
	 printf("[%d]\n", ft_printf("%s%*.*s%s", GRN, -15, 10, "hello", NC));
	 printf("[%d]\n", printf("%*.*s", -15, 10, "hello"));
	 printf("[%d]\n", ft_printf("%s%*.*s%s", GRN, 15, -10, "hello", NC));
	 printf("[%d]\n", printf("%*.*s", 15, -10, "hello"));
	return (0);
}
