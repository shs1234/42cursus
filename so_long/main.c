/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:33:27 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/08 13:42:45 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	rendering(t_vars *vars)
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
	if (make_map(av[1], &vars) && valid_map(&vars))
		so_long(&vars);
	else
		error("Error");
	return (0);
}
