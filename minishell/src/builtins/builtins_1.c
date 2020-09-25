#include "minishell.h"

void echo(char *s)
{
	int i;
	i = 0;

	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void echo_n(char *s)
{
	int i;
	i = 0;
	
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}