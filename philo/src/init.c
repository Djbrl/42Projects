/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 04:41:35 by dsy               #+#    #+#             */
/*   Updated: 2022/07/22 04:41:36 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < N_PHILO)
	{
		data->philos[i].id = i;
		data->philos[i].meal_done = 0;
		data->philos[i].last_meal = 0;
		data->philos[i].fourchette = i;
		data->philos[i].couteau = (i + 1);
		data->philos[i].info = data;
		if (pthread_create(&data->philos[i].thread, NULL, &job, (void *)&data->philos[i]) != 0)
			return (exit_err(PCREAT_ERR, data));
		i++;
	}
	return (1);
}

int	end_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < N_PHILO)
	{
		if (pthread_join(data->philos[i].thread, NULL))
			return (exit_err(PJOIN_ERR, data));
		i++;
	}
	return (1);
}

int	init_mutexs(t_data *data)
{
	int	i;

	i = 0;
	while (i < N_FORK)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (exit_err(MUTEX_INIT, data));
		i++;
	}
	if (pthread_mutex_init(&data->write, NULL))
			return (exit_err(MUTEX_INIT, data));
	if (pthread_mutex_init(&data->meal, NULL))
		return (exit_err(MUTEX_INIT, data));

	return (1);
}

int	end_mutexs(t_data *data)
{
	int	i;

	i = 0;
	while (i < N_FORK)
	{
		if (pthread_mutex_destroy(&data->forks[i]))
			return (exit_err(MUTEX_KILL, data));
		i++;
	}
	if (pthread_mutex_destroy(&data->write))
		return (exit_err(MUTEX_KILL, data));
	if (pthread_mutex_destroy(&data->meal))
		return (exit_err(MUTEX_KILL, data));
	return (1);
}