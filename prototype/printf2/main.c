/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:31:22 by dsy               #+#    #+#             */
/*   Updated: 2020/01/06 17:33:53 by dsy              ###   ########.fr       */
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
	//	char *s = NULL;
	//	int ret = 5;
	//ft_printf("p : %p\n", s);
	//printf("rp : %p\n", s);

	printf("%10x\n", 15);		//places n sspaces such that n = arg + spaces
	printf("%010x\n", 15);		// replaces spaces with 0s
	printf("%010.0x\n", 15);	// number of chars printed, also erases 0s, doesnt erase the number
	printf("%010.1x\n", 15);	// number of chars printed, also erases 0
	printf("%010.5x\n", 15);
	printf("%-10.5x\n", 15); 	// width number of spaces will be printed no matter what and no matter the justification
	printf("%010.10x\n", 15);
	printf("%010.20x\n", 15);	//if precision > number, fill with 0s
	printf("%-10.20x\n", 15);	//if precision > number, fill with 0s, overrides width
	printf("%-10.20x\n", 15);	//if precision > number, fill with 0s, overrides width

	//replace wildcard with arg and relaunch
	//	printf("%-010.20x\n", 15); // 0 and - will always be ignored
	//ft_printf("XTEST %x\t%X\n", 9999, 9999);
	//	ret = ft_printf("XTEST, this is some sort of elaborate printing test. %s%x%X%s%c%p%u%i%s\n", GRN, 9999, 9999, "it seems to be working tho", '.', s, 9999, 9999, RST);
	/*
	ret = ft_printf("abcd%s", "abcd");
	ft_printf("%i\n", ret);
	ret = ft_printf("abcdabcd");
	ft_printf("%i\n", ret);
	ret = ft_printf("%%%%%%%%");
	ft_printf("%i\n", ret);
	ret = ft_printf("%%%%%%%%, testing, %i, %c, %s, %p, %x, %X, %u, %d\n", 5, 'c', "cowd", &ret, 17421, 17421, 17, 17);
	ft_printf("%i\n", ret);*/
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
