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
	printf("%10s\n", "Salut");
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
	printf("****precision long avec - *****\n");

	/*******************FT_PRINTF****************/

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
	return (0);
}
