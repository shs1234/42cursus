/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:33:27 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/16 13:15:15 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key(int keycode, t_vars *vars)
{
	if (keycode == K_ESC)
		exit(0);
	if (keycode == K_AR_L)
		key_left(vars);
	else if (keycode == K_AR_R)
		key_right(vars);
	else if (keycode == K_AR_U)
		key_up(vars);
	else if (keycode == K_AR_D)
		key_down(vars);
	if (vars->exit == 1)
	{
		rendering(vars);
		sleep(1);
		exit(0);
	}
	return (0);
}

void	img_init(t_vars *vars)
{
	img_01(vars);
	img_c(vars);
	img_e(vars);
	img_p(vars);
	img_f(vars);
}

void	so_long(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map_width * IMG_SIZE,
			vars->map_height * IMG_SIZE, "so long");
	img_init(vars);
	mlx_loop_hook(vars->mlx, rendering, vars);
	mlx_hook(vars->win, 2, 1L << 0, key, vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
		error("no map");
	ft_bzero(&vars, sizeof(t_vars));
	if (make_map(av[1], &vars))
	{
		if (valid_map(&vars))
			so_long(&vars);
		else
			error("map error");
	}
	else
		error("map error");
	return (0);
}
