/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:28:13 by dsy               #+#    #+#             */
/*   Updated: 2020/01/03 21:10:06 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	check_zero(char *str)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '0' && (flags(str[i - 1]) || flags(str[i + 1])))
			check = 1;
		i++;
	}
	return (check);
}

int	pars_hexa(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] && !is_conversion(s[i]))
	{
		if (s[i] == '.' && !(nb_digit(s[i + 1]) || s[i + 1] == '*'
			 || is_conversion(s[i + 1])))
			return (0);
		if (s[i + 1] && s[i] == '*' && !(s[i + 1] == '.'
					|| is_conversion(s[i + 1])))
			return (0);
		j = ((s[i] == '.' || s[i] == '-') && check_zero(s) == 1) ? 1 : 0;
		if ((s[i] == '.' || s[i] == '-') && j == 1)
			return (0);
		i++;
	}
	return (1);
}

int	pars_decimal(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] && !is_conversion(s[i]))
	{
		if (s[i] == '.' && !(nb_digit(s[i + 1]) || s[i + 1] == '*' ||
			 is_conversion(s[i + 1])))
			return (0);
		if (s[i] == '*' && !(s[i + 1] == '.' || is_conversion(s[i + 1])))
			return (0);
		j = ((s[i] == '.' || s[i] == '-') && check_zero(s) == 1) ? 1 : 0;
		if ((s[i] == '.' || s[i] == '-') && j == 1)
			return (0);
		i++;
	}
	return (1);
}

int	pars_str(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] && !is_conversion(s[i]))
	{
		j = ((s[i] == '.' || s[i] == '-' || s[i] == '0') && check_zero(s) == 1) ? 1 : 0;
		if (s[i] == '+' || s[i] == ' ' || j == 1)
			return (0);
		if (s[i] == '.' && !(nb_digit(s[i + 1]) || s[i + 1] == '*' || is_conversion(s[i + 1])))
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

	i = 0;
	while (s[i] && !is_conversion(s[i]))
	{
		j = ((s[i] == '-' || s[i] == '0') && check_zero(s) == 1) ? 1 : 0;
		if (s[i] == '+' || s[i] == ' ' || s[i] == '.' || j == 1)
			return (0);
		i++;
	}
	return (1);
}
