#include "get_next_line.h"
#include <stdio.h>

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	size_t i;
	char *dup;
	
	i = 0;
	if (!(dup = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (0);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char *ft_strjoin(char *s1, char *s2)
{
	size_t i;
	size_t j;
	char *str;

	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_substr(char *str, int start, int size)
{
	int i;
	int j;
	char *string;

	i = start;
	j = 0;
	if (!(string = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (str[i] && j < size)
	{
		string[j] = str[i];
		i++;
		j++;
	}
	string[j] = '\0';
	return (string);
}

int is_line(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\n')
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *ft_create_line(char *str, char **line)
{
	int i;

	i = 0;
	if (str[i] == '\n' || str[i] == '\0')
		return (*line = ft_strdup(""));
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i--;
	return (*line = ft_substr(str, 0, i + 1));
}

int gnl_return(char **line, char **str, int ret)
{
	char *temp;

	if (ret > 0)
	{
		*line = ft_create_line(*str, line);
		temp = ft_strdup(*str);
		free(*str);
		*str = ft_substr(temp, is_line(temp) + 1, ft_strlen(temp) - is_line(temp));
		printf("is_line(temp) = %d, ft_strlen(temp) = %lu, str = -%s-\n", is_line(temp), ft_strlen(temp), *str);
		free(temp);
		return (1);
	}
	*line = ft_create_line(*str, line);
	*str = NULL;
	free(*str);
	return (0);
}

int get_next_line(char **line)
{
	int ret;
	static char *str;
	char *buf;
	char *temp;

	ret = 1;
	*line = NULL;
	free(*line);
	*line = NULL;
	if (!str)
	{
		if (!(buf = malloc(sizeof(char) * (300 + 1))))
			return (-1);
		if ((ret = read(0, buf, 300)) < 0)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		str = ft_strdup(buf);
		free(buf);
	}
	while (str && (is_line(str) == -1) && ret > 0)
	{
		if (!(buf = malloc(sizeof(char) * (300 + 1))))
            return (-1);
		if ((ret = read(0, buf, 300)) < 0)
		{
            free(buf);
			free(str);
            return (-1);
        }
		buf[ret] = '\0';
		temp = ft_strdup(str);
		free(str);
		str = ft_strjoin(temp, buf);
		free(temp);
		free(buf);
	}
	return (gnl_return(line, &str, ret));
}
