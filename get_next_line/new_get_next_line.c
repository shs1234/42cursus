#include "get_next_line.h"

int newline(char **ret, char **save)
{
    int i;

    i = ft_getindex(*ret);
    if (i >= 0)
    {
        if ((*ret)[i + 1])
        {
            *save = ft_strdup(&(*ret)[i + 1]);
            if (!(*save))
            {
                ft_free(ret);
                return (1);
            }
        }
        else
            *save = 0;
        (*ret)[i + 1] = 0;
        return (1);
    }
    *save = 0;
    return (0);
}

char *get_next_line(int fd)
{
    char *ret;
    static char *save;
    int len;
    char buf[BUFFER_SIZE + 1];
    char *tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
    
    ret = save;
    if (ret && newline(&ret, &save))
        return (ret);

    while(1)
    {
        len = read(fd, buf, BUFFER_SIZE);
        if (len == 0)
            break ;
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
                ft_free(&save);
                return (0);
            }
            free(tmp);
        }
        if (newline(&ret, &save))
            break ;
    }
    return (ret);
}