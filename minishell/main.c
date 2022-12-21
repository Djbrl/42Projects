#include "libft/libft.h"


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
	strs = malloc((wrds + 1)*sizeof(char *));
	if (!strs)
		return (NULL);
	strs[wrds] = 0;
	while (++i < wrds)
	{
		while (s[j] && ft_issep(s[j], set))
			j++;
		len = wrd_len(s + j, set);
		strs[i] = malloc((len + 1)*sizeof(char));
		if (!(strs[i]))
			return (ft_free(strs, i));
		(void)ft_strlcpy(strs[i], s + j, len + 1);
		j += len;
	}
	return (strs);
}

int main()
{
	int j = 0;
	int i = 0;
	int r_redir = 0;
	char *str = "hi > bro > ski";
	while (str[i])
	{
		if (str[i] == '>')
			r_redir++;
	}
	char **res = ft_splitt("hi > bro > ski", "|>");
	while (res[i])
		printf("%s\n", res[i++]);

	return (0);
}
