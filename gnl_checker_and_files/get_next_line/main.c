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

	char *stack = "this is a test lol\nanother test lel\n";
	char *line;
	check_line_stack(&stack, &line);
//	get_next_line(open("test", O_RDONLY), line);
}
