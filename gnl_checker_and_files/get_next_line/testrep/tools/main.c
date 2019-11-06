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
 
	
//	r = get_next_line(42, &line);

//	printf("%d\n",r);
    
	while (i < 3)
	{
		printf("\n================================\nretour de la fonction\n===========================\n\nretour de gnl : %i\n", get_next_line(fd, &line));	
		printf("valeur de line : \n\"%s\"\n", line);
		i++;
	}
	free(line_buffer);
	free(line);
   //	check_line_stack(&stack, &line);
//    get_next_line(open("test", O_RDONLY), line);
}
