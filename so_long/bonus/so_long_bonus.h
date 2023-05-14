/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:33:19 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/14 05:17:18 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
// # include "minilibx/mlx.h"
# include "../key_linux.h"
// # include "key_mac.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 42
# define IMG_SIZE 32

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
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		c_count;
	int		move;
	int		exit;
	t_img	imgs[5];
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

// move
void		up(t_vars *vars);
void		down(t_vars *vars);
void		left(t_vars *vars);
void		right(t_vars *vars);
int			esc(void);

#endif