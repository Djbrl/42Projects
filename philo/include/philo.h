/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:17:33 by dsy               #+#    #+#             */
/*   Updated: 2022/06/24 05:46:50 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define N_PHILO 2
# define N_FORK 2
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define GREEN_COLOR "\033[0;32m"
# define YLW_COLOR "\033[0;33m"
# define RED_COLOR "\033[0;31m"
# define END_COLOR "\033[0m"
# define MALLOC_ERR "Error : Failed to allocate memory.\n"
# define PCREAT_ERR "Error : Failed to create thread.\n"
# define PJOIN_ERR "Error : Failed to terminate thread.\n"
# define MUTEX_INIT "Error : Failed to init mutex.\n"
# define MUTEX_KILL "Error : Failed to destroy mutex.\n"

/*
STRUCTURES
*/

typedef struct s_philo
{
	int				id;
	int				meal_done;
	pthread_t		t;
	long long		last_meal;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	long long		start_time;
	int				dinner_status;
	int				death_status;
	int				nb_philo;
	int				nb_meals;
	int				meals_done;
	int				death_time;
	int				sleep_time;
	int				eat_time;
	t_philo			*philos;
	pthread_mutex_t write;
	pthread_mutex_t	meal_status;
	pthread_mutex_t	*forks;
}					t_data;

/*
UTILS
*/
void	*job(void *arg);
int		init_threads(t_data *data);
int		end_threads(t_data *data);
int		init_mutexs(t_data *data);
int		end_mutexs(t_data *data);
int		exit_err(char *err, t_data *data);
void	init_struct(t_data *data);
void	destroy_struct(t_data *data);
#endif
