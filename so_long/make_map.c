/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:52:24 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/08 06:10:54 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	map_len(char *filename)
{
	int		fd;
	char	buf;
	size_t	len;
	size_t	max_len;

	max_len = MAX_HEIGHT * MAX_WIDTH;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error("Error\nopen");
	len = 0;
	while (read(fd, &buf, 1))
	{
		len++;
		if (len > max_len)
			error("Error\nmap is big");
	}
	close(fd);
	if (len == 0)
		error("Error\nempty map");
	return (len);
}

int	make_map(char *filename, t_vars *vars)
{
	int		fd;
	char	buf;
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (map_len(filename) + 1));
	if (!str)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error("Error\nopen");
	i = 0;
	while (read(fd, &buf, 1))
		str[i++] = buf;
	str[i] = '\0';
	close(fd);
	free(str);
	vars->map = ft_split(str, '\n');
	if (!vars->map[0])
		error("Error\nempty map");
	return (1);
}
