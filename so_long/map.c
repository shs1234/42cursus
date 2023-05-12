/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:52:24 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/13 05:32:18 by hoseoson         ###   ########.fr       */
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

int	make_map(char *filename, t_vars *vars)
{
	int		fd;
	int		i;
	char	*new_line;

	vars->map_height = line_count(filename);
	vars->map = malloc(sizeof(char *) * (vars->map_height + 1));
	if (!vars->map)
		return (0);
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		while (i < vars->map_height)
		{
			vars->map[i] = get_next_line(fd);
			new_line = ft_strchr(vars->map[i++], '\n');
			if (new_line)
				*new_line = '\0';
		}
		vars->map[i] = NULL;
	}
	else
		error("fd");
	close(fd);
	return (1);
}

int	components(int y, int x, char *cep1, t_vars *vars)
{
	if (y == 0 || y == vars->map_height - 1 ||
		x == 0 || x == vars->map_width - 1)
	{
		if (vars->map[y][x] != '1')
			cep1[3] = 1;
	}
	else
	{
		if (vars->map[y][x] == 'C')
			cep1[0]++;
		else if (vars->map[y][x] == 'E')
			cep1[1]++;
		else if (vars->map[y][x] == 'P')
		{
			vars->player_x = x;
			vars->player_y = y;
			cep1[2]++;
		}
	}
	return (1);
}

int	valid_map(t_vars *vars)
{
	int		y;
	int		x;
	char	cep1[4];

	ft_bzero(cep1, 4);
	vars->map_width = ft_strlen(vars->map[0]);
	y = 0;
	while (y < vars->map_height)
	{
		if (ft_strlen(vars->map[y]) != vars->map_width)
			return (0);
		x = 0;
		while (x < vars->map_width)
		{
			components(y, x, cep1, vars);
			x++;
		}
		y++;
	}
	if (!(cep1[0] > 0 && cep1[1] == 1 && cep1[2] == 1 && cep1[3] == 0))
		return (0);
	vars->c_count = cep1[0];
	return (1);
}
// 경로 있는지 확인. DFS