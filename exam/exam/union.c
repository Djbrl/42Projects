#include <unistd.h>

int not_print(int i, char *str, char c)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (str[j] == c)
			return (0);
		j++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		if (not_print(i, argv[1], argv[1][i]))
			write(1, &argv[1][i], 1);
		i++;
	}
	while (argv[2][j])
	{
		if (not_print(i, argv[1], argv[2][j]) && not_print(j, argv[2], argv[2][j]))
			write(1, &argv[2][j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
