/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:58:41 by hoseoson          #+#    #+#             */
/*   Updated: 2023/02/02 10:49:52 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_read_map(char *filename, int len)
{
	int		fd;
	char	buf[1];
	char	*map;
	int		i;

	i = 0;
	map = (char *)malloc(sizeof(char) * len + 1);
	if (!map)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		while (read(fd, buf, 1))
			map[i++] = buf[0];
		map[i] = '\0';
	}
	close(fd);
	return (map);
}

int	ft_count_map_len(char *filename, t_map_data *map_data)
{
	int		fd;
	char	buf[1];
	int		len;

	map_data->lb = 0;
	len = 0;
	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		while (read(fd, buf, 1))
		{
			if (buf[0] == '\n')
				map_data->lb++;
			len++;
		}
	}
	close(fd);
	return (len);
}

int	ft_make_map(char *filename, char ***map, t_map_data *map_data)
{
	char	*data;
	int		len;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		len = ft_count_map_len(filename, map_data);
		data = ft_read_map(filename, len);
		if (data[len - 1] != '\n')
			return (0);
		*map = ft_split(data, "\n");
		return (1);
	}
	close(fd);
	return (0);
}

void	ft_argc_1(char **map, int **int_map, t_map_data *map_data)
{
	int		fd;
	char	buf[1];

	fd = open("argc1.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd > 0)
	{
		while (read(0, buf, 1))
			write(fd, buf, 1);
		close(fd);
	}
	if (ft_make_map("argc1.txt", &map, map_data))
	{
		if (ft_valid_map(map, map_data))
			ft_calc_map(map, int_map, *map_data);
		else
			write(1, "map error\n", 10);
	}
	else
		write(1, "map error\n", 10);
}
