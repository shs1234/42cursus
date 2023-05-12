/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:33:27 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/13 08:55:32 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rendering(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map_height)
	{
		x = 0;
		while (x < vars->map_width)
		{
			if (vars->map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[0].img,
						x * IMG_SIZE, y * IMG_SIZE);
			else if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[1].img,
						x * IMG_SIZE, y * IMG_SIZE);
			else if (vars->map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[2].img,
						x * IMG_SIZE, y * IMG_SIZE);
			else if (vars->map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[3].img,
						x * IMG_SIZE, y * IMG_SIZE);
			else if (vars->map[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[4].img,
						x * IMG_SIZE, y * IMG_SIZE);
			x++;
		}
		y++;
	}
}

int	key(int keycode, t_vars *vars)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == K_AR_L)
		left(vars);
	else if (keycode == K_AR_R)
		right(vars);
	else if (keycode == K_AR_U)
		up(vars);
	else if (keycode == K_AR_D)
		down(vars);
	rendering(vars);
	ft_putnbr_fd(vars->move, 1);
	ft_putchar_fd('\n', 1);
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
	t_img	imgs[5];

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map_width * IMG_SIZE,
			vars->map_height * IMG_SIZE, "so long");
	img_init(vars);
	rendering(vars);
	mlx_key_hook(vars->win, key, vars);
	mlx_loop(vars->mlx);
	return ;
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
// 맵 읽기-------
// 맵 랜더링--------
// 움직일때마다 맵 변경 ---
// 맵 랜더링 ----

// 적 추가
// 캐릭터 모션
//