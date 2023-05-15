/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:33:27 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/15 18:46:35 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rendering(t_vars *vars)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < vars->map_height)
	{
		x = 0;
		while (x < vars->map_width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
					vars->imgs[return_index("01CEP", vars->map[y][x])].img, x
					* IMG_SIZE, y * IMG_SIZE);
			x++;
		}
		y++;
	}
	return (0);
}

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
	vars->imgs[0].img = mlx_xpm_file_to_image(vars->mlx, "./imgs/empty.xpm",
			&vars->imgs[0].img_width, &vars->imgs[0].img_height);
	vars->imgs[1].img = mlx_xpm_file_to_image(vars->mlx, "./imgs/wall.xpm",
			&vars->imgs[1].img_width, &vars->imgs[1].img_height);
	vars->imgs[2].img = mlx_xpm_file_to_image(vars->mlx,
												"./imgs/collectible.xpm",
												&vars->imgs[2].img_width,
												&vars->imgs[2].img_height);
	vars->imgs[3].img = mlx_xpm_file_to_image(vars->mlx, "./imgs/exit.xpm",
			&vars->imgs[3].img_width, &vars->imgs[3].img_height);
	vars->imgs[4].img = mlx_xpm_file_to_image(vars->mlx, "./imgs/player.xpm",
			&vars->imgs[4].img_width, &vars->imgs[4].img_height);
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
