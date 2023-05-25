/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:33:27 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/23 21:36:57 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	key(int keycode, t_vars *vars)
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
		exit(0);
	return (0);
}

static void	img_init(t_vars *vars)
{
	img_01(vars);
	img_c(vars);
	img_e(vars);
	img_p(vars);
	img_f(vars);
}

static void	so_long(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map_width * IMG_SIZE,
			vars->map_height * IMG_SIZE, "so long");
	img_init(vars);
	mlx_loop_hook(vars->mlx, rendering, vars);
	mlx_hook(vars->win, 17, 0, ft_close, 0);
	mlx_hook(vars->win, 2, 0, key, vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
		error("Error\nac != 2");
	ft_bzero(&vars, sizeof(t_vars));
	if (make_map(av[1], &vars))
	{
		if (valid_map(&vars))
			so_long(&vars);
		else
			error("Error\n");
	}
	else
		error("Error\n");
	return (0);
}
