/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:52:24 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/23 22:42:00 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	make_map(char *filename, t_vars *vars)
{
	int		fd;
	size_t	i;
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
		error("Error\nfd");
	close(fd);
	return (1);
}

static void	components(size_t y, size_t x, char *cep, t_vars *vars)
{
	if (y == 0 || y == vars->map_height - 1
		|| x == 0 || x == vars->map_width - 1)
	{
		if (vars->map[y][x] != '1')
			error("Error\nwall 1");
	}
	else
	{
		if (vars->map[y][x] == 'C')
			cep[0]++;
		else if (vars->map[y][x] == 'E')
			cep[1]++;
		else if (vars->map[y][x] == 'P')
		{
			vars->player_x = x;
			vars->player_y = y;
			cep[2]++;
		}
		else if (vars->map[y][x] == '0' || vars->map[y][x] == '1')
			return ;
		else
			error("Error\ninvalid component");
	}
}

static void	dfs(char **map, int x, int y, int *c_count)
{
	if (map[y][x] == '1' || *c_count == -1)
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'E')
		(*c_count)--;
	map[y][x] = '1';
	dfs(map, x + 1, y, c_count);
	dfs(map, x - 1, y, c_count);
	dfs(map, x, y + 1, c_count);
	dfs(map, x, y - 1, c_count);
}

int	valid_path(t_vars *vars)
{
	char	**map_copy;
	int		c_count;
	size_t	i;

	i = 0;
	map_copy = malloc(sizeof(char *) * (vars->map_height + 1));
	if (!map_copy)
		return (0);
	while (i < vars->map_height)
	{
		map_copy[i] = ft_strdup(vars->map[i]);
		if (map_copy[i] == NULL)
			return (0);
		i++;
	}
	map_copy[i] = 0;
	c_count = vars->c_count;
	dfs(map_copy, vars->player_x, vars->player_y, &c_count);
	map_clear(map_copy);
	if (c_count == -1)
		return (1);
	return (0);
}

int	valid_map(t_vars *vars)
{
	size_t	y;
	size_t	x;
	char	cep[3];

	ft_bzero(cep, 3);
	vars->map_width = ft_strlen(vars->map[0]);
	y = 0;
	while (y < vars->map_height)
	{
		if (ft_strlen(vars->map[y]) != vars->map_width)
			error("Error\nno rectangle");
		x = 0;
		while (x < vars->map_width)
		{
			components(y, x, cep, vars);
			x++;
		}
		y++;
	}
	vars->c_count = cep[0];
	if (map_error(cep, vars))
		return (0);
	return (1);
}
