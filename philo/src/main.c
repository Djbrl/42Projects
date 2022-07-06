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
	pthread_t	t1;
	void		*job_arg;
	void		*job_ret;
	int			status;

	(void)ac;
	(void)av;
	status = 0;
	job_arg = NULL;
	job_ret = NULL;
	if (pthread_create(&t1, NULL, &job, job_arg) != 0)
		return (exit_err(PCREAT_ERR));
	if (pthread_join(t1, &job_ret) != 0)
		return (exit_err(PJOIN_ERR));
	return (0);
}
