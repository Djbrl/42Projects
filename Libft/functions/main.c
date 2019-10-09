/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:48:58 by dsy               #+#    #+#             */
/*   Updated: 2019/10/09 15:04:04 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int		ft_strlen(char *);
char	*ft_strchr(char *, int);
void	*ft_memset(void *, int, size_t);
void	*ft_memcpy(void *, void *, size_t n);
void	*ft_memccpy(void *, void *, int, size_t n);
int		main(int ac, char **av)
{
	(void)av;
	(void)ac;
	char	str[] = "titi";
	char	stra[] = "titi";
	char	strs[] = "titi";
	char	strd[] = "titi";
	char	strf[] = "titi";
	char	strg[] = "titi";
	char	strh[] = "titi";
	char	strj[] = "titi";
	char	strq[] = "titi";
	char	strw[] = "titi";
	char	stre[] = "titi";
	char	strr[] = "titi";
	char	strt[] = "titi";
	char	stry[] = "titi";
	char	stru[] = "titi";
	char	str2[] = "toto";
	char	str3[] = "tutu";
	char	str4[] = "tototutu";
	char	str5[] = "";
	char	str6[] = "1234";
	char	*str7 = NULL;
	/*char	*str1 = " ";
	char	*str2 = "/n";
	char	*str3 = NULL;
	int		n = 0;

	printf("%i\n", ft_strlen(str));
	printf("%i\n", ft_strlen(str1));
	printf("%i\n", ft_strlen(str2));
	printf("%i\n", ft_strlen(str3));

	printf("%s\n", ft_strchr(str, 0));
	printf("%s\n", strchr(str, 0));
	printf("%s\n", ft_strchr(str, -9));
	printf("%s\n", strchr(str, -9));
	printf("%s\n", ft_strchr(str, 53));
	printf("%s\n", strchr(str, 53));
	printf("%s\n", ft_strchr(str, 123));
	printf("%s\n", strchr(str, 123));

	printf("%s\n", ft_memset(str2, 'X', 10));
	printf("%s\n", memset(str2, 'X', 10));
	printf("%s\n", ft_memset(str3, 'X', 0));
	printf("%s\n", memset(str3, 'X', 0));
	printf("%s\n", ft_memset(str4, 'X', 1000));
	printf("%s\n", memset(str4, 'X', 1000));
	printf("%s\n", ft_memset(str5, 'X', -5));
	printf("%s\n", memset(str5, 'X', -5));

	printf("%s\n", ft_memcpy(str, str2, 3));
	printf("m %s\n", memcpy(stra, str2, 3));
	printf("%s\n", ft_memcpy(strq, str2, 0));
	printf("m %s\n", memcpy(strs, str2, 0));
	printf("%s\n", ft_memcpy(stre, str2, 5));
	printf("m %s\n", memcpy(strd, str2, 5));
	printf("%s\n", ft_memcpy(strr, str4, 3));
	printf("m %s\n", memcpy(strf, str4, 3));
	printf("%s\n", ft_memcpy(stru, str7, 0));
	printf("m %s\n", memcpy(strj, str7, 0));
*/	
	

	printf("%s\n", ft_memccpy(stra, str2, 'o', 0));
	printf("m %s\n", memccpy(str, str2, 'o', 0));
	printf("%s\n", ft_memccpy(strs, str2, 'o', 2));
	printf("m %s\n", memccpy(strq, str2, 'o', 2));
	printf("%s\n", ft_memccpy(strd, str2, 'o', 3));
	printf("m %s\n", memccpy(strw, str2, 'o', 3));
	printf("%s\n", ft_memccpy(strf, str2, 'o', 4));
	printf("m %s\n", memccpy(stre, str2, 'o', 4));
	printf("results : memstr %s ftstra %s\n", str, stra);
	printf("results : memstr %s ftstra %s\n", strq, strs);
	printf("results : memstr %s ftstra %s\n", strw, strd);
	printf("results : memstr %s ftstra %s\n", stre, strf);
	return (0);
}
