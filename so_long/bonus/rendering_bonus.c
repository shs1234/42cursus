/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:28:33 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/07 03:16:29 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_image(t_vars *vars, int x, int y, time_t now)
{
	if (vars->map[y][x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->empty.img, x
			* IMG_SIZE, y * IMG_SIZE);
	else if (vars->map[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.img, x
			* IMG_SIZE, y * IMG_SIZE);
	else if (vars->map[y][x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->c[now % 3].img, x
			* IMG_SIZE, y * IMG_SIZE);
	else if (vars->map[y][x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->e[now % 4].img, x
			* IMG_SIZE, y * IMG_SIZE);
	else if (vars->map[y][x] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p[now % 4].img, x
			* IMG_SIZE, y * IMG_SIZE);
	else if (vars->map[y][x] == 'F')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->f[now % 4].img, x
			* IMG_SIZE, y * IMG_SIZE);
}

void	patrol(t_vars *vars, time_t now)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < vars->map_height)
	{
		x = 0;
		while (x < vars->map_width)
		{
			if (vars->map[y][x] == 'F')
			{
				vars->map[y][x] = '0';
				vars->map[y][x+1] = 'F';
			}
			x++;
		}
		y++;
	}

}

int	rendering(t_vars *vars)
{
	size_t	x;
	size_t	y;
	time_t	now;
	char	*move;

	now = time(NULL);
	move = ft_itoa(vars->move);
	patrol(vars, now);
	y = 0;
	while (y < vars->map_height)
	{
		x = 0;
		while (x < vars->map_width)
		{
			mlx_string_put(vars->mlx, vars->win, 10, 20, 0xFFFFFF, move);
			put_image(vars, x, y, now);
			x++;
		}
		y++;
	}
	free(move);
	return (0);
}
