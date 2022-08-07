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
	data->start_time = timestamp();
	data->death_status = 0;
	data->philos = NULL;
	data->forks = NULL;
	data->all_ate = 0;
	data->philos = malloc(sizeof(t_philo) * (data->nb_philo + 1));
	if (!data->philos)
		exit_err(MALLOC_ERR, data);
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->nb_fork + 1));
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
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == 32 || str[i] == 10 || str[i] == 9 || str[i] == 12
		|| str[i] == 13 || str[i] == 11)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (res * neg);
		else
			res = (res * 10) + (long)(str[i] - '0');
		i++;
	}
	return (res * neg);
}
