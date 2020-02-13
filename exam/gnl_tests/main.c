#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main()
{
	int fd;
	char *line;
	int function;
	int nb = 0;

	fd = -1;
	//fd = open("empty_file.txt", O_RDONLY);
	//fd = open("one_line_file.txt", O_RDONLY);
	//fd = open("two_chars.txt", O_RDONLY);
	//fd = open("several_lines.txt", O_RDONLY);
	//fd = open("big_line.txt", O_RDONLY);
	//fd = 0;
	while ((function = get_next_line(fd, &line)) == 1)
	{
		nb++;
		printf("%d\n%s\n", function, line);
	}
	printf("%d\nnb_line = %d\n", function, nb);
	close(fd);
	return (0);
}
