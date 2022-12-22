#include "include/minishell.h"


size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)src;
	if (!dst)
		return (0);
	while (str[i] && i + 1 < size)
	{
		dst[i] = str[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	while (str[i])
		i++;
	return (i);
}

int	ft_issep(char c, const char *charset)
{
	size_t	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	nb_wrds(const char *s, const char *set, int *i, int *j)
{
	int	k;
	int	n;

	k = 0;
	n = 0;
	*i = -1;
	*j = 0;
	while (s[k])
	{
		while (s[k] && ft_issep(s[k], set))
			k++;
		if (s[k] && !ft_issep(s[k], set))
			n++;
		while (s[k] && !ft_issep(s[k], set))
			k++;
	}
	return (n);
}

static int	wrd_len(const char *s, const char *set)
{
	int	i;

	i = 0;
	while (s[i] && !ft_issep(s[i], set))
		i++;
	return (i);
}

static char	**ft_free(char **strs, int i)
{
	int		j;

	j = -1;
	while (++j < i)
		free(strs[j]);
	free(strs);
	return (NULL);
}

char	**ft_splitt(const char *s, const char *set)
{
	char	**strs;
	int		wrds;
	int		i;
	int		j;
	int		len;

	if (!s || !set)
		return (NULL);
	wrds = nb_wrds(s, set, &i, &j);
	strs = malloc((wrds + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs[wrds] = 0;
	while (++i < wrds)
	{
		while (s[j] && ft_issep(s[j], set))
			j++;
		len = wrd_len(s + j, set);
		strs[i] = malloc((len + 1) * sizeof(char));
		if (!(strs[i]))
			return (ft_free(strs, i));
		(void)ft_strlcpy(strs[i], s + j, len + 1);
		j += len;
	}
	return (strs);
}
void	free_split(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}

int main()
{
	int j = 0;
	int i = 0;
	int r_redir = 0;
	char *str = "ls -laR | wc > result.txt | cat result.txt > lol | ls -la";
	char **res = ft_splitt(str, " ");
	while (res[i])
	{
		if (res[i][0] == '|' || res[i][0] == '>')
			j++;
		printf("%s\n", res[i++]);
	}
	printf("num of pipes and redirs : %i\nexpr : %i\n", j, j + 1);
	i = 0;
	j = 0;
	free_split(res);
	while (res[j])
	{
		if (res[j][0] == '|')
			printf("%s\t", "next");
		if (res[j][0] == '>')
		{
			int fd = open(res[j + 1], O_RDWR | O_CREAT, 0644);
			if (fd == -1)
				perror("open");
			printf("[%i->%i %s]\t",0 , fd, res[j+1]);
			write(fd, "hello", 4);
			close(fd);
		}
		j++;
	}
	
	return (0);
}
