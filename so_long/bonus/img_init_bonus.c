/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:13:35 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/09 09:13:52 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_01(t_vars *vars)
{
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, "./bonus/imgs/wall.xpm",
			&vars->wall.img_width, &vars->wall.img_height);
	vars->empty.img = mlx_xpm_file_to_image(vars->mlx, "./bonus/imgs/empty.xpm",
			&vars->empty.img_width, &vars->empty.img_height);
}

void	img_c(t_vars *vars)
{
	vars->c[0].img = mlx_xpm_file_to_image(vars->mlx,
			"./bonus/imgs/c/collectible1.xpm", &vars->c[0].img_width,
			&vars->c[0].img_height);
	vars->c[1].img = mlx_xpm_file_to_image(vars->mlx,
			"./bonus/imgs/c/collectible2.xpm", &vars->c[1].img_width,
			&vars->c[1].img_height);
	vars->c[2].img = mlx_xpm_file_to_image(vars->mlx,
			"./bonus/imgs/c/collectible3.xpm", &vars->c[2].img_width,
			&vars->c[2].img_height);
}

void	img_e(t_vars *vars)
{
	vars->e[0].img = mlx_xpm_file_to_image(vars->mlx,
			"./bonus/imgs/e/exit1.xpm", &vars->e[0].img_width,
			&vars->e[0].img_height);
	vars->e[1].img = mlx_xpm_file_to_image(vars->mlx,
			"./bonus/imgs/e/exit2.xpm", &vars->e[1].img_width,
			&vars->e[1].img_height);
	vars->e[2].img = mlx_xpm_file_to_image(vars->mlx,
			"./bonus/imgs/e/exit3.xpm", &vars->e[2].img_width,
			&vars->e[2].img_height);
	vars->e[3].img = mlx_xpm_file_to_image(vars->mlx,
			"./bonus/imgs/e/exit4.xpm", &vars->e[3].img_width,
			&vars->e[3].img_height);
}

void	img_p(t_vars *vars)
{
	vars->p[0].img = mlx_xpm_file_to_image(vars->mlx,
			"./bonus/imgs/p/player1.xpm", &vars->p[0].img_width,
			&vars->p[0].img_height);
	vars->p[1].img = mlx_xpm_file_to_image(vars->mlx,
			"./bonus/imgs/p/player2.xpm", &vars->p[1].img_width,
			&vars->p[1].img_height);
	vars->p[2].img = mlx_xpm_file_to_image(vars->mlx,
			"./bonus/imgs/p/player3.xpm", &vars->p[2].img_width,
			&vars->p[2].img_height);
	vars->p[3].img = mlx_xpm_file_to_image(vars->mlx,
			"./bonus/imgs/p/player4.xpm", &vars->p[3].img_width,
			&vars->p[3].img_height);
}

void	img_f(t_vars *vars)
{
	vars->f[0].img = mlx_xpm_file_to_image(vars->mlx,
			"./bonus/imgs/f/fire1.xpm", &vars->f[0].img_width,
			&vars->f[0].img_height);
	vars->f[1].img = mlx_xpm_file_to_image(vars->mlx,
			"./bonus/imgs/f/fire2.xpm", &vars->f[1].img_width,
			&vars->f[1].img_height);
	vars->f[2].img = mlx_xpm_file_to_image(vars->mlx,
			"./bonus/imgs/f/fire3.xpm", &vars->f[2].img_width,
			&vars->f[2].img_height);
	vars->f[3].img = mlx_xpm_file_to_image(vars->mlx,
			"./bonus/imgs/f/fire4.xpm", &vars->f[3].img_width,
			&vars->f[3].img_height);
}
