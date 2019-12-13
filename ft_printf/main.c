/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:31:22 by dsy               #+#    #+#             */
/*   Updated: 2019/12/04 06:15:17 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <stdio.h>
#include <limits.h>
int main()
{
	/**********************STRING***************/

	/*printf("%10s\n", "Salut");
	  printf("%-10s\n", "Salut");
	  printf("****court*****\n");

	  printf("%10s\n", "Salut tout le monde");
	  printf("%-10s\n", "Salut tout le monde");
	  printf("****long****\n");

	  printf("%10.5s\n", "salut tout");
	  printf("%5.10s\n", "salut tout");
	  printf("****precision court****\n");

	  printf("%10.5s\n", "Salut tout le monde");
	  printf("%5.10s\n", "Salut tout le monde");
	  printf("****precision long*****\n");

	  printf("%-10.5s\n", "salut tout");
	  printf("%-5.10s\n", "salut tout");
	  printf("****precision court avec - *****\n");

	  printf("%-10.5s\n", "Salut tout le monde");
	  printf("%-5.10s\n", "Salut tout le monde");
	  printf("****precision long avec - *****\n");*/

	/*ft_printf("%10s\n", "Salut");
	  ft_printf("%-10s\n", "Salut");
	  ft_printf("****court*****\n");

	  ft_printf("%10s\n", "Salut tout le monde");
	  ft_printf("%-10s\n", "Salut tout le monde");
	  ft_printf("****long****\n");

	  ft_printf("%10.5s\n", "salut tout");
	  ft_printf("%5.10s\n", "salut tout");
	  ft_printf("****precision court****\n");

	  ft_printf("%10.5s\n", "Salut tout le monde");
	  ft_printf("%5.10s\n", "Salut tout le monde");
	  ft_printf("****precision long*****\n");

	  ft_printf("%-10.5s\n", "salut tout");
	  ft_printf("%-5.10s\n", "salut tout");
	  ft_printf("****precision court avec - *****\n");

	  ft_printf("%-10.5s\n", "Salut tout le monde");
	  ft_printf("%-5.10s\n", "Salut tout le monde");
	  ft_printf("****precision long avec - *****\n");*/

	/*****************CHAR************/
	/*printf("%c\n", 'a');
	printf("*** test simple ****\n");

	printf("%-c\n", 'a');
	printf("*** avec '-' **\n");

	printf("%10c\n", 'a');
	printf("*** avec largeur ***\n");

	printf("%-10c\n", 'a');
	printf("**** largeur avec '-' ***\n");

		printf("////////\n");

	printf("%c\n", 97);
        printf("*** test simple avec valeur decimal ****\n");

        printf("%-c\n", 97);
        printf("*** '-' avec valeur decimal**\n");

        printf("%10c\n", 97);
        printf("*** largeur avec valeur decimal ***\n");

        printf("%-10c\n", 97);
        printf("**** largeur ,'-' et valeur decimal***\n");*/

	
        /*ft_printf("*** test simple ****\n");

        ft_printf("%-c\n", 'a');
        ft_printf("*** avec '-' **\n");

        ft_printf("%10c\n", 'a');
        ft_printf("*** avec largeur ***\n");

        ft_printf("%-10c\n", 'a');
        ft_printf("**** largeur avec '-' ***\n");

                ft_printf("////////\n");

        ft_printf("%c\n", 97);
        ft_printf("*** test simple avec valeur decimal ****\n");

        ft_printf("%-c\n", 97);
        ft_printf("*** '-' avec valeur decimal**\n");

        ft_printf("%10c\n", 97);
        ft_printf("*** largeur avec valeur decimal ***\n");

        ft_printf("%-10c\n", 97);
        ft_printf("**** largeur ,'-' et valeur decimal***\n");*/



	/*printf("%+-10.20d, %-10.5s, %-5c\n", 1245, "salut tout le monde", 'a');
	ft_printf("%+-10.20d, %-10.5s, %-5c\n", 1245, "salut tout le monde", 'a');*/


			/**************ADRESSE*************/

	/*char	*a;
	a = "0";
	//a = NULL;
	printf("%20p\n", a);
	printf("%-20p\n", a);
        ft_printf("%20p\n", a);
        ft_printf("%-20p\n", a);*/

			/*********HEXADECIMAL*********/
	/*printf("ori: %3x\n", 1248);
	printf("ori: %-3x\n", 1248);
	printf("ori: %10x\n", 1248);
	printf("ori: %-10x\n", 1248);
	printf("******* largeur ******\n");

	printf("ori: %.3X\n",1248);
	printf("ori: %-.3x\n",1248);
	printf("ori: %.10x\n", 1248);
	printf("ori: %-10x\n", 1248);
	printf("******** precision *******\n");

	printf("ori: %10.3x\n", 1248);
	printf("ori: %3.10x\n", 1248);
	printf("ori: %10.3x\n", 12480);
        printf("ori: %3.10x\n", 12480);
	printf("***** largeur et precision ****\n");

	printf("ori: %-10.3x\n", 1248);
        printf("ori: %-3.10x\n", 1248);
        printf("ori: %-10.3x\n", 12480);
        printf("ori: %-3.10x\n", 12480);
	printf("***** largeur, precision et - *****\n");*/

	/*--------------------------------------------*/
        ft_printf("cpy: %3x\n", 1248);
        ft_printf("cpy: %-3x\n", 1248);
        ft_printf("cpy: %10x\n", 1248);
        ft_printf("cpy: %-10x\n", 1248);
        ft_printf("******* largeur ******\n");

        ft_printf("cpy: %.3X\n",1248);
        ft_printf("cpy: %-.3x\n",1248);
        ft_printf("cpy: %.10x\n", 1248);
        ft_printf("cpy: %-10x\n", 1248);
        ft_printf("******** precision *******\n");

        ft_printf("cpy: %10.3x\n", 1248);
        ft_printf("cpy: %3.10x\n", 1248);
        ft_printf("cpy: %10.3x\n", 12480);
        ft_printf("cpy: %3.10x\n", 12480);
        ft_printf("***** largeur et precision ****\n");

        ft_printf("cpy: %-10.3x\n", 1248);
        ft_printf("cpy: %-3.10x\n", 1248);
        ft_printf("cpy: %-10.3x\n", 12480);
        ft_printf("cpy: %-3.10x\n", 12480);
        ft_printf("***** largeur, precision et - *****\n");

	return (0);
}
