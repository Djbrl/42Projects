/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:48:58 by dsy               #+#    #+#             */
/*   Updated: 2019/10/16 16:22:29 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int		main()
{

	char str[50] = "test du strlcpy!";
	char str1[50] = "test du strlcpy!";
	char str2[50] = "test du strlcpy!";
	char str3[50] = "test du strlcpy!";
	char str4[50] = "test du strlcpy!";
	char str5[50] = "test du strlcpy!";

	printf("%i\n%i\n", (int)strlcat(str, "XXXXX", 16), (int)ft_strlcat(str1, "XXXXX", 16));
	printf("results : \nst %s\nft %s\n", str, str1);
	printf("%i\n%i\n", (int)strlcat(str2, "XXXXX", 3), (int)ft_strlcat(str3, "XXXXX", 3));
	printf("results : \nst %s\nft %s\n", str2, str3);
	printf("%i\n%i\n", (int)strlcat(str4, "XXXXX", 0), (int)ft_strlcat(str5, "XXXXX", 0));
	printf("results : \nst %s\nft %s\n", str4, str5);
	/*
	   char str1[] = "test";
	   char str2[] = "test";
	//char str3[] = "test basic du memccpy";
	//char str4[] = "test basic du memccpy";
	//char str5[] = "test";
	//char str6[] = "test";
	//char str7[] = "test";
	*//*
		 printf("%i %i\n", ft_isalpha('a'), isalpha('a'));	
		 printf("%i %i\n", ft_isalpha('A'), isalpha('A'));	
		 printf("%i %i\n", ft_isdigit('1'), isdigit('1'));	
		 printf("%i %i\n", ft_isdigit('2'), isdigit('2'));	
		 printf("%i %i\n", ft_isdigit('3'), isdigit('3'));	
		 printf("%i %i\n", ft_isalpha('-'), isalpha('-'));	
		 printf("%i %i\n", ft_isdigit('\0'), isdigit('\0'));	
		 printf("%i %i\n", ft_isdigit('k'), isdigit('k'));	
		 printf("%i %i\n", ft_isalpha('0'), isalpha('0'));	
		 printf("%i %i\n", ft_isalpha('d'), isalpha('d'));	
		 printf("%i %i\n", ft_isalpha('a'), isalpha('a'));	
		 printf("%i %i\n", ft_isalpha('a'), isalpha('a'));	
		 printf("%i %i\n", ft_isalpha('a'), isalpha('a'));	
		 printf("%i %i\n", ft_isalpha('a'), isalpha('a'));	
		 printf("%i %i\n", ft_isalpha('a'), isalpha('a'));	
		 printf("%i %i\n\n", ft_isalpha('a'), isalpha('a'));

		 printf("st %s\nft %s\n",strnstr("\0", "\0", 0), ft_strnstr("\0", "\0", 0));
		 printf("st %s\nft %s\n",strnstr("uiuihouholei", "hole", 20), ft_strnstr("uiuihouholei", "hole", 20));
		 printf("st %s\nft %s\n",strnstr("uiuihoui", "ho", 20), ft_strnstr("uiuihoui", "ho", 20));
		 printf("st %s\nft %s\n",strnstr("uiuihoui", "ho", ft_strlen("uiuihoui")), ft_strnstr("uiuihoui", "ho", ft_strlen("uiuihoui")));
		 printf("st %s\nft %s\n",strnstr("uiuihoui", "", 20), ft_strnstr("uiuihoui", "", 20));
		 printf("st %s\nft %s\n",strnstr("", "", 20), ft_strnstr("", "", 20));
		 printf("st %s\nft %s\n",strnstr("", "dede", 20), ft_strnstr("", "dede", 20));*/
	return (0);
}
