/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:56:44 by dsy               #+#    #+#             */
/*   Updated: 2019/10/17 16:56:56 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
t_list	*ft_lstnew(void *content)
{
	t_list	*New_elem;
	if (!(New_elem = malloc(sizeof(*New_elem))))
		return (NULL);
	if (!content)
		New_elem->content = NULL;
	if (!(New_elem->content = (void *)malloc(sizeof(t_list) * ft_strlen(content))))
		return NULL;
	ft_memcpy(New_elem->content, content, ft_strlen(content));
	New_elem->next = NULL;
	return (New_elem);
}
