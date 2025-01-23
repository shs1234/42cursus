/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:54:49 by hoseoson          #+#    #+#             */
/*   Updated: 2023/02/02 06:05:24 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	sign = 1;
	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (10 * res) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_print_map(int **int_map, t_map_data map_data)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < map_data.row + 1)
	{
		j = 1;
		while (j < map_data.col + 1)
		{
			if (int_map[i][j] == 0)
				c = map_data.obs;
			else if (int_map[i][j] == map_data.max + 1)
				c = map_data.fill;
			else
				c = map_data.emp;
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
