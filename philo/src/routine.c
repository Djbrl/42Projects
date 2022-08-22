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

static int ft_usleep(int time, t_data *data)
{
	int i;

	i = 0;
	while (i < time)
	{
		pthread_mutex_lock(&data->read);
		if (data->death_status)
		{
			pthread_mutex_unlock(&data->read);
			return (1);
		}
		pthread_mutex_unlock(&data->read);
		usleep(1);
	}
	return (0);
}

static int	dinner(t_philo *philo)
{
	t_data	*data;
	int		ret;

	data = philo->info;
	pthread_mutex_lock(&data->forks[philo->fourchette]);
	ret = fork_message(philo, "has taken a fork");
	if (ret)
	{
		pthread_mutex_unlock(&data->forks[philo->fourchette]);
		return (1);
	}
	if (philo->couteau < data->nb_fork)
		pthread_mutex_lock(&data->forks[philo->couteau]);
	ret = fork_message(philo, "has taken a fork");
	pthread_mutex_lock(&data->read);
	ret = eat_message(philo);
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&data->read);
	ft_usleep(data->eat_time, data);
	if (ret)
	{
		pthread_mutex_unlock(&data->forks[philo->fourchette]);
		if (philo->id != data->nb_philo - 1)
			pthread_mutex_unlock(&data->forks[philo->couteau]);
		return (1);
	}
	pthread_mutex_lock(&data->write);
	philo->ate++;
	pthread_mutex_unlock(&data->write);
	pthread_mutex_unlock(&data->forks[philo->fourchette]);
	if (philo->couteau < data->nb_fork)
		pthread_mutex_unlock(&data->forks[philo->couteau]);
	return (0);
}

void	*job(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		i;
	int		ret;

	i = 0;
	philo = (t_philo *)arg;
	data = philo->info;
	while (1)
	{
		pthread_mutex_lock(&data->read);
		if (data->nb_philo == 1 || data->nb_meals == 0 || \
			data->nb_meals == data->meals_ate)
			{pthread_mutex_unlock(&data->read);
			break ;
			}
		pthread_mutex_unlock(&data->read);
		ret = dinner(philo);
		if (ret)
			break ;
		ret = sleep_message(philo);
		if (ret)
			break ;
		usleep(data->sleep_time);
		// if (ret)
		// 	break ;
		ret = think_message(philo);
		if (ret)
			break ;
	}
	return ((void *) NULL);
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
			death_message(&data->philos[i]);
			pthread_mutex_lock(&data->death);
			data->death_status = 1;
			pthread_mutex_unlock(&data->death);
			pthread_mutex_unlock(&data->read);
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
