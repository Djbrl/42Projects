/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:44:42 by dsy               #+#    #+#             */
/*   Updated: 2020/02/09 17:32:05 by dsy              ###   ########.fr       */
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
	int     a = -4;
	int     b = 0;
	char    c = 'a';
	int     d = 2147483647;
	int     e = -2147483648;
	int     f = 42;
	int     g = 25;
	int     h = 4200;
	int     i = 8;
	int     j = -12;
	int     k = 123456789;
	int     l = 0;
	int     m = -12345678;
	char    *n = "abcdefghijklmnop";
	char    *o = "-a";
	char    *p = "-12";
	char    *q = "0";
	char    *r = "%%";
	char    *s = "-2147483648";
	char    *t = "0x12345678";
	char    *u = "-0";

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
	printf("\n");
	printf(" --- Return : %d\n", printf("%1.*d\n", 0, 0));
	printf(" --- Return : %d\n", ft_printf("%1.*d\n", 0, 0));
	printf(" --- Return : %d\n", printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf(" --- Return : %d\n", ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("-- %d --\n", ft_printf("%-i%.0i%13.*s%uMwA313t1RDzSEza", 0, 2147483647, -6, "hiOJUTZ     n5agtzMoBsO9FLqAE5Gh6Hg2r7GzVe8bpyuvOR5G6tP75CTFgIx0zwrnBcmvGF75vFl78Q6HnXlKXql", 2147483647));	
	printf("-- %d --\n", printf("%-i%.0i%13.*s%uMwA313t1RDzSEza", 0, 2147483647, -6, "hiOJUTZ     n5agtzMoBsO9FLqAE5Gh6Hg2r7GzVe8bpyuvOR5G6tP75CTFgIx0zwrnBcmvGF75vFl78Q6HnXlKXql", 2147483647));
	printf("-- %d --\n", ft_printf("%.*d", 0, 0));
	printf("-- %d --\n", printf("%.*d", 0, 0));
	//system("leaks a.out");
	return (0);
}
