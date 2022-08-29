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
	pthread_mutex_lock(&philo->info->write);
	write(1, ft_itoa((int)(timestamp() - philo->info->start_time)), ft_strlen(ft_itoa((int)(timestamp() - philo->info->start_time))));
	write(1, " ", 1);
	write(1, ft_itoa(philo->id), ft_strlen(ft_itoa(philo->id)));
	write(1, " ", 1);
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	pthread_mutex_unlock(&philo->info->write);
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
	pthread_mutex_lock(&philo->info->write);
	write(1, ft_itoa((int)(timestamp() - philo->info->start_time)), ft_strlen(ft_itoa((int)(timestamp() - philo->info->start_time))));
	write(1, " ", 1);
	write(1, ft_itoa(philo->id), ft_strlen(ft_itoa(philo->id)));
	write(1, " ", 1);
	write(1, "thinking\n", 9);
	pthread_mutex_unlock(&philo->info->write);
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
	pthread_mutex_lock(&philo->info->write);
	write(1, ft_itoa((int)(timestamp() - philo->info->start_time)), ft_strlen(ft_itoa((int)(timestamp() - philo->info->start_time))));
	write(1, " ", 1);
	write(1, ft_itoa(philo->id), ft_strlen(ft_itoa(philo->id)));
	write(1, " ", 1);
	write(1, "eat\n", 4);
	pthread_mutex_unlock(&philo->info->write);
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
	pthread_mutex_lock(&philo->info->write);
	write(1, ft_itoa((int)(timestamp() - philo->info->start_time)), ft_strlen(ft_itoa((int)(timestamp() - philo->info->start_time))));
	write(1, " ", 1);
	write(1, ft_itoa(philo->id), ft_strlen(ft_itoa(philo->id)));
	write(1, " ", 1);
	write(1, "sleep\n", 6);
	pthread_mutex_unlock(&philo->info->write);
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
	pthread_mutex_lock(&philo->info->write);
	write(1, ft_itoa((int)(timestamp() - philo->info->start_time)), ft_strlen(ft_itoa((int)(timestamp() - philo->info->start_time))));
	write(1, " ", 1);
	write(1, ft_itoa(philo->id), ft_strlen(ft_itoa(philo->id)));
	write(1, " ", 1);
	write(1, "died\n", 5);
	pthread_mutex_unlock(&philo->info->write);
	return (0);
}
