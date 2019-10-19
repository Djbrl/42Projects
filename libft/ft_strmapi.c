#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	size_t	i;

	i = 0;
	map = NULL;
	if (s && f)
	{
		map = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
		while (i < ft_strlen((char *)s))
		{
			map[i] = f(i, s[i]);
			i++;
		}
	}
	return (map);
}
