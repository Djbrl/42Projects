/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_balise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:54:24 by idouidi           #+#    #+#             */
/*   Updated: 2019/12/04 06:18:12 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			is_present(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !is_conversion(str[i]))
	{
		if (str[i - 1] && str[i] == '0' && str[i - 1] >= '0' && str[i - 1] <= '9')
			return (1);
		else if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

t_field		is_balise_flags(const char *str, t_field field)
{
	if (is_present(str, '+') == 0)
		field.flags[0] = '+';
	else
		field.flags[0] = '/';
	if (is_present(str, '-') == 0)
		field.flags[1] = '-';
	else
		field.flags[1] = '/';
	if (is_present(str, ' ') == 0)
		field.flags[2] = ' ';
	else
		field.flags[2] = '/';
	if (is_present(str, '0') == 0)
		field.flags[3] = '0';
	else
		field.flags[3] = '/';
	return (field);
}

t_field		is_balise_width_n_precision(const char *str, t_field field)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && (str[i] == '+' || str[i] == '-' || str[i] == ' '
				|| str[i] == '0'))
		i++;
	j = i;
	while (str[j] && str[j] >= '0' && str[j] <= '9')
		j++;
	tmp = ft_substr(str, i, j);
	field.width = ft_atoi(tmp);
	free(tmp);
	if (str[j] && str[j] == '.')
	{
		j++;
		i = j;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
		tmp = ft_substr(str, j, i);
		field.precision = ft_atoi(tmp);
		free(tmp);
	}
	else
		field.precision = 1;
	return (field);
}

t_field		is_balise(const char *str, t_field field)
{
	t_field tmp;
	t_field tmp2;

	tmp = is_balise_flags(str, field);
	tmp2 = is_balise_width_n_precision(str + 1, tmp);
	return (tmp2);
}
