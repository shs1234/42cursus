/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 08:46:34 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/14 04:08:51 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	up(t_vars *vars)
{
	if (vars->map[vars->player_y - 1][vars->player_x] == '1')
		return ;
	else if (vars->map[vars->player_y - 1][vars->player_x] == 'C')
		vars->c_count--;
	else if (vars->map[vars->player_y - 1][vars->player_x] == 'E'
			&& vars->c_count != 0)
		return ;
	if (vars->map[vars->player_y - 1][vars->player_x] == 'E')
		vars->exit = 1;
	vars->map[vars->player_y][vars->player_x] = '0';
	vars->player_y--;
	vars->map[vars->player_y][vars->player_x] = 'P';
	vars->move++;
	ft_putnbr_fd(vars->move, 1);
	ft_putchar_fd('\n', 1);
}
void	down(t_vars *vars)
{
	if (vars->map[vars->player_y + 1][vars->player_x] == '1')
		return ;
	else if (vars->map[vars->player_y + 1][vars->player_x] == 'C')
		vars->c_count--;
	else if (vars->map[vars->player_y + 1][vars->player_x] == 'E'
			&& vars->c_count != 0)
		return ;
	if (vars->map[vars->player_y + 1][vars->player_x] == 'E')
		vars->exit = 1;
	vars->map[vars->player_y][vars->player_x] = '0';
	vars->player_y++;
	vars->map[vars->player_y][vars->player_x] = 'P';
	vars->move++;
	ft_putnbr_fd(vars->move, 1);
	ft_putchar_fd('\n', 1);
}
void	left(t_vars *vars)
{
	if (vars->map[vars->player_y][vars->player_x - 1] == '1')
		return ;
	else if (vars->map[vars->player_y][vars->player_x - 1] == 'C')
		vars->c_count--;
	else if (vars->map[vars->player_y][vars->player_x - 1] == 'E'
			&& vars->c_count != 0)
		return ;
	if (vars->map[vars->player_y][vars->player_x - 1] == 'E')
		vars->exit = 1;
	vars->map[vars->player_y][vars->player_x] = '0';
	vars->player_x--;
	vars->map[vars->player_y][vars->player_x] = 'P';
	vars->move++;
	ft_putnbr_fd(vars->move, 1);
	ft_putchar_fd('\n', 1);
}
void	right(t_vars *vars)
{
	if (vars->map[vars->player_y][vars->player_x + 1] == '1')
		return ;
	else if (vars->map[vars->player_y][vars->player_x + 1] == 'C')
		vars->c_count--;
	else if (vars->map[vars->player_y][vars->player_x + 1] == 'E'
			&& vars->c_count != 0)
		return ;
	if (vars->map[vars->player_y][vars->player_x + 1] == 'E')
		vars->exit = 1;
	vars->map[vars->player_y][vars->player_x] = '0';
	vars->player_x++;
	vars->map[vars->player_y][vars->player_x] = 'P';
	vars->move++;
	ft_putnbr_fd(vars->move, 1);
	ft_putchar_fd('\n', 1);
}
int	esc(void)
{
	exit(0);
}