/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:33:27 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/12 10:03:42 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key(int keycode, t_vars *vars)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == K_AR_L)
		;
	else if (keycode == K_AR_R)
		;
	else if (keycode == K_AR_U)
		;
	else if (keycode == K_AR_D)
		;
	return (0);
}

void	so_long(t_map *map_data)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "so long");
	mlx_key_hook(vars.win, key, &vars);
	mlx_loop(vars.mlx);
	return ;
}

int	main(int ac, char **av)
{
	t_map	map_data;

	if (ac != 2)
		error("no map");
	if (make_map(av[1], &map_data))
	{
		if (valid_map(&map_data))
			so_long(&map_data);
		else
			error("map error");
	}
	else
		error("map error");
	return (0);
}
// 맵 읽기-------
// 맵 랜더링
// 움직일때마다 맵 변경
// 맵 랜더링