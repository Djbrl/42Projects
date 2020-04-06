#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"
/*
int             get_file_size(char *path)
{
	int             fd;
	int             file_size;
	char    tmp[1];

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

char    *fetch_file(char *path)
{
	char    *file;
	int             fd;
	int             ret;
	int             n;

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
*/

void shell_loop(void)
{
	char *line;
	char **args;
	int status;
	char buffer[4096];
	while (1)
	{
		read(0, buffer, 4096);
		printf("%s", buffer);
		if (ft_strcmp(buffer, "exit"))
			return ;
	}
	//must read standard input
	//split what received
	//execute the command
	//free stuff and update status/succes/failure
}

int main(int ac, char **av)
{
	int done;

	done = 0;

	shell_loop();
	return (0);
}

