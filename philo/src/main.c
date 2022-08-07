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
		if (!is_num(av[i]))
			return (0);
		i++;
	}
	data->nb_meals = 0;
	data->nb_philo = ft_atoi(av[1]);
	data->nb_fork = data->nb_philo;
	data->death_time = ft_atoi(av[2]);
	data->sleep_time = ft_atoi(av[3]) * 1000;
	data->eat_time = ft_atoi(av[4]) * 1000;
	if (av[5])
		data->nb_meals = ft_atoi(av[5]);
	return (1);
}

void	dinner(t_philo *philo)
{
	t_data	*data;

	data = philo->info;
	pthread_mutex_lock(&data->forks[philo->fourchette]);
	fork_message(philo, "has taken a fork", philo->couteau);
	if (philo->couteau < data->nb_fork)
		pthread_mutex_lock(&data->forks[philo->couteau]);
	fork_message(philo, "has taken a fork", philo->fourchette);
	//DEBUG PRINT
	pthread_mutex_lock(&data->write);
	printf("GUEST %i is about to eat! They've been waiting for %lli ms\n", philo->id, timestamp() - philo->last_meal);
	pthread_mutex_unlock(&data->write);
	//DEBUG PRINT
	eat_message(philo);
	pthread_mutex_lock(&data->write);
	philo->last_meal = timestamp();
	usleep(data->eat_time);
	philo->meal_done++;
	pthread_mutex_unlock(&data->write);
	pthread_mutex_unlock(&data->forks[philo->fourchette]);
	if (philo->couteau < data->nb_fork)
		pthread_mutex_unlock(&data->forks[philo->couteau]);
}

void	*job(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	data = philo->info;
	if (philo->id % 2 == 0)
		usleep(10000);
	while (!data->death_status)
	{
		if (i == data->nb_meals && data->nb_meals != 0)
			break ;
		dinner(philo);
		sleep_message(philo);
		usleep(data->sleep_time);
		think_message(philo);
		i++;
	}
	return ((void *) NULL);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (exit_err(ARG_ERR, &data));
	if (!input_parsing(av, &data))
		return (exit_err(ARG_ERR, &data));
	init_struct(&data);
	init_mutexs(&data);
	init_threads(&data);
	//DATA RACE
	// int i = 0;
	// while (i < data.nb_philo)
	// {
	// 	if (timestamp() - data.philos[i].last_meal > data.death_time)
	// 	{
	// 		printf("%i dead\n", i);
	// 		break;
	// 	}
	// 	i++;
	// 	if (i == data.nb_philo)
	// 		i = 0;
	// }
	//DATA RACE
	end_threads(&data);
	end_mutexs(&data);
	destroy_struct(&data);
	return (0);
}
