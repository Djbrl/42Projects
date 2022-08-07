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

void	fork_message(t_philo *philo, char *msg, int id)
{
	pthread_mutex_lock(&philo->info->write);
	printf("[%lld] ", timestamp() - philo->info->start_time);
	printf("%s", YLW_COLOR);
	printf("%d", philo->id);
	printf("%s", END_COLOR);
	printf(" %s", msg);
	printf("%s", YLW_COLOR);
	printf(" (%d)\n", id);
	printf("%s", END_COLOR);
	pthread_mutex_unlock(&philo->info->write);
}

void	think_message(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->write);
	printf("[%lld] ", timestamp() - philo->info->start_time);
	printf("%s", YLW_COLOR);
	printf("%d", philo->id);
	printf("%s", END_COLOR);
	printf(" %s", "is ");
	printf("%s", GREEN_COLOR);
	printf("thinking\n");
	printf("%s", END_COLOR);
	pthread_mutex_unlock(&philo->info->write);
}

void	eat_message(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->write);
	printf("[%lld] ", timestamp() - philo->info->start_time);
	printf("%s", YLW_COLOR);
	printf("%d", philo->id);
	printf("%s", END_COLOR);
	printf(" %s", "is ");
	printf("%s", GREEN_COLOR);
	printf("eating\n");
	printf("%s", END_COLOR);
	pthread_mutex_unlock(&philo->info->write);
}

void	sleep_message(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->write);
	printf("[%lld] ", timestamp() - philo->info->start_time);
	printf("%s", YLW_COLOR);
	printf("%d", philo->id);
	printf("%s", END_COLOR);
	printf(" %s", "is ");
	printf("%s", GREEN_COLOR);
	printf("sleeping\n");
	printf("%s", END_COLOR);
	pthread_mutex_unlock(&philo->info->write);
}

void	death_message(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->write);
	printf("[%lld] ", timestamp() - philo->info->start_time);
	printf("%s", RED_COLOR);
	printf("%d", philo->id);
	printf("%s", END_COLOR);
	printf(" %s", "is ");
	printf("%s", RED_COLOR);
	printf("dead\n");
	printf("%s", END_COLOR);
	pthread_mutex_unlock(&philo->info->write);
}
