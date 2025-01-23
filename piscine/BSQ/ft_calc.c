/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:07:43 by hoseoson          #+#    #+#             */
/*   Updated: 2023/02/02 03:44:18 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	**ft_char_to_num(char **map, int **int_map, t_map_data map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data.row + 1)
	{
		j = 0;
		while (j < map_data.col + 1)
		{
			if (i > 0 && j > 0)
			{
				if (map[i][j - 1] == map_data.emp)
					int_map[i][j] = 1;
				else if (map[i][j - 1] == map_data.obs)
					int_map[i][j] = 0;
			}
			else
				int_map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (int_map);
}

int	ft_min_plus_1(int **int_map, int i, int j)
{
	int	min;

	if (int_map[i - 1][j] > int_map[i][j - 1])
		min = int_map[i][j - 1];
	else
		min = int_map[i - 1][j];
	if (min > int_map[i - 1][j - 1])
		min = int_map[i - 1][j - 1];
	return (min + 1);
}

void	ft_sum_map(int **int_map, t_map_data *map_data)
{
	int	i;
	int	j;

	map_data->max = 0;
	i = -1;
	while (++i < map_data->row + 1)
	{
		j = -1;
		while (++j < map_data->col + 1)
		{
			if (int_map[i][j] != 0)
			{
				int_map[i][j] = ft_min_plus_1(int_map, i, j);
				if (int_map[i][j] > map_data->max)
				{
					map_data->max = int_map[i][j];
					map_data->i = i;
					map_data->j = j;
				}
			}
		}
	}
}

void	ft_draw_max(int **int_map, t_map_data map_data)
{
	int	i;
	int	j;

	i = map_data.i;
	while (i > map_data.i - map_data.max)
	{
		j = map_data.j;
		while (j > map_data.j - map_data.max)
		{
			int_map[i][j] = map_data.max + 1;
			j--;
		}
		i--;
	}
}

void	ft_calc_map(char **map, int **int_map, t_map_data map_data)
{
	int	i;

	i = 0;
	int_map = (int **)malloc(sizeof(int *) * (map_data.row + 1));
	while (i < map_data.row + 1)
	{
		int_map[i] = (int *)malloc(sizeof(int) * (map_data.col + 1));
		i++;
	}
	ft_char_to_num(map, int_map, map_data);
	ft_sum_map(int_map, &map_data);
	ft_draw_max(int_map, map_data);
	ft_print_map(int_map, map_data);
}
