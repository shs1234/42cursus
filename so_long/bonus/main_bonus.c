/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:33:27 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/12 10:27:07 by hoseoson         ###   ########.fr       */
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
	mlx_hook(vars->win, 17, 0, close_win, 0);
	mlx_hook(vars->win, 2, 0, key, vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	char	*extension;

	if (ac != 2)
		error("Error\nac != 2");
	extension = ft_strrchr(av[1], '.');
	if (!extension || ft_strncmp(extension, ".ber", 4) || extension[4])
		error("Error\n.ber file only");
	ft_bzero(&vars, sizeof(t_vars));
	if (make_map(av[1], &vars) && valid_map(&vars) && enemy_init(&vars))
		so_long(&vars);
	else
		error("Error");
	return (0);
}
