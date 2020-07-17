/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:49:26 by dsy               #+#    #+#             */
/*   Updated: 2020/02/21 16:46:52 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//count chars until \n or \0 in stack
//if there is \n, ret whats before it
//if not ret current stack
//read file up until BUFFSIZE
#define BUFFER_SIZE 64

int gnl_read(int fd, int ret, char **s)
{
	int i;
	char *tmp[BUFFER_SIZE + 1]

	i = 0;
	ret = read(fd, );
}

int	gnl(int fd, char **line)
{
	static char *stack;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!stack)
		if (!stack = malloc(1))
			return (-1);
	
}
int main()
{
	char *line;

	system("cat /etc/passwd > test");
	int fd = open("test", O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	while ((ret = gnl(fd, &line)))
	{
		printf("ret %i\n", ret);
	}
	return (0);
}
