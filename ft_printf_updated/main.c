/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:44:42 by dsy               #+#    #+#             */
/*   Updated: 2020/02/15 21:57:48 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <stdio.h>
/*
char *GRN="\033[0;32m";
char *RED="\033[0;31m";
char *YLW="\033[0;33m";
char *NC="\033[0m";i
*/

int main()
{
	/*
	 ft_printf("%d - %i - %u - %x - %X - %c - %s - %%", -5, -5, -5, -5, -5, '\0', NULL);
printf("\n");
	 printf("%d - %i - %u - %x - %X - %c - %s - %%", -5, -5, -5, -5, -5, '\0', NULL);
printf("\n");
	  ft_printf("%10s", "hello");
printf("\n");
	  printf("%10s", "hello");
printf("\n");

	  ft_printf("%.10s", "hello");
printf("\n");
	  printf("%.10s", "hello");
printf("\n");

	  ft_printf("%15.10s", "hello");
printf("\n");
	  printf("%15.10s", "hello");
printf("\n");

	  ft_printf("%s%*.*s%s", GRN, -15, -10, "hello", NC);
printf("\n");
	  printf("%*.*s", -15, -10, "hello");
printf("\n");
	  ft_printf("%s%*.*s%s", GRN, 15, 10, "hello", NC);
printf("\n");
	  printf("%*.*s", 15, 10, "hello");
printf("\n");
	  ft_printf("%s%*.*s%s", GRN, -15, 10, "hello", NC);
printf("\n");
	  printf("%*.*s", -15, 10, "hello");
printf("\n");
	  ft_printf("%s%*.*s%s", YLW, 15, -10, "hello", NC);
printf("\n");
	  printf("%*.*s", 15, -10, "hello");
printf("\n");
	
	 printf("hello ca%----4c %1c%10c%-c ??", '\0', '\n', (char)56, 0);
printf("\n");
	 ft_printf("hello ca%----4c %1c%10c%-c ??", '\0', '\n', (char)56, 0);
printf("\n");*/
	printf(" --- Return : %d\n", printf("%1.d\n", 0));
	printf(" --- Return : %d\n", ft_printf("%1.d\n", 0));

 	 return (0);
}
