/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:09:46 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/12 10:16:10 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	enemy_u(int *loc, t_vars *vars)
{
	if (vars->map[loc[1] - 1][loc[0]] == '0')
	{
		vars->map[loc[1]][loc[0]] = '0';
		loc[1]--;
		vars->map[loc[1]][loc[0]] = 'F';
	}
	else if (vars->map[loc[1] - 1][loc[0]] == 'P')
		exit(0);
}

static void	enemy_d(int *loc, t_vars *vars)
{
	if (vars->map[loc[1] + 1][loc[0]] == '0')
	{
		vars->map[loc[1]][loc[0]] = '0';
		loc[1]++;
		vars->map[loc[1]][loc[0]] = 'F';
	}
	else if (vars->map[loc[1] + 1][loc[0]] == 'P')
		exit(0);
}

static void	enemy_r(int *loc, t_vars *vars)
{
	if (vars->map[loc[1]][loc[0] + 1] == '0')
	{
		vars->map[loc[1]][loc[0]] = '0';
		loc[0]++;
		vars->map[loc[1]][loc[0]] = 'F';
	}
	else if (vars->map[loc[1]][loc[0] + 1] == 'P')
		exit(0);
}

static void	enemy_l(int *loc, t_vars *vars)
{
	if (vars->map[loc[1]][loc[0] - 1] == '0')
	{
		vars->map[loc[1]][loc[0]] = '0';
		loc[0]--;
		vars->map[loc[1]][loc[0]] = 'F';
	}
	else if (vars->map[loc[1]][loc[0] - 1] == 'P')
		exit(0);
}

void	patrol(t_vars *vars)
{
	int	i;
	int	direction;

	i = 0;
	while (i < vars->f_count)
	{
		direction = rand() % 4;
		if (direction == UP)
			enemy_u(vars->enemy[i], vars);
		else if (direction == DOWN)
			enemy_d(vars->enemy[i], vars);
		else if (direction == RIGHT)
			enemy_r(vars->enemy[i], vars);
		else if (direction == LEFT)
			enemy_l(vars->enemy[i], vars);
		i++;
	}
}
