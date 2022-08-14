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

static int	is_num(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	input_parsing(char **av, t_data *data)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!is_num(av[i]))
			return (0);
		i++;
	}
	data->nb_meals = 0;
	data->nb_philo = ft_atoi(av[1]);
	data->nb_fork = data->nb_philo;
	data->death_time = ft_atoi(av[2]);
	data->sleep_time = ft_atoi(av[3]) * 1000;
	data->eat_time = ft_atoi(av[4]) * 1000;
	if (av[5])
		data->nb_meals = ft_atoi(av[5]);
	return (1);
}

void		smart_sleep(long long time, t_data *data)
{
	long long i;

	i = timestamp();
	pthread_mutex_lock(&data->death);
	while (!(data->death_status))
	{
		if ((timestamp() - i) >= time)
		{	
			pthread_mutex_unlock(&data->death);
			break ;
		}
		usleep(50);
	}
	pthread_mutex_unlock(&data->death);
}


int	dinner(t_philo *philo)
{
	t_data	*data;
	int		ret;

	data = philo->info;	
	pthread_mutex_lock(&data->forks[philo->fourchette]);
	ret = fork_message(philo, "has taken a fork");
	if (ret)
	{
		pthread_mutex_unlock(&data->forks[philo->fourchette]);
		return (1);
	}
	if (philo->couteau < data->nb_fork)
		pthread_mutex_lock(&data->forks[philo->couteau]);
	ret = fork_message(philo, "has taken a fork");
	if (ret)
	{
		pthread_mutex_unlock(&data->forks[philo->fourchette]);
		pthread_mutex_unlock(&data->forks[philo->couteau]);
		return (1);
	}
	pthread_mutex_lock(&data->read);
	ret = eat_message(philo);
	if (ret)
	{
		pthread_mutex_unlock(&data->forks[philo->fourchette]);
		pthread_mutex_unlock(&data->forks[philo->couteau]);
		pthread_mutex_unlock(&data->read);
		return (1);
	}
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&data->read);
	usleep(data->eat_time);
	//smart_sleep(data->eat_time, data);
	philo->meal_done++;
	pthread_mutex_unlock(&data->forks[philo->fourchette]);
	if (philo->couteau < data->nb_fork)
		pthread_mutex_unlock(&data->forks[philo->couteau]);
	return (0);
}

void	*job(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	philo = (t_philo *)arg;
	data = philo->info;
	if (philo->id % 2 == 0)
		usleep(10000);
	while (1)
	{
		if ((i == data->nb_meals && data->nb_meals != 0))
			break ;
		// pthread_mutex_lock(&data->death);
		// if (data->death_status){
		// 	pthread_mutex_unlock(&data->death);
		// 	break;
		// }
		// pthread_mutex_unlock(&data->death);
		ret = dinner(philo);
		if (ret)
			break;
		// pthread_mutex_lock(&data->death);
		// if (data->death_status){
		// 	pthread_mutex_unlock(&data->death);
		// 	break;
		// }
		// pthread_mutex_unlock(&data->death);
		ret = sleep_message(philo);
		if (ret)
			break;
		usleep(data->eat_time);
		// smart_sleep(data->sleep_time, data);
		// pthread_mutex_lock(&data->death);
		// if (data->death_status){
		// 	pthread_mutex_unlock(&data->death);
		// 	break;
		// }
		// pthread_mutex_unlock(&data->death);
		ret = think_message(philo);
		if (ret)
			break;
		i++;
	}
	return ((void *) NULL);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (exit_err(ARG_ERR, &data));
	if (!input_parsing(av, &data))
		return (exit_err(ARG_ERR, &data));
	init_struct(&data);
	init_mutexs(&data);
	init_threads(&data);
	int i = 0;
	while (i < data.nb_philo)
	{
		
		pthread_mutex_lock(&data.read);
		if (timestamp() - data.philos[i].last_meal > data.death_time)
		{
			death_message(&data.philos[i]);
			pthread_mutex_lock(&data.death);
			data.death_status = 1;
			pthread_mutex_unlock(&data.death);
			pthread_mutex_unlock(&data.read);
			break;
		}
		pthread_mutex_unlock(&data.read);
		i++;
		if (i == data.nb_philo)
			i = 0;
	}
	end_threads(&data);
	end_mutexs(&data);
	destroy_struct(&data);
	return (0);
}
