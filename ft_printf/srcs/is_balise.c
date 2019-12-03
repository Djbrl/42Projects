/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_balise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:54:24 by idouidi           #+#    #+#             */
/*   Updated: 2019/12/04 00:49:23 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			is_present(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !is_conversion(str[i]))
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void		is_balise_flags(const char *str)
{
	t_field	*field;

	field = NULL;
	if (is_present(str, '+') == 0)
		field->flags[0] = '+';
	else
		field->flags[0] = '/';
	if (is_present(str, '-') == 0)
		field->flags[1] = '-';
	else
		field->flags[1] = '/';
	if (is_present(str, ' ') == 0)
		field->flags[2] = ' ';
	else
		field->flags[2] = '/';
	if (is_present(str, '0') == 0)
		field->flags[3] = '0';
	else
		field->flags[3] = '/';
}

void		is_balise_width(const char *str)
{
	char	*tmp;
	int		i;
	int		j;
	t_field	*field;

	field = NULL;
	i = 0;
	j = 0;
	tmp = NULL;
	while (str[i] && (str[i] == '+' || str[i] == '-'
				|| str[i] == ' ' || str[i] == '0'))
		i++;
	j = i;
	while (str[j] && str[j] >= '0' && str[j] <= '9')
		j++;
	tmp = ft_substr(str, i, j);
	field->width = ft_atoi(tmp);
	free(tmp);
}
