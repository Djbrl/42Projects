/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:36:26 by dsy               #+#    #+#             */
/*   Updated: 2022/08/07 13:36:27 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fork_message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->death);
	if (philo->info->death_status)
	{
		pthread_mutex_unlock(&philo->info->death);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->death);
	pthread_mutex_lock(&philo->info->status);
	printf("%lld %d %s\n", timestamp() - philo->info->start_time, \
		philo->id, msg);
	pthread_mutex_unlock(&philo->info->status);
	return (0);
}

int	think_message(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->death);
	if (philo->info->death_status)
	{
		pthread_mutex_unlock(&philo->info->death);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->death);
	pthread_mutex_lock(&philo->info->status);
	printf("%lld %d %s\n", timestamp() - philo->info->start_time, philo->id, \
		"is thinking");
	pthread_mutex_unlock(&philo->info->status);
	return (0);
}

int	eat_message(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->death);
	if (philo->info->death_status)
	{
		pthread_mutex_unlock(&philo->info->death);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->death);
	pthread_mutex_lock(&philo->info->status);
	printf("%lld %d %s\n", timestamp() - philo->info->start_time, philo->id, \
		"is eating");
	pthread_mutex_unlock(&philo->info->status);
	return (0);
}

int	sleep_message(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->death);
	if (philo->info->death_status)
	{
		pthread_mutex_unlock(&philo->info->death);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->death);
	pthread_mutex_lock(&philo->info->status);
	printf("%lld %d %s\n", timestamp() - philo->info->start_time, philo->id, \
		"is sleeping");
	pthread_mutex_unlock(&philo->info->status);
	return (0);
}

int	death_message(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->death);
	if (philo->info->death_status)
	{
		pthread_mutex_unlock(&philo->info->death);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->death);
	pthread_mutex_lock(&philo->info->status);
	printf("%lld %d %s\n", timestamp() - philo->info->start_time, philo->id, \
		"died");
	pthread_mutex_unlock(&philo->info->status);
	return (0);
}
