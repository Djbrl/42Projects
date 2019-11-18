/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:40:40 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/25 15:51:19 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		ret = 1;
	int 	i;

	if (ac == 2)
	{
		i = 1;
		fd = open(av[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("Line %d file 1 : %s\n", i, line);
			free(line);
		}
		i++;
		close(fd);
	}
	system("leaks a.out");
	return (0);
}
