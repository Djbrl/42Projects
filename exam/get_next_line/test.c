#include <stdio.h>
#include <string.h>

char    *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (to_find[j] == str[i] || to_find[j] == '\0')
        {
            while (to_find[j] == str[i])
            {
                i++;
                j++;
            }
            if (to_find[j] == '\0')
                return (&str[i - j]);
            if (str[i] == '\0')
                return (0);
        }
        j = 0;
        i++;
    }
    return ((str[i] == '\0' && to_find[j] == '\0') ? &str[i] : 0);
}

int main()
{
    char a[] = "TesttesttestTesttesttestTesttesttestTesttesttestTesttesttestTesttesttestabTesttesttestTesttesttestTesttesttestTesttesttestTesttesttestTesttesttestTesttesttestTesttesttest";
    char b[] = "b";
    printf("[%s]\n", strstr(a, b));
    printf("[%s]", ft_strstr(a, b));
    return 0;
}
