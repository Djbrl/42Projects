/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:13:08 by dsy               #+#    #+#             */
/*   Updated: 2020/02/22 16:07:50 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	if (!(file = (char*)malloc(sizeof(char) * n)))
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

char	**rearrange_keys(char **parsed_file, int n)
{
	char **lines;
	int i;

	if (!(lines = (char**)malloc(sizeof(char*) * n)))
		return (NULL);
	i = 0;
	while (parsed_file[i])
	{
		if (parsed_file[i][0] == 'R')
			lines[0] = ft_strdup(parsed_file[i]);
		if (parsed_file[i][0] == 'N')
			lines[1] = ft_strdup(parsed_file[i]);
		if (parsed_file[i][0] == 'S' && parsed_file[i][1] == 'O')
		{
			lines[2] = ft_strdup(parsed_file[i]);
			//printf("we in\n%s\n%s\n", lines[2], parsed_file[i]);
		}
		if (parsed_file[i][0] == 'W')
			lines[3] = ft_strdup(parsed_file[i]);
		if (parsed_file[i][0] == 'E')
			lines[4] = ft_strdup(parsed_file[i]);
		if (parsed_file[i][0] == 'S' && parsed_file[i][1] == ' ')
			lines[5] = ft_strdup(parsed_file[i]);
		if (parsed_file[i][0] == 'F')
			lines[6] = ft_strdup(parsed_file[i]);
		if (parsed_file[i][0] == 'C')
			lines[7] = ft_strdup(parsed_file[i]);
		if (i > 7)
			lines[i] = ft_strdup(parsed_file[i]);
		i++;
	}
	lines[i] = 0;
	//printf("i val : %i\n", i);
	i = 0;
	//printf("check line 3 : %s\n", lines[2]);
	while (lines[i])
	{
		printf("\x1b[32mlines : %s\x1b[0m\n", lines[i]);
		i++;
	}
	i = 0;
	//while (parsed_file[i])
		//printf("messy file : %s\n", parsed_file[i++]);
//	free_array(parsed_file);
	return (lines);
}

char	**load_map_file(char *path)
{
	char	**parsed_file;
	char	*file;
	int		file_size;
	int		i;

	i = 0;
	file_size = 0;
	if ((file = fetch_file(path)) == 0)
	{
		write(1, "Error\n[Path]Couldn't find map file.\n", 36);
		return (NULL);
	}
	if ((parsed_file = ft_split(file, '\n')) == 0)
	{
		free_array(parsed_file);
		return (NULL);
	}
	while (parsed_file[file_size])
		file_size++;
	rearrange_keys(parsed_file, file_size);
	free(file);
	return (parsed_file);
}
