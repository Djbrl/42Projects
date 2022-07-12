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

void	*job(void *arg)
{
	printf("Thread is running\n");
	return (arg);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	(void)ac;
	(void)av;
	init_struct(&data);
	while (i < N_PHILO)
	{
		if (pthread_create(&data.philos[i].t, NULL, &job, NULL) != 0)
			return (exit_err(PCREAT_ERR, &data));
		if (pthread_join(data.philos[i].t, &data.job_res) != 0)
			return (exit_err(PJOIN_ERR, &data));
		i++;
	}
	destroy_struct(&data);
	// if (pthread_mutex_init(&data.forks.m, NULL))
	// 	return(exit_err(MUTEX_INIT));
	// if (pthread_create(&data.philos.t, NULL, &job, NULL) != 0)
	// 	return (exit_err(PCREAT_ERR));
	// if (pthread_join(data.philos.t, &data.job_res) != 0)
	// 	return (exit_err(PJOIN_ERR));
	// if (pthread_mutex_destroy(&data.forks.m))
	// 	return(exit_err(MUTEX_KILL));
	return (0);
}
