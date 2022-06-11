/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:01:49 by dsy               #+#    #+#             */
/*   Updated: 2022/05/10 15:29:26 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args(char *av, int count)
{
	int		j;
	char	**split;

	j = 0;
	split = ft_split(av, ' ');
	while (split[j] != 0)
	{
		count++;
		j++;
	}
	free_split(split);
	return (count);
}

int	get_nb_args(int ac, char **av)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (i < ac)
	{
		if (((int)ft_strlen(av[i])) > 1)
		{
			count = count_args(av[i], count);
		}
		else
			count++;
		i++;
	}
	return (count);
}

char	**free_norme_mdr(char **args, int stop)
{
	int	i;

	i = 0;
	while (i < stop - 1)
		free(args[i++]);
	free(args);
	(void)size;
	return (NULL);
}

int	bad_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

char	**input_checker(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	**in;
	char	**args;

	i = 1;
	j = 0;
	k = 0;
	args = (char **)malloc(sizeof(char *) * get_nb_args(ac, av));
	while (i < ac)
	{
		if (((ft_strlen(av[i]) > 9) && (ft_strcmp(av[i], "2147483647") > 0)) \
		|| ((ft_strlen(av[i]) > 10) && (ft_strcmp(av[i], "-2147483648") > 0)) \
		|| bad_string(av[i]))
			return (free_norme_mdr(args, i));
		in = ft_split(av[i], ' ');
		while (in[j])
			args[k++] = ft_strdup(in[j++]);
		free_split(in);
		j = 0;
		i++;
	}
	i = 0;
	return (check_dup(args, get_nb_args(ac, av)));
}
