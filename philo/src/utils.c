/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 04:32:57 by dsy               #+#    #+#             */
/*   Updated: 2022/07/06 04:33:01 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_data *data)
{
	data->philos = NULL;
	data->forks = NULL;
	data->philos = malloc(sizeof(t_philo) * (N_PHILO + 1));
	if (!data->philos)
		exit_err(MALLOC_ERR, data);
	data->forks = malloc(sizeof(pthread_mutex_t) * (N_FORK + 1));
	if (!data->forks)
		exit_err(MALLOC_ERR, data);
}

void	destroy_struct(t_data *data)
{
	if (data->philos != NULL)
		free(data->philos);
	if (data->forks != NULL)
		free(data->forks);
}

void	fork_message(t_philo *philo, char *msg, int id)
{
	pthread_mutex_lock(&philo->info->write);
	printf("[%lld] ", timestamp() - philo->info->start_time);
	printf("%s", YLW_COLOR);
	printf("Guest n.%d", philo->id);
	printf("%s", END_COLOR);
	printf(" %s\t", msg);
	printf("%s", YLW_COLOR);
	printf("n.%d.\n", id);
	printf("%s", END_COLOR);
	pthread_mutex_unlock(&philo->info->write);
}

void	eat_message(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->write);
	printf("[%lld] ", timestamp() - philo->info->start_time);
	printf("%s", YLW_COLOR);
	printf("Guest n.%d", philo->id);
	printf("%s", END_COLOR);
	printf(" %s", "is enjoying his ");
	printf("%s", GREEN_COLOR);
	printf("\tmeal.\n");
	printf("%s", END_COLOR);
	pthread_mutex_unlock(&philo->info->write);
}

void	sleep_message(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->write);
	printf("[%lld] ", timestamp() - philo->info->start_time);
	printf("%s", YLW_COLOR);
	printf("Guest n.%d", philo->id);
	printf("%s", END_COLOR);
	printf(" %s", "is enjoying his ");
	printf("%s", GREEN_COLOR);
	printf("\tnap.\n");
	printf("%s", END_COLOR);
	pthread_mutex_unlock(&philo->info->write);
}

void	death_message(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->write);
	printf("[%lld] ", timestamp() - philo->info->start_time);
	printf("%s", RED_COLOR);
	printf("Guest n.%d", philo->id);
	printf("%s", END_COLOR);
	printf(" %s", "is ");
	printf("%s", RED_COLOR);
	printf("\tdead.\n");
	printf("%s", END_COLOR);
	pthread_mutex_unlock(&philo->info->write);
}


int	exit_err(char *err, t_data *data)
{
	printf("%s", RED_COLOR);
	printf("%s", err);
	printf("%s", END_COLOR);
	destroy_struct(data);
	return (0);
}

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}
