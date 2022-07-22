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
	t_data	*data;

	data = (t_data *)arg;
	// pthread_mutex_lock(&data->forks[1].m);
	// pthread_mutex_unlock(&data->forks[1].m);
	return ((void *) NULL);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	(void)ac;
	(void)av;
	init_struct(&data);
	init_mutexs(&data);
	init_threads(&data);
	end_threads(&data);
	end_mutexs(&data);
	destroy_struct(&data);
	return (0);
}
