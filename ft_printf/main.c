/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:31:22 by dsy               #+#    #+#             */
/*   Updated: 2019/12/02 22:09:52 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <stdio.h>
#define	GRN "\x1b[32m"
#define RST "\x1b[0m"

int main()
{
//	ft_printf("test i : \"%i\"\ntest s : \"%s\"\n", 43, "test field");
//	ft_printf("%s%s%s%i%s%u%s%c\n", "huk", "huk", "huk", 213, "huk", 321, "huk", 'X');
	char *s;
	printf("u : %u\n", s);
	printf("x : %x\n", s);
	printf("p :%p\n", s);
	ft_printf("u : %u\n", s);
	ft_printf("x : %x\n", s);
	ft_printf("p : %p\n", 342831158);

	/*int i = 7;
	int p = 5;
	int	test = printf("");
	int	test1 = printf("test printf : \"%s%s%s\"\n", GRN, "test", RST);
	int	test2 = printf("test printf : \"%s%c%s\"\n", GRN, 'g', RST);
	int	test3 = printf("test printf : \"%s%p%s\"\n", GRN, &p, RST);
	int	test4 = printf("test printf : \"%s%i%s\"\n", GRN, p, RST);
	int	test5 = printf("test printf : \"%s%d%s\"\n", GRN, p, RST);
	int	test6 = printf("test printf : \"%s%u%s\"\n", GRN, p, RST);
	int	test7 = printf("test printf : \"%s%x%s\"\n", GRN, p, RST);
	
	printf("ret de printf : %i\n", test1);
	printf("ret de printf : %i\n", test2);
	printf("ret de printf : %i\n", test3);
	printf("ret de printf : %i\n", test4);
	printf("ret de printf : %i\n", test5);
	printf("ret de printf : %i\n", test6);
	printf("ret de printf : %i\n", test7);*/
}
