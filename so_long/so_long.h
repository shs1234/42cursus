/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:33:19 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/16 12:57:34 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx_mac/mlx.h"
// # include "key_linux.h"
# include "key_mac.h"
// # include "minilibx-linux/mlx.h"
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
	size_t	map_width;
	size_t	map_height;
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
int			return_index(char *str, char c);
int			line_count(char *filename);

// move
void		key_up(t_vars *vars);
void		key_down(t_vars *vars);
void		key_left(t_vars *vars);
void		key_right(t_vars *vars);

#endif