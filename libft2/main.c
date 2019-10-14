/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:48:58 by dsy               #+#    #+#             */
/*   Updated: 2019/10/14 16:27:36 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main()
{
	char str1[] = "test";
	char str2[] = "test";
	//char str3[] = "test basic du memccpy";
	//char str4[] = "test basic du memccpy";
	//char str5[] = "test";
	//char str6[] = "test";
	//char str7[] = "test";
	
	/*printf("%s\n", memccpy(str1, "toto", 'z', 0));
	printf("%s\n", str1);
	printf("%s\n", ft_memccpy(str2, "toto", 'z', 0));
	printf("%s\n", str2);*/
	printf("%s\n", memccpy(str2, "dwhuw", '\0', 4));
	printf("%s\n", str2);
	printf("%s\n", ft_memccpy(str1, "dwhuw", '\0', 4));
	printf("%s\n", str1);
	return (0);
}
