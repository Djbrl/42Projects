/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:28:13 by dsy               #+#    #+#             */
/*   Updated: 2019/12/30 15:42:33 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	check_zero(char *str, int i)
{
	int	j;
	int	check;

	check = 0;
	j = 0;
	while (j < i)
	{
		if (str[j] == '0' && (flags(str[j - 1]) || flags(str[j + 1])))
			check = 1;
		j++;
		// printf("j = %d\n", j);
	}
	// printf("check = %d\n", check);
	// printf("\n ------ \n");
	return (check);
}

int	pars_hexa(char *s, int check)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] && !is_conversion(s[i]))
	{
		if (s[i] > '0' && s[i] <= '9')
			check = 1;
		if (s[i + 1] && s[i] == '.' && !(nb_digit(s[i + 1]) || s[i + 1] == '*'))
			return (0);
		if (s[i + 1] && s[i] == '*' && !(s[i + 1] == '.'
					|| is_conversion(s[i + 1])))
			return (0);
		j = (s[i] == '.' && check_zero(s, i) == 1) ? 1 : i + 1;
		if ((s[i] == '.' && j == 1) || s[i] == '+' || s[i] == ' ')
			return (0);
		while (check == 0 && s[j] && flags(s[i]) && flags(s[j]))
		{
			if (((s[i] == '-' || s[i] == '0') &&
						(s[j] == '-' || s[j] == '0')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	pars_decimal(char *s, int check)
{
	int	i;
	int	j;

	i = 0;
	check = 0;
	while (s[i] && !is_conversion(s[i]))
	{
		if (s[i] > '0' && s[i] <= '9')
			check = 1;
		if (s[i + 1] && s[i] == '.' && !(nb_digit(s[i + 1]) || s[i + 1] == '*'))
			return (0);
		if (s[i + 1] && s[i] == '*' && !(s[i + 1] == '.' ||
					is_conversion(s[i + 1])))
			return (0);
		j = (s[i] == '.' && check_zero(s, i) == 1) ? 1 : i + 1;
		if (s[i] == '.' && j == 1)
			return (0);
		while (check == 0 && s[j] && (flags(s[i]) && flags(s[j])))
		{
			if ((((s[i] == ' ' || s[i] == '+') && (s[j] == ' ' || s[j] == '+'))
			|| ((s[i] == '-' || check_zero(s, i)) &&
			(s[j] == '-' || check_zero(s, j)))))
				return (0);
			j++;
		}
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
		j = check_zero(s, i);
		if (s[i] == '+' || s[i] == ' ' || j == 1)
			return (0);
		if (s[i + 1] && s[i] == '.' && !(nb_digit(s[i + 1]) ||
					s[i + 1] == '*'))
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
		if (s[i] > '0' && s[i] <= '9')
			break ;
		j = check_zero(s, i);
		if (s[i] == '+' || s[i] == ' ' || s[i] == '.' || j == 1)
			return (0);
		i++;
	}
	return (1);
}
