/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:35:50 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/25 11:38:05 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_has_newline(char *line)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*sub;
	int		i;

	if (!s)
		return (0);
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (0);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}


char	*ft_strtrim(char const *s1, int end)
{
	int	start;

	if (!s1)
		return (0);
	start = 0;
	while (s1[start]!='\n')
		start++;
	while (end > 0 && '\n' != s1[end - 1])
		end--;
	if (start == end - 1)
		return (ft_substr(s1, 0, end));
	return (ft_substr(s1, start + 1, end - start));
}


char *ft_linejoin(t_list *lst)
{
	char *join;
	int last;
	int len;
	char *trim;

	join = (char *)malloc(sizeof(char) * ft_lstsize(lst) * BUFFER_SIZE + 1);
	if (!join)
		return (0);
	len = 0;
	last = 0;
	while (lst)
	{
		if (!lst->next)
			last = 1;
		ft_strlcat(join, lst->content, last, &len);
		lst = lst->next;
	}
	trim = ft_strtrim(join, len);
	return (trim);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		buf[BUFFER_SIZE];
	t_list		*lst;
	int			len;
	char		*join;

	lst = 0;
	if (line)
		ft_lstadd_back(&lst, ft_lstnew(line));
	while (1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == 0)
			return (0);
		line = (char *)malloc(sizeof(char) * len);
		if (!line)
			return (0);
		ft_strcpy(line, buf, len);
		ft_lstadd_back(&lst, ft_lstnew(line));
		if (ft_has_newline(line) > 0)
			break;
	}
	join = ft_linejoin(lst);
	return (join);
}

int	main()
{
	int	fd;
	char *line;
	int i;

	i = 0;
	fd = open("test", O_RDONLY);
	while (i < 9)
	{
		line = get_next_line(fd);
		printf(">>>>>%d : %s\n", i + 1, line);
		i++;
	}
}
