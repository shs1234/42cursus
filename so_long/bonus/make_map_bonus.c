/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 05:42:31 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/09 09:03:21 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			error("Error\ninvalid map");
	}
	close(fd);
	if (len == 0)
		error("Error\ninvalid map");
	return (len);
}

static int	valid_line(char *str, char **map)
{
	int	ln;
	int	line_count;

	ln = 0;
	line_count = 0;
	if (*str == '\n')
		return (0);
	while (*str)
	{
		if (*str == '\n')
		{
			if (*(str + 1) && *(str + 1) == '\n')
				return (0);
			ln++;
		}
		str++;
	}
	while (map[line_count])
		line_count++;
	if (!(ln == line_count || ln + 1 == line_count))
		return (0);
	return (1);
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
	vars->map = ft_split(str, '\n');
	if (!valid_line(str, vars->map))
		error("Error\ninvalid map");
	free(str);
	return (1);
}
