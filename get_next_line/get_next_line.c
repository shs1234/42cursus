/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:35:50 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/24 00:59:09 by hoseoson         ###   ########.fr       */
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
	static char	buf[BUFFER_SIZE];
	t_list		*lst;
	static int	len;
	
	// 처음 함수 호출했을 경우.
	if (!line)
	{
		// EOF를 못만났을 경우.
		len = read(fd, buf, BUFFER_SIZE);
		if (len == BUFFER_SIZE)
		{
			line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
			if (!line)
				return (0);
			// 개행이 없을 경우.
			ft_strcpy(line, buf);
			len = ft_has_newline(line);
			if (len == BUFFER_SIZE)
				lst = ft_lstnew(line);
			else
			{
				line[len] = 0;
				return (line);
			}
		}
		else
		{
			line[len] = 0;
			return (line);
		}
	}
	// 두번째 이상 호출일 경우
	while (len == BUFFER_SIZE)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == BUFFER_SIZE) // EOF 아님.
		{
			line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
			if (!line)
				return (0);
			ft_strcpy(line, buf);
			ft_lstadd_back(&lst, ft_lstnew(line));
			len = ft_has_newline(line);
			if (len == BUFFER_SIZE)
				continue ;
			else
				return (ft_linejoin(lst));
		}
	}
}

int	main(int ac, char **av)
{
	int	fd;
	char *line;

	fd = open("test", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s", get_next_line(fd));
	}
}
