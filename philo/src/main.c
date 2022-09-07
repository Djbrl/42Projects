/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 05:44:18 by dsy               #+#    #+#             */
/*   Updated: 2022/06/24 05:45:03 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_num(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	input_parsing(char **av, t_data *data)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!is_num(av[i]) || ft_atoi(av[i]) < 0 || ft_atoi(av[i]) == 0)
			return (0);
		i++;
	}
	data->nb_meals = -1;
	data->nb_philo = ft_atoi(av[1]);
	data->nb_fork = data->nb_philo;
	data->death_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]) * 1000;
	data->sleep_time = ft_atoi(av[4]) * 1000;
	if (av[5])
	{
		if (ft_atoi(av[5]) < 0)
			return (0);
		data->nb_meals = ft_atoi(av[5]);
	}
	return (1);
}

static int	rip_too_soon(char *err)
{
	printf("%s", RED_COLOR);
	printf("%s", err);
	printf("%s", END_COLOR);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (rip_too_soon(ARG_ERR));
	if (!input_parsing(av, &data))
		return (rip_too_soon(ARG_ERR));
	init_struct(&data);
	init_mutexs(&data);
	init_threads(&data);
	deathloop(&data);
	end_threads(&data);
	end_mutexs(&data);
	destroy_struct(&data);
	return (0);
}
