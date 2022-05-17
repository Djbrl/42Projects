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
	int		j;
	int		count;

	i = 1;
	j = 0;
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
		j = 0;
	}
	return (count);
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