/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:48:58 by dsy               #+#    #+#             */
/*   Updated: 2019/10/23 18:24:29 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int		main()
{
	printf("%s\n", ft_strtrim("          ", " "));	
//	char *str = calloc(1, 0);
//	char *str1 = calloc(SIZE_MAX - 1, SIZE_MAX - 1);
//	char *str2 = calloc(0, SIZE_MAX);
//	char *str3 = ft_calloc(1, 0);
//	char *str4 = ft_calloc(SIZE_MAX - 1, SIZE_MAX - 1);
/*	char *str5 = ft_calloc(0, SIZE_MAX);
	printf("%s\n", str);
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	printf("%s\n", str4);
	printf("%s\n", str5);
	*//*ft_split("", '\0');
	ft_split("          ", ' ');
	ft_split(" ", ' ');
	*/
/*	char **str = ft_split("chaine de test", ' ');
	int i = 0;
	while (str[i] != 0)
	{
		printf("%s\n", str[i]);
		i++;
	}*/
/*	printf("%s\n", ft_strtrim("abacbcabacbacbacbacbacbabc", "abc"));
	printf("%s\n", ft_strtrim("aaaaaaaaaaaaaaaaaaaaaaa", "a"));
	printf("%s\n", ft_strtrim("bbbbbbbbbbbbbbbbbbbbbbbbbbb", "abc"));
	printf("%s\n", ft_strtrim("", ""));
	printf("%s\n", ft_strtrim("          ", "   "));
*/
	/*
	char str[] = "test du strlcpy!";
	char str1[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	char str2[] = "test du strlcpy!";
	char str3[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	char str4[] = "test du strlcpy!";
	char str5[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	char str6[] = "test du strlcpy!";
	char str7[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
*/
/*	char *s1 = "where is my ";
char *s2 = "malloc ???";
char *res = ft_strjoin (s1, s2);
printf("%s\n", res);*/
	/*
	printf("%s\n%s\n", memmove(str, str1, 16), ft_memmove(str2, str3, 16));
	printf("%s\n%s\n", memmove(str5, str4, 16), ft_memmove(str7, str6, 16));
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
