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

int main()
{
	printf("ori:% -.10d\n", 7);
	ft_printf("cpy:% -.10d\n", 7);
	return (0);
}
