/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:35:50 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/21 00:23:18 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_get_next_line_len(int fd)
{
	size_t	len;
	char	buf;

	len = 0;
	while(read(fd, &buf, 1))
	{
		if (buf == '\n')
			return (len);
		len++;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	char	*line;
	size_t	len;

	len = ft_get_next_line_len(fd);
	if (len)
	{
		line = (char *)malloc(sizeof(char) * len + 1);
		if (!line)
			return (0);
		
	}
	return (line);
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
