#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strndup(char *str, int n)  // strndup를 살짝 수정한 함수. n이 -1일 경우 strdup처럼 작동.
{
    int i;
    int len;
    char *ret;

    i = 0;
    if (n == -1) // n == -1, str 전체를 복사.
        len = ft_strlen(str);
    else
        len = n; // n != -1, str의 n까지만 복사.
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

int get_index(char *str) // 개행의 위치를 반환하는 함수. 개행이 없을 경우 -1 반환.
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

void ft_free(char **line) // free하고 주소값을 null로 바꿔주는 함수.
{
    free(*line);
    *line = 0;
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

char *divide(char **line, char **remain) // 개행을 기준으로 잘라 나눠주는 함수.
{
    char *front; // 개행 앞부분
    char *back; // 개행 뒷부분
    int i;

    front = 0;
    back = 0;
    i = get_index(*line); // 개행 위치의 인덱스
    front = ft_strndup(*line, i + 1); // 개행 위치까지 복사. 인덱스는 0부터라서 i + 1.
    if (!front)
    {
        ft_free(line);
        return (0);
    }
    if ((*line)[i + 1]) // 개행 뒷부분에 추가적인 문자가 남아있는지 확인.
    {
        back = ft_strndup(&(*line)[i + 1], -1); // 개행 뒷부분 문자열 전체 복사.
        if (!back)
        {   
            ft_free(&front);
            ft_free(line);
            return (0);
        }
    }
    ft_free(line); // 기존의 line은 free.
    *remain = back; // 뒷부분을 remain에 저장.
    return (front); // 앞부분을 반환
}

char *get_next_line(int fd)
{
    char *line;
    static char *remain;
    char buf[BUFFER_SIZE + 1];
    int len;
    char *temp;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    line = remain; // 이전 단계에서 남아있었던 remain을 line으로 옮기고, remain은 0으로 비워줌.
    remain = 0;
    if (line && get_index(line) >= 0) // 라인에 개행이 있을경우 나눠주고 바로 반환.
    {
        line = divide(&line, &remain);
        return (line);
    }
    while (1)
    {
        len = read(fd, buf, BUFFER_SIZE);
        if (len == 0) // 0일때 예외처리
            return (line);
        if (len == -1) // EOF를 만났을때 예외처리.
        {
            ft_free(&line);
            ft_free(&remain);
            return (line);
        }
        buf[len] = 0; // 버퍼 마지막을 0로 막아서 문자열 형태로 만들어줌.
        if (!line) // 만약 처음으로 호출된 gnl일 경우(line == NULL), 버퍼값 전체를 line으로 복사.
        {
            line = ft_strndup(buf, -1);
            if (!line)
            {
                ft_free(&remain);
                return (0);
            }
        }
        else // 두번째 부터 호출된 gnl일 경우(line에 문자열이 있는 상태), 새로 읽어온 buf값과 join
        {
            temp = line; // join하고 기존의 문자열은 free 시켜주기 위해 임시 포인터에 기존 문자열 저장.
            line = ft_strjoin(line, buf);
            if (!line)
            {
                ft_free(&temp);
                return (0);
            }
            ft_free(&temp);
        }
        if (get_index(line) >= 0) // line에 개행이 있을 경우 나눠주고 반환.
        {
            line = divide(&line, &remain);
            return (line);
        }
    }
    return (line);
}
