/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:33:19 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/12 10:15:45 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../minilibx_mac/mlx.h"
# include <fcntl.h>
# include <time.h>

# define IMG_SIZE 32

# define MAX_HEIGHT 24
# define MAX_WIDTH 50

# define K_ESC 53
# define K_AR_L 123
# define K_AR_R 124
# define K_AR_U 126
# define K_AR_D 125

# define UP 0
# define DOWN 1
# define RIGHT 2
# define LEFT 3

typedef struct s_img
{
	void	*img;
	int		img_width;
	int		img_height;
}			t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	size_t	map_width;
	size_t	map_height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		c_count;
	int		f_count;
	int		**enemy;
	int		move;
	int		exit;
	time_t	now;
	t_img	empty;
	t_img	wall;
	t_img	c[3];
	t_img	e[4];
	t_img	p[4];
	t_img	f[4];
}			t_vars;

// map
int			make_map(char *filename, t_vars *vars);
int			valid_map(t_vars *vars);

// utils
void		error(char *msg);
int			return_index(char *str, char c);
void		map_clear(char **map);
int			close_win(void);

// move
void		key_up(t_vars *vars);
void		key_down(t_vars *vars);
void		key_left(t_vars *vars);
void		key_right(t_vars *vars);

// img
void		img_01(t_vars *vars);
void		img_c(t_vars *vars);
void		img_e(t_vars *vars);
void		img_p(t_vars *vars);
void		img_f(t_vars *vars);

// rendering
int			rendering(t_vars *vars);
void		put_image(t_vars *vars, int x, int y);

// enemy
int			enemy_init(t_vars *vars);
void		patrol(t_vars *vars);

#endif