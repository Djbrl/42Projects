/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:48:58 by dsy               #+#    #+#             */
/*   Updated: 2019/10/12 19:02:51 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int ac, char **av)
{
	char str1[] = "test";
	char str2[] = "test";
	char str3[] = "test";
	char str4[] = "test";
	char str5[] = "test";
	char str6[] = "test";
	char str7[] = "test";
	int i = 1;

	while (i < ac)
	{
		printf("retour de memccpy : %s\nretour de ft_memccpy : %s\n", memccpy(str1, (const char*)av[i], 's', 4), ft_memccpy(str2, (const char*)av[i], 's', 4));
		printf("valeur de str : %s\n", str1);
		free(str1);
		printf("valeur de str : %s\n\n", str1);
	}
	return (0);
}
