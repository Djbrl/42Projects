/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:13:08 by dsy               #+#    #+#             */
/*   Updated: 2020/05/11 18:41:15 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		get_file_size(char *path)
{
	int		fd;
	int		file_size;
	char	tmp[1];

	file_size = 0;
	fd = open(path, O_RDONLY);
	if (fd > 0)
		while (read(fd, tmp, 1) > 0)
			file_size++;
	else
		return (-1);
	close(fd);
	return (file_size - 1);
}

char	*fetch_file(char *path)
{
	char	*file;
	int		fd;
	int		ret;
	int		n;

	if ((n = get_file_size(path)) < 0)
		return (0);
	if (!(file = (char*)malloc(sizeof(char) * (n + 1))))
	{
		free(file);
		return (0);
	}
	if ((fd = open(path, O_RDONLY)) < 0)
		return (0);
	if ((ret = read(fd, file, n)) < 0)
		return (0);
	return (file);
}

char	**rearrange_keys(char **f, int n)
{
	char	**s;
	int		i;

	if (!(s = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	i = 0;
	while (f[i])
	{
		if (i > 7)
			s[i] = ft_strdup(f[i]);
		else
		{
			f[i][0] == 'R' ? s[0] = ft_strdup(f[i]) : 0;
			f[i][0] == 'N' ? s[1] = ft_strdup(f[i]) : 0;
			f[i][0] == 'S' && f[i][1] == 'O' ? s[2] = ft_strdup(f[i]) : 0;
			f[i][0] == 'W' ? s[3] = ft_strdup(f[i]) : 0;
			f[i][0] == 'E' ? s[4] = ft_strdup(f[i]) : 0;
			f[i][0] == 'S' && f[i][1] == ' ' ? s[5] = ft_strdup(f[i]) : 0;
			f[i][0] == 'F' ? s[6] = ft_strdup(f[i]) : 0;
			f[i][0] == 'C' ? s[7] = ft_strdup(f[i]) : 0;
		}
		i++;
	}
	s[i] = 0;
	return (s);
}

char	**load_map_file(char *path, t_game *data)
{
	char	**parsed_file;
	char	**arranged_file;
	char	*file;
	int		file_size;
	int		i;

	i = 0;
	file_size = 0;
	if ((file = fetch_file(path)) == 0)
	{
		data->error = 0;
		return (NULL);
	}
	if ((parsed_file = ft_split(file, '\n')) == 0)
	{
		free_array(parsed_file);
		return (NULL);
	}
	while (parsed_file[file_size])
		file_size++;
	arranged_file = rearrange_keys(parsed_file, file_size);
	free(file);
	free_array(parsed_file);
	return (arranged_file);
}
