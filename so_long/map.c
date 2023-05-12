/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:52:24 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/12 10:13:30 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	line_count(char *filename)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd > 0)
		while (get_next_line(fd))
			i++;
	else
		error("fd");
	close(fd);
	return (i);
}

int	make_map(char *filename, t_map *map_data)
{
	int		fd;
	int		i;
	char	*new_line;

	map_data->map_height = line_count(filename);
	map_data->map = malloc(sizeof(char *) * (map_data->map_height + 1));
	if (!map_data->map)
		return (0);
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		while (i < map_data->map_height)
		{
			map_data->map[i] = get_next_line(fd);
			new_line = ft_strchr(map_data->map[i++], '\n');
			if (new_line)
				*new_line = '\0';
		}
		map_data->map[i] = NULL;
	}
	else
		error("fd");
	close(fd);
	return (1);
}

int	components(int x, int y, char *cep1, t_map *map_data)
{
	if (x == 0 || x == map_data->map_height - 1 ||
		y == 0 || y == map_data->map_width - 1)
	{
		if (map_data->map[x][y] != '1')
			cep1[3] = 1;
	}
	else
	{
		if (map_data->map[x][y] == 'C')
			cep1[0]++;
		else if (map_data->map[x][y] == 'E')
			cep1[1]++;
		else if (map_data->map[x][y] == 'P')
			cep1[2]++;
	}
	return (1);
}
int	valid_map(t_map *map_data)
{
	int		x;
	int		y;
	char	cep1[4];

	ft_bzero(cep1, 4);
	map_data->map_width = ft_strlen(map_data->map[0]);
	x = 0;
	while (x < map_data->map_height)
	{
		if (ft_strlen(map_data->map[x]) != map_data->map_width)
			return (0);
		y = 0;
		while (y < map_data->map_width)
		{
			components(x, y, cep1, map_data);
			y++;
		}
		x++;
	}
	if (!(cep1[0] > 0 && cep1[1] == 1 && cep1[2] == 1 && cep1[3] == 0))
		return (0);
	return (1);
}
// 경로 있는지 확인. DFS