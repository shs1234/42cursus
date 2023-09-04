#include "get_next_line.h"

int get_index(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char *get_front(char *str, int len)
{
    char *ret;
    int i;

    ret = malloc(len + 2);
    if (!ret)
        return (0);
    i = 0;
    while (i < len + 1)
    {
        ret[i] = str[i];
        i++;
    }
    ret[i] = 0;
    return (ret);
}

void ft_free(char **str)
{
    free(*str);
    *str = 0;
}

char *ft_strdup(char *str)
{
    int i;
    int len;
    char *ret;

    i = 0;
    len = ft_strlen(str);
    ret = malloc(len + 1);
    if (!ret)
        return (0);
    while (i < len)
    {
        ret[i] = str[i];
        i++;
    }
    ret[i] = 0;
    return (ret);
}

char *divide(char **ret, char **save)
{
    char *front;
    char *back;
    int i;

    front = 0;
    back = 0;
    i = get_index(*ret);
    front = get_front(*ret, i);
    if (!front)
    {
        ft_free(ret);
        return (0);
    }
    if ((*ret)[i + 1])
    {
        back = ft_strdup(&(*ret)[i + 1]);
        if (!back)
        {   
            ft_free(&front);
            ft_free(ret);
            return (0);
        }
    }
    ft_free(ret);
    *save = back;
    return (front);
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
    j = 0;
    while (i < s1_len)
    {
        ret[i] = s1[i];
        i++;
    }
    while (j < s2_len)
    {
        ret[i + j] = s2[j];
        j++;
    }
    ret[i + j] = 0;
    return (ret);
}

char *get_next_line(int fd)
{
    char *ret;
    static char *save;
    char buf[BUFFER_SIZE + 1];
    int len;
    char *tmp;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    ret = save;
    save = 0;
    if (ret && get_index(ret) >= 0)
    {
        ret = divide(&ret, &save);
        return (ret);
    }
    len = 1;
    while (len)
    {
        len = read(fd, buf, BUFFER_SIZE);
        if (len == 0)
            return (ret);
        if (len == -1)
        {
            ft_free(&ret);
            ft_free(&save);
            return (0);
        }
        buf[len] = 0;
        if (!ret)
        {
            ret = ft_strdup(buf);
            if (!ret)
            {
                ft_free(&save);
                return (0);
            }
        }
        else
        {
            tmp = ret;
            ret = ft_strjoin(ret, buf);
            if (!ret)
            {
                ft_free(&tmp);
                return (0);
            }
            ft_free(&tmp);
        }
        if (get_index(ret) >= 0)
        {
            ret = divide(&ret, &save);
            return (ret);
        }
    }
    return (ret);
}
// #include <stdio.h>
// int main()
// {
//     int fd;
//     char *str;

//     fd = open("get_next_line.c", O_RDONLY);
//     // str = get_next_line(fd);
//     while (str = get_next_line(fd))
//     {
//         printf("%s", str);
//         free(str);
//         // str = get_next_line(fd);
//     }
//     return (0);
// }