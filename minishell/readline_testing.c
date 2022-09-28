#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
	char *s;

	while (1){
	s = readline("> ");
	printf("%s\n", s);
	if (s != NULL)
		add_history(s);
	free(s);
	}
	return (0);
}
// A4283163 up
// B4348699 down