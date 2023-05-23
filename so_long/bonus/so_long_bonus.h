/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:33:19 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/23 17:21:00 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../minilibx_mac/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <time.h>

# define BUFFER_SIZE 42
# define IMG_SIZE 32

# define K_ESC 53
# define K_AR_L 123
# define K_AR_R 124
# define K_AR_U 126
# define K_AR_D 125

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
	int		c_count;
	int		move;
	int		exit;
	t_img	empty;
	t_img	wall;
	t_img	c[3];
	t_img	e[4];
	t_img	p[4];
	t_img	f[4];
}			t_vars;

// GNL
int			ft_has_newline(char *buf);
void		ft_free(char **mem);
char		*get_next_line(int fd);

// map
int			make_map(char *filename, t_vars *vars);
int			valid_map(t_vars *vars);

// utils
void		error(char *msg);
int			return_index(char *str, char c);
int			line_count(char *filename);

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
void		put_image(t_vars *vars, int x, int y, time_t now);

#endif