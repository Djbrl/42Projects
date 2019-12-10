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
  //printf("%d %d %d %d %d %d %d %d\n", 0, 1, 9, 10, 11, 9999, 10000, 100001);
  //printf("%d %d %d %d %d %d %d %d\n", 0, -1, -9, -10, -11, -9999, -10000, -100001);
  printf("%d\n", 12345);
  printf("%d\n", -12345);
  printf("%+d\n", 12345);
  printf("% d\n", 12345);
  printf("% d\n", -12345);
  printf("%.8d\n", 12345);
  printf("%08d\n", 12345);
  printf("%12.8d\n", 12345);
  printf("%8.12d\n", 12345);
  printf("%-12d\n", 12345);
   printf("%-12.8d\n", 12345);
  printf("%-.12d\n", 12345);
  //printf("%.0d\n", 0);
  //printf("% .0d\n", 0);

  //ft_printf("%d %d %d %d %d %d %d %d\n", 0, 1, 9, 10, 11, 9999, 10000, 100001);
  //ft_printf("%d %d %d %d %d %d %d %d\n", 0, -1, -9, -10, -11, -9999, -10000, -100001);
 ft_printf("%d\n", 12345);
  ft_printf("%d\n", -12345);
  ft_printf("%+d\n", 12345);
  ft_printf("% d\n", 12345);
  ft_printf("% d\n", -12345);
  ft_printf("%.8d\n", 12345);
  ft_printf("%08d\n", 12345);
  ft_printf("%12.8d\n", 12345);
  ft_printf("%8.12d\n", 12345);
  ft_printf("%-12d\n", 12345);
  ft_printf("%-12.8d\n", 12345);
  ft_printf("%-.12d\n", 12345);
	return (0);
}
