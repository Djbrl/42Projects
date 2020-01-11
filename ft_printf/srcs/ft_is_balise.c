/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_balise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:54:24 by idouidi           #+#    #+#             */
/*   Updated: 2020/01/11 17:27:04 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_field		check_star(char *str, va_list args)
{
	int		i;
	int		c;
	t_field	field;

	i = 0;
	field.width = 0;
	field.precision = 0;
	field.flags[0] = '/';
	field.flags[1] = '/';
	while (str[i] && !is_conversion(str[i]))
	{
		if (str[i] == '*')
		{
			c = (int)va_arg(args, int);
			if (c < 0)
				field.flags[1] = '-';
			if (str[i - 1] && str[i - 1] == '.')
				field.precision = c;
			else
				field.width = (c < 0) ? -c : c;
		}
		i++;
	}
	return (field);
}

int			is_present(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !is_conversion(str[i]))
	{
		if (str[i - 1] && str[i] == '0' && nb_digit(str[i - 1]))
			return (0);
		else if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

t_field		is_balise_flags(char *str, t_field field, int check_neg)
{
	field.flags[0] = '/';
	field.flags[1] = '/';
	if (is_present(str, '0') == 1)
		field.flags[0] = '0';
	else
		field.flags[0] = '/';
	if (is_present(str, '-') == 1 || check_neg == 1)
		field.flags[1] = '-';
	else
		field.flags[1] = '/';
	return (field);
}

t_field		is_balise_width_n_precision(char *str, t_field field)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (str[i] && (flags(str[i]) || str[i] == '*'))
		i++;
	j = i;
	while (str[j] && nb_digit(str[j]))
		j++;
	tmp = ft_substr(str, i, j);
	field.width = (field.width == 0) ? ft_atoi(tmp) : field.width;
	free(tmp);
	if (str[j] && str[j] == '.')
	{
		j++;
		i = j;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
		tmp = ft_substr(str, j, i);
		field.precision = (field.precision == 0) ?
			ft_atoi(tmp) : field.precision;
		free(tmp);
	}
	return (field);
}

t_field		is_balise(char *str, va_list args)
{
	t_field		field;
	int		check_neg;


	field = check_star(str, args);
	check_neg = (field.flags[1] == '-') ? 1 : 0;
	field = is_balise_flags(str, field, check_neg);
	field = is_balise_width_n_precision(str, field);
	return (field);
}
