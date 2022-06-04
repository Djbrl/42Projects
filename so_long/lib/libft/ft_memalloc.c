/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:03:56 by dsy               #+#    #+#             */
/*   Updated: 2022/04/05 16:09:16 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memalloc(size_t n)
{
	void	*mem;

	mem = malloc(sizeof(n));
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, n);
	return (mem);
}
