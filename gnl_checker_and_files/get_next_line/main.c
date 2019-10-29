#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>

#include "get_next_line.h"

int main()
{
	int i = 0;
	char *file = "test";
	int fd = open(file, O_RDONLY);
    static char *line_buffer;
    line_buffer	= malloc(50);
    static char *line;
    line = malloc(100);
    printf("ret check %i\n", check_line_buffer(&line_buffer, &line));	
	printf("ret read %i\n", gnl_read(fd, file, &line_buffer, &line));
	printf("ln buf %s\n", line_buffer);
	printf("ln \n%s\n", line);

	free(line_buffer);
	free(line);
   //	check_line_stack(&stack, &line);
//    get_next_line(open("test", O_RDONLY), line);
}
