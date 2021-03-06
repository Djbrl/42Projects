/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:04:38 by dsy               #+#    #+#             */
/*   Updated: 2020/02/07 05:04:39 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	check_zero(char *str)
{
	int	i;

	i = 1;
	while (str[i] && !is_conversion(str[i]))
	{
		if (str[i] == '0' && (str[i - 1] == '%' || str[i + 1] == '-'))
			return (1);
		i++;
	}
	return (0);
}

int	pars_hexa(char *s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i] && !is_conversion(s[i]))
	{
		if (s[i] == '.' && !(nb_digit(s[i + 1]) || s[i + 1] == '*'
			|| is_conversion(s[i + 1])))
			return (0);
		if (s[i] == '*' && !(s[i + 1] == '.' || is_conversion(s[i + 1])))
			return (0);
		j = (s[i] == '0' && s[i + 1] == '-') ? 1 : 0;
		if (s[i] == '-' && j == 1)
			return (0);
		i++;
	}
	return (1);
}

int	pars_decimal(char *s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i] && !is_conversion(s[i]))
	{
		if (s[i] == '.' && !(nb_digit(s[i + 1]) || s[i + 1] == '*' ||
			is_conversion(s[i + 1])))
			return (0);
		if (s[i] == '*' && !(s[i + 1] == '.' || is_conversion(s[i + 1])))
			return (0);
		j = (s[i] == '0' && s[i + 1] == '-') ? 1 : 0;
		if (s[i] == '-' && j == 1)
			return (0);
		i++;
	}
	return (1);
}

int	pars_str(char *s)
{
	int	i;

	i = 1;
	while (s[i] && !is_conversion(s[i]))
	{
		if (s[i] == '+' || s[i] == ' ' || (s[i] == '.' && check_zero(s) == 1))
			return (0);
		if (s[i] == '.' && !(nb_digit(s[i + 1]) || s[i + 1] == '*' ||
			is_conversion(s[i + 1])))
			return (0);
		if (s[i + 1] && s[i] == '*' && !(s[i + 1] == '.' ||
			is_conversion(s[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

int	pars_char_n_add(char *s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i] && !is_conversion(s[i]))
	{
		j = ((s[i] == '-' || s[i] == '0') && check_zero(s) == 1) ? 1 : 0;
		if (s[i] == '+' || s[i] == ' ' || s[i] == '.' || j == 1)
			return (0);
		i++;
	}
	return (1);
}
