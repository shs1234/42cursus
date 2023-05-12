/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:33:19 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/12 07:15:42 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
// # include "minilibx/mlx.h"
# include "key_linux.h"
// # include "key_mac.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 42

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_map
{
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
}			t_map;

// GNL
int			ft_has_newline(char *buf);
void		ft_free(char **mem);
char		*get_next_line(int fd);

// map
int			make_map(char *filename, t_map *map_data);
int			valid_map(t_map *map_data);

// utils
void		error(char *msg);

#endif