/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 04:56:59 by dsy               #+#    #+#             */
/*   Updated: 2022/08/19 04:57:00 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	dinner(t_philo *philo)
{
	t_data	*data;
	int		ret;

	data = philo->info;
	pthread_mutex_lock(&data->forks[philo->fourchette]);
	ret = fork_message(philo, "has taken a fork");
	if (ret)
		return (pthread_mutex_unlock(&data->forks[philo->fourchette]) + 1);
	if (philo->couteau < data->nb_fork)
		pthread_mutex_lock(&data->forks[philo->couteau]);
	ret = fork_message(philo, "has taken a fork");
	pthread_mutex_lock(&data->read);
	ret = eat_message(philo);
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&data->read);
	usleep(data->eat_time);
	pthread_mutex_lock(&data->write);
	philo->ate++;
	pthread_mutex_unlock(&data->write);
	pthread_mutex_unlock(&data->forks[philo->fourchette]);
	if (philo->couteau < data->nb_fork)
		pthread_mutex_unlock(&data->forks[philo->couteau]);
	return (0);
}

static int	ftn_stop(t_philo *philo)
{
	int		ret;
	t_data	*data;

	data = philo->info;
	ret = dinner(philo);
	if (ret)
		return (1);
	ret = sleep_message(philo);
	if (ret)
		return (1);
	usleep(data->sleep_time);
	ret = think_message(philo);
	if (ret)
		return (1);
	return (0);
}

void	*job(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->info;
	if (philo->id % 2 == 0)
		usleep(5000);
	while (1)
	{
		pthread_mutex_lock(&data->read);
		if (data->nb_philo == 1 || data->nb_meals == 0 || \
			data->nb_meals == data->meals_ate)
		{
			pthread_mutex_unlock(&data->read);
			break ;
		}
		pthread_mutex_unlock(&data->read);
		if (ftn_stop(philo))
			break ;
	}
	return ((void *) NULL);
}

void	death(t_data *data, int id)
{
	death_message(&data->philos[id]);
	pthread_mutex_lock(&data->death);
	data->death_status = 1;
	pthread_mutex_unlock(&data->death);
	pthread_mutex_unlock(&data->read);
}

void	deathloop(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->read);
		if (timestamp() - data->philos[i].last_meal > data->death_time)
		{
			death(data, i);
			break ;
		}
		pthread_mutex_lock(&data->write);
		if (data->philos[i].ate >= data->nb_meals)
			data->meals_ate++;
		pthread_mutex_unlock(&data->write);
		pthread_mutex_unlock(&data->read);
		i++;
		if (i == data->nb_philo)
			i = 0;
		if (data->meals_ate == data->nb_meals)
			break ;
	}
}
