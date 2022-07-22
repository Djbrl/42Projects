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
	// data->job_res = NULL;
	// data->job_data = NULL;
	data->philos = malloc(sizeof(t_philo) * (N_PHILO));
	if (!data->philos)
		exit_err(MALLOC_ERR, data);
	data->forks = malloc(sizeof(pthread_mutex_t) * (N_FORK));
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
