/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:52:24 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/12 10:42:57 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	components(size_t y, size_t x, int *cep, t_vars *vars)
{
	if ((y == 0 || y == vars->map_height - 1 || x == 0 || x == vars->map_width
			- 1) && vars->map[y][x] != '1')
		error("Error\ninvalid map");
	else
	{
		if (vars->map[y][x] == 'C')
			cep[0]++;
		else if (vars->map[y][x] == 'E')
		{
			vars->exit_x = x;
			vars->exit_y = y;
			cep[1]++;
		}
		else if (vars->map[y][x] == 'P')
		{
			vars->player_x = x;
			vars->player_y = y;
			cep[2]++;
		}
		else if (vars->map[y][x] == '0' || vars->map[y][x] == '1'
			|| vars->map[y][x] == 'F')
			return ;
		else
			error("Error\ninvalid map");
	}
}

static void	dfs(char **map, int x, int y, int *ce)
{
	if (map[y][x] == '1' || *ce == 0)
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'E')
		(*ce)--;
	map[y][x] = '1';
	dfs(map, x + 1, y, ce);
	dfs(map, x - 1, y, ce);
	dfs(map, x, y + 1, ce);
	dfs(map, x, y - 1, ce);
}

static int	valid_path(t_vars *vars)
{
	char	**map_copy;
	int		ce;
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
	ce = vars->c_count + 1;
	dfs(map_copy, vars->player_x, vars->player_y, &ce);
	map_clear(map_copy);
	if (ce == 0)
		return (1);
	return (0);
}

int	valid_map(t_vars *vars)
{
	size_t	y;
	size_t	x;
	int		cep[3];

	ft_bzero(cep, sizeof(int) * 3);
	vars->map_width = ft_strlen(vars->map[0]);
	y = -1;
	while (vars->map[++y])
	{
		if (ft_strlen(vars->map[y]) != vars->map_width)
			error("Error\ninvalid map");
		x = -1;
		while (++x < vars->map_width)
			components(y, x, cep, vars);
	}
	vars->map_height = y;
	if (vars->map_height > MAX_HEIGHT || vars->map_width > MAX_WIDTH)
		error("Error\ninvalid map");
	vars->c_count = cep[0];
	if (!(cep[0] > 0 && cep[1] == 1 && cep[2] == 1))
		error("Error\ninvalid map");
	if (!valid_path(vars))
		error("Error\ninvalid map");
	return (1);
}
