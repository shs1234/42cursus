/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 05:32:08 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/07 08:10:05 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	enemy_count(t_vars *vars)
{
	size_t	x;
	size_t	y;

	vars->f_count = 0;
	y = 0;
	while (y < vars->map_height)
	{
		x = 0;
		while (x < vars->map_width)
		{
			if (vars->map[y][x] == 'F')
				vars->f_count++;
			x++;
		}
		y++;
	}
}

static void	enemy_loc(t_vars *vars)
{
	size_t	x;
	size_t	y;
	int		i;

	y = 0;
	i = 0;
	while (y < vars->map_height)
	{
		x = 0;
		while (x < vars->map_width)
		{
			if (vars->map[y][x] == 'F')
			{
				vars->enemy[i][0] = x;
				vars->enemy[i][1] = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

int	enemy_init(t_vars *vars)
{
	int	i;

	enemy_count(vars);
	vars->enemy = malloc(sizeof(int *) * vars->f_count);
	if (!vars->enemy)
		return (0);
	i = -1;
	while (++i < vars->f_count)
	{
		vars->enemy[i] = malloc(sizeof(int) * 2);
		if (!vars->enemy[i])
			return (0);
	}
	enemy_loc(vars);
	return (1);
}
