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

void	*job(void *arg)
{
	t_philo *philo;
	t_data	*data;

	philo = (t_philo*)arg;
	data = philo->info;
	pthread_mutex_lock(&data->forks[philo->fourchette]);
	fork_message(philo, "has taken Fourchette", philo->fourchette);
	pthread_mutex_lock(&data->forks[philo->couteau]);
	fork_message(philo, "has taken Couteau", philo->couteau);
	eat_message(philo);
	philo->last_meal = timestamp();
	pthread_mutex_lock(&data->meal);
	usleep(1000);
	printf("time stamp [%lld]\n", timestamp() - philo->last_meal);
	pthread_mutex_unlock(&data->meal);
	pthread_mutex_unlock(&data->forks[philo->fourchette]);
	pthread_mutex_unlock(&data->forks[philo->couteau]);
	return ((void *) NULL);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	(void)ac;
	(void)av;
	init_struct(&data);
	init_mutexs(&data);
	init_threads(&data);
	end_threads(&data);
	end_mutexs(&data);
	destroy_struct(&data);
	return (0);
}
