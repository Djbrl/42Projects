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

void	init_struct(t_data *philo)
{
	(void)philo;
}

void	*job(void *arg)
{
	printf("Thread is running\n");
	return (arg);
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	(void)av;
	init_struct(&data);
	pthread_mutex_init(&data.forks.m, NULL);
	if (pthread_create(&data.philos.t, NULL, &job, data.job_data) != 0)
		return (exit_err(PCREAT_ERR));
	if (pthread_join(data.philos.t, &data.job_res) != 0)
		return (exit_err(PJOIN_ERR));
	pthread_mutex_destroy(&data.forks.m);
	return (0);
}
