/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 05:44:18 by dsy               #+#    #+#             */
/*   Updated: 2022/06/24 05:45:03 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <time.h>

void	*job(void *arg)
{
	// t_data *data = (t_data *)arg;
	// int value = (rand() % 6) + 1;
	// data->job_data = &value;
	// return ((void *)data->job_data);
	return(arg);
}

int		init_threads(t_data *data)
{
	int i = 0;
	while (i < N_PHILO)
	{
		if (pthread_create(&data->philos[i].t, NULL, &job, (void *)data) != 0)
			return (exit_err(PCREAT_ERR, data));
		i++;
	}
	return (1);
}

int		end_threads(t_data *data)
{
	int i = 0;
	while (i < N_PHILO)
	{
		if (pthread_join(data->philos[i].t, (void **)&data->job_data) != 0)
			return (exit_err(PJOIN_ERR, data));
		i++;
		printf("%p\n", data->job_data);
	}
	return (1);
}

int		init_mutexs(t_data *data)
{
	int i = 0;
	while (i < N_FORK)
	{
		if (pthread_mutex_init(&data->forks[i].m, NULL))
		 	return(exit_err(MUTEX_INIT, data));
		i++;
	}
	return (1);
}

int		end_mutexs(t_data *data)
{
	int i = 0;
	while (i < N_FORK)
	{
		if (pthread_mutex_destroy(&data->forks[i].m))
			return(exit_err(MUTEX_KILL, data));
		i++;
	}
	return (1);
}


int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	(void)ac;
	(void)av;
	init_struct(&data);
	init_threads(&data);
	init_mutexs(&data);
	end_threads(&data);
	end_mutexs(&data);
	destroy_struct(&data);
	// if (pthread_mutex_init(&data.forks.m, NULL))
	// 	return(exit_err(MUTEX_INIT));
	// if (pthread_mutex_destroy(&data.forks.m))
	// 	return(exit_err(MUTEX_KILL));
	return (0);
}
