#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void ft_free(char **str)
{
    free(*str);
    *str = 0;
}

int ft_getindex(const char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char *ft_strdup(char *str)
{
    char *ret;
    int len;
    int i;

    len = ft_strlen(str);
    ret = malloc(len + 1);
    if (!ret)
        return (0);
    i = 0;
    while (i < len)
    {
        ret[i] = str[i];
        i++;
    }
    ret[i] = 0;
    return (ret);
}

char *ft_strjoin(char *s1, char *s2)
{
    int s1_len;
    int s2_len;
    char *ret;
    int i;
    int j;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    ret = malloc(s1_len + s2_len + 1);
    if (!ret)
        return (0);
    i = 0;
    while (i < s1_len)
    {
        ret[i] = s1[i];
        i++;
    }
    j = 0;
    while (j < s2_len)
    {
        ret[i + j] = s2[j];
        j++;
    }
    ret[i+j] = 0;
    return (ret);
}
