#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	int fd2;
    char *line;
	int ret = 1;
	int dpipe[2];
	int out = dup(1);
	pipe(dpipe);
	(void)ac;
	
	if (!(fd = open(av[1], O_RDONLY)))
		printf("main error\n");
	//Test normal
	printf("TEST NORMAL----------------------------------------------------------------\n");
	while ((ret = gnl(fd, &line)) > 0)
	{
//		free(line);
		printf("\n===========================================================\n");	
		printf("retour de gnl : %i\n", ret);	
		printf("valeur de line : \"\x1b[32m%s\x1b[0m\"\n", line);
	}
	printf("retour de gnl : %i\n", ret);	
	printf("valeur de line : \"\x1b[32m%s\x1b[0m\"\n", line);
	//Test 2 avec sortie standard
	printf("TEST STDIN----------------------------------------------------------------\n");
	fd = 1;
	dup2(dpipe[1], fd);
	write(fd, "test(01) of pipe input!\n", 24);
	write(fd, "i put this right after test 1\n", 31);
	close(dpipe[1]);
	dup2(out, fd);
	gnl(dpipe[0], &line);
	printf("string compare : %i\n", strcmp("test(01) of pipe input!", line));
	printf("valeur de line (pipe): \"\x1b[32m%s\x1b[0m\"\n", line);
	gnl(dpipe[0], &line);
	printf("string compare 2 : %i\n", strcmp("i put this right after test 1", line));
	printf("valeur de line (pipe): \"\x1b[32m%s\x1b[0m\"\n", line);
//	free(line);
	//Test Multi FD
	printf("TEST MULTIFD----------------------------------------------------------------\n");
	if (!(fd2 = open("secondfile", O_RDONLY)))
		printf("main error\n");
	ret = gnl(fd2, &line);
	printf("retour de gnl : %i\n", ret);	
	printf("valeur de line : \"\x1b[32m%s\x1b[0m\"\n", line);
	ret = gnl(fd2, &line);
	printf("valeur de line : \"\x1b[32m%s\x1b[0m\"\n", line);
	ret = gnl(fd, &line);
	printf("valeur de line : \"\x1b[32m%s\x1b[0m\"\n", line);
//	free(line);
	printf("TEST IN----------------------------------------------------------------\n");
	while (1)
	{
		gnl(0, &line);
		printf("valeur de line (in): \"\x1b[32m%s\x1b[0m\"\n", line);
	}
}
