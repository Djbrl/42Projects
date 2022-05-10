/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:01:49 by dsy               #+#    #+#             */
/*   Updated: 2022/05/10 15:29:17 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}

void	compare_sort_norme(char **s1, char **s2)
{
	free(*s1);
	*s1 = ft_strdup(*s2);
}

void	compare_sort(int size, char **sorted)
{
	int		k;
	int		j;
	char	*temp;

	j = 0;
	k = 0;
	while (k < size - 1)
	{
		while (sorted[j] && sorted[j + 1])
		{
			temp = ft_strdup(sorted[j]);
			if (ft_atoi(sorted[j]) > ft_atoi(sorted[j + 1]))
			{
				compare_sort_norme(&sorted[j], &sorted[j + 1]);
				compare_sort_norme(&sorted[j + 1], &temp);
				free(temp);
			}
			else
				free(temp);
			j++;
		}
		k++;
		j = 0;
	}
}

char	**sort(char **array, int size)
{
	int		i;
	int		j;
	char	**sorted;

	j = 0;
	i = 0;
	sorted = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		sorted[j] = ft_strdup(array[i]);
		i++;
		j++;
	}
	sorted[j] = 0;
	i = 0;
	while (i < size)
		free(array[i++]);
	free(array);
	compare_sort(size, sorted);
	return (sorted);
}

char	**check_dup(char **args, int size)
{
	char	**sorted;
	int		i;
	int		j;

	i = 0;
	j = 0;
	sorted = sort(args, size);
	while (sorted[i] && sorted[i + 1])
	{
		if (ft_strcmp(sorted[i], sorted[i + 1]) == 0)
		{
			while (sorted[j])
				free(sorted[j++]);
			free(sorted);
			return (NULL);
		}
		else
			i++;
	}
	j = 0;
	return (sorted);
}
