#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>
#include "get_next_line.h"
#include "libft/libft.h"

int main()
{
	char *file = "test";
//	printf("%zi\n", read(open(file, O_RDONLY), file, 0));
//	printf("%s", file);
	int i = 0;
	int fd = open(file, O_RDONLY);
    static char *line_buffer;
    static char *line;
	
	printf("current fd : %i\n", fd);
    printf("ret gnl %i\n", get_next_line(fd, &line));	
	printf("ln buf %s\n", line_buffer);
	printf("ln \n%s\n", line);
	get_next_line(0, &line);
	printf("ln \n%s\n", line);
	free(line_buffer);
	free(line);
   //	check_line_stack(&stack, &line);
//    get_next_line(open("test", O_RDONLY), line);
}
