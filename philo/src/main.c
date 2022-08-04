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

void	dinner(t_philo *philo)
{
	t_data	*data;
	data = philo->info;

	fork_message(philo, "has taken Couteau", philo->couteau);
	pthread_mutex_lock(&data->forks[philo->fourchette]);
	fork_message(philo, "has taken Fourchette", philo->fourchette);
	if (philo->couteau < N_FORK)
		pthread_mutex_lock(&data->forks[philo->couteau]);
	eat_message(philo);
	pthread_mutex_lock(&data->write);
	philo->last_meal = timestamp();
	usleep(300); // eating
	philo->meal_done++;
	pthread_mutex_unlock(&data->write);
	pthread_mutex_unlock(&data->forks[philo->fourchette]);
	if (philo->couteau < N_FORK)
		pthread_mutex_unlock(&data->forks[philo->couteau]);
	pthread_mutex_lock(&data->write);
	data->nb_meals++;
	pthread_mutex_unlock(&data->write);
}

void	*job(void *arg)
{
	t_philo *philo;
	t_data	*data;

	philo = (t_philo*)arg;
	data = philo->info;
	if (philo->id % 2)
		usleep(300);
	int i  = 0;
	pthread_mutex_lock(&data->death);
	while (i++ < 2 && data->death_status == 0)
	{
		dinner(philo);
		if (timestamp() - philo->last_meal > 1)
		{
			data->death_status = 1;
		}
		sleep_message(philo);
		usleep(200); //sleep
	}
	pthread_mutex_unlock(&data->death);
	return ((void *) NULL);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;
	int		death;
	pthread_mutex_t arrrr;

	i = 0;
	death = 0;
	(void)ac;
	(void)av;
	pthread_mutex_init(&arrrr, NULL);
	init_struct(&data);
	init_mutexs(&data);
	init_threads(&data);
	end_threads(&data);
	end_mutexs(&data);
	destroy_struct(&data);
	return (0);
}
