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
# include <pthread.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define GREEN_COLOR "\033[0;32m"
# define YLW_COLOR "\033[0;33m"
# define RED_COLOR "\033[0;31m"
# define END_COLOR "\033[0m"
# define PCREAT_ERR "Error : Failed to create thread.\n"
# define PJOIN_ERR "Error : Failed to terminate thread.\n"

/*
STRUCTURES
*/

typedef struct s_philo
{
	pthread_t	t;
	int			timer;
}				t_philo;

typedef struct s_fork
{
	pthread_mutex_t	m;
	int				status;
}					t_fork;

typedef struct s_data
{
	t_philo			philos;
	t_fork			forks;
	void			*job_data;
	void			*job_res;
}					t_data;

/*
UTILS
*/

int	exit_err(char *err);

#endif
