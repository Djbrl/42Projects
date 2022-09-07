/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:39:00 by dsy               #+#    #+#             */
/*   Updated: 2022/09/07 12:39:01 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		if (data->philos[i].ate == data->nb_meals)
		{
			data->meals_ate++;
			data->philos[i].done = 1;
		}
		pthread_mutex_unlock(&data->write);
		pthread_mutex_unlock(&data->read);
		i++;
		if (i == data->nb_philo)
			i = 0;
		if (all_done(data))
			break ;
	}
}
