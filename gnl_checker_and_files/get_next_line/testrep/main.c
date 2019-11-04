#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>
#include "get_next_line.h"

int main()
{
	char *file = "test";
//	printf("%zi\n", read(open(file, O_RDONLY), file, 0));
//	printf("%s", file);
	int fd;
   if (!(fd = open(file, O_RDONLY)))
	   printf("error\n");
    static char *line_buffer;
    static char *line;
 
	write(1, "a",1);
	printf("current fd : %i\n", fd);
    printf("ret gnl %i\n", get_next_line(fd, &line));	
	printf("%s\n", line);
    printf("ret gnl %i\n", get_next_line(fd, &line));	
	printf("%s\n", line);
    printf("ret gnl %i\n", get_next_line(fd, &line));	
	printf("%s\n", line);
    printf("ret gnl %i\n", get_next_line(fd, &line));	
	printf("%s\n", line);
    printf("ret gnl %i\n", get_next_line(fd, &line));	
	printf("%s\n", line);
    printf("ret gnl %i\n", get_next_line(fd, &line));	
	printf("%s\n", line);
    printf("ret gnl %i\n", get_next_line(fd, &line));	
	printf("%s\n", line);
    printf("ret gnl %i\n", get_next_line(fd, &line));	
	printf("%s\n", line);
    printf("ret gnl %i\n", get_next_line(fd, &line));	
	printf("%s\n", line);
    printf("ret gnl %i\n", get_next_line(fd, &line));	
	printf("%s\n", line);
    printf("ret gnl %i\n", get_next_line(fd, &line));	
	printf("%s\n", line);
    printf("ret gnl %i\n", get_next_line(fd, &line));	
	printf("%s\n", line);
    printf("ret gnl %i\n", get_next_line(fd, &line));	
	printf("%s\n", line);
    printf("ret gnl %i\n", get_next_line(fd, &line));	
	printf("%s\n", line);
	free(line_buffer);
	free(line);
   //	check_line_stack(&stack, &line);
//    get_next_line(open("test", O_RDONLY), line);
}
