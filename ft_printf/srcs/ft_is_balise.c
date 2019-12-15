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

int		pars(char *str)
{
	int	i;
	i = 0;
	while (str[i] && !is_conversion(str[i]))
		i++;
	if (str[i] == 'x' || str[i] == 'X')
		if(pars_hexa(str) == 1)
			return(1);
	if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u')
		if (pars_decimal(str) == 1)
			return (1);
	if (str[i] == 'c' || str[i] == 'p')
		if (pars_char(str) == 1)
			return (1);
	if (str[i] == 's')
		if (pars_str(str) == 1)
			return (1);
	return (0);
}

int			is_present(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !is_conversion(str[i]))
	{
		if (str[i - 1] && str[i] == '0' && str[i - 1] >= '0' && str[i - 1] <= '9')
			return (0);
		else if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

t_field		is_balise_flags(char *str, t_field field)
{
	if (is_present(str, '+') == 1)
		field.flags[0] = '+';
	if (is_present(str, '-') == 1)
		field.flags[1] = '-';
	if (is_present(str, ' ') == 1)
		field.flags[2] = ' ';
	if (is_present(str, '0') == 1)
		field.flags[3] = '0';
	field.flags[4] = 0;
	return (field);
}

t_field		is_balise_width_n_precision(char *str, t_field field)
{
	char		*tmp;
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
	if (str[j] && str[j] == '.')
	{
		j++;
		i = j;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
		tmp = ft_substr(str, j, i);
		field.precision = ft_atoi(tmp);
	}
	return (field);
}

t_field		is_balise(char *str, va_list args)
{
	t_field field = {"////", 0, 0, 0, 0};
	int	c;

	c = 0;
	if (pars(str) == 0)
		field.error = 1;
	else
	{
		field = is_balise_flags(str, field);
		field = is_balise_width_n_precision(str, field);
		if (is_present(str, '*') == 1)
		{
			c = (int)va_arg(args, int); 
			if (is_present(str, '.') == 1)
				field.precision = c;
			else
				field.width = c;		
        	}
	}
	return (field);
}
