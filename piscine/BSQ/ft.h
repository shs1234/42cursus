/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:54:39 by hoseoson          #+#    #+#             */
/*   Updated: 2023/02/02 06:34:40 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map_data
{
	int		row;
	int		col;
	char	emp;
	char	obs;
	char	fill;
	int		i;
	int		j;
	int		max;
	int		lb;
}			t_map_data;

char	*ft_read_map(char *filename, int len);
int		ft_count_map_len(char *filename, t_map_data *map_data);
int		ft_make_map(char *filename, char ***map, t_map_data *map_data);
void	ft_argc_1(char **map, int **int_map, t_map_data *map_data);

int		ft_strlen(char *str);
char	*ft_strdup(char *src, int len);
int		ft_in_charset(char c, char *charset);
char	**ft_split(char *str, char *charset);

int		ft_data_in_str(char *str, t_map_data *map_data);
int		ft_valid_row(char **map, t_map_data *map_data);
int		ft_valid_data(t_map_data *map_data);
int		ft_map_data(char **map, t_map_data *map_data);
int		ft_valid_map(char **map, t_map_data *map_data);

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_str_is_printable(char *str);
int		ft_atoi(char *str);

void	ft_calc_map(char **map, int **int_map, t_map_data map_data);
int		**ft_char_to_num(char **map, int **int_map, t_map_data map_data);

void	ft_print_map(int **map, t_map_data map_data);

#endif