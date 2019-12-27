/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 12:51:43 by dsy               #+#    #+#             */
/*   Updated: 2019/12/27 12:52:51 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_capitalize(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
					|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v'))
			i++;
		while (str[i] && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] + 32;
			i++;
		}
		i++;
	}
	return (str);
}
