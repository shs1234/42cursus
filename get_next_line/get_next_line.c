/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:35:50 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/24 06:30:21 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_has_newline(char *buf)
{
	size_t	i;

	i = 0;
	while(i < BUFFER_SIZE)
	{
		if(buf[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
char *ft_linejoin(t_list *lst)
{
	char *line;

	line = (char *)malloc(sizeof(char) * ft_lstsize(lst) * BUFFER_SIZE + 1);
	if (!line)
		return (0);
	line[0] = 0;
	while (lst)
	{
		ft_strlcat(line, lst->content, BUFFER_SIZE + 1);
		lst = lst->next;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char *line;
	char	buf[BUFFER_SIZE];
	t_list	*lst;
	int len;
	char *ret;

	lst = ft_lstnew(0);
	if (!line)
	{
		len = read(fd, buf, BUFFER_SIZE);
		line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!line)
			return (0);
		ft_strcpy(line, buf);
		ft_lstadd_back(&lst, ft_lstnew(line));
	}
	while (len == BUFFER_SIZE)
	{
		len = read(fd, buf, BUFFER_SIZE);
		line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!line)
			return (0);
		ft_strcpy(line, buf);
		ft_lstadd_back(&lst, ft_lstnew(line));
	}
	ret = ft_linejoin(lst);
	printf("%s",ret);
	return (ret);
}

int	main()
{
	int	fd;
	char *line;
	int i;

	i = 0;
	fd = open("test", O_RDONLY);
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
}
