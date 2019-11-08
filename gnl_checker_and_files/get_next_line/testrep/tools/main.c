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
//	int r;
//	printf("%zi\n", read(open(file, O_RDONLY), file, 0));
//	printf("%s", file);
	int fd;
	int i = 0;
   if (!(fd = open(file, O_RDONLY)))
	   printf("error\n");
    static char *line_buffer;
    static char *line;
	int p = 1;
//	r = get_next_line(42, &line);

//	printf("%d\n",r);
    
		while (p > 0)
	{
		p = get_next_line(fd, &line);
		printf("retour de gnl : %i\n", get_next_line(fd, &line));	
		printf("valeur de line : \"\x1b[32m%s\x1b[0m\"\n", line);
		printf("\n===========================================================\n");	
		i++;
	}
	free(line_buffer);
	free(line);
//	while (1);
   //	check_line_stack(&stack, &line);
//    get_next_line(open("test", O_RDONLY), line);
}
