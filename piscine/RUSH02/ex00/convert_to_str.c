/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:06:24 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/29 23:20:03 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	*ft_build_apt(char *arr, int *floor)
{
	int		len;
	int		i;
	int		j;
	int		idx;
	int		*apt;

	len = 0;
	while (arr[len])
		len++;
	*floor = (len + 2) / 3;
	apt = (int *)malloc(sizeof(int) * (*floor));
	j = 0;
	while (j < *floor)
		apt[j++] = 0;
	idx = -1;
	while (++idx < len - ((len - 1) / 3) * 3)
		apt[0] = apt[0] * 10 + (arr[idx] - '0');
	i = 0;
	while (++i < *floor)
	{
		j = -1;
		while (++j < 3)
			apt[i] = apt[i] * 10 + (arr[idx + (i - 1) * 3 + j] - '0');
	}
	return (apt);
}

void	ft_print_num(int num, char **key, char **val)
{
	char	*out;
	int		i;

	out = (char *)malloc(sizeof(char) * 4);
	out[3] = '\0';
	i = 0;
	while (out[i])
		out[i++] = '0';
	ft_print_100(num, out, key, val);
	num %= 100;
	if (num >= 20 && 99 >= num)
		ft_print_2099(num, out, key, val);
	else if (num >= 10 && 19 >= num)
		ft_print_1019(num, out, key, val);
	else if (num >= 1 && 9 >= num)
		ft_print_0109(num, out, key, val);
	free(out);
}

void	ft_print_floor(int num, int floor, char **key, char **val)
{
	char	*out;
	int		i;

	if (floor < 1)
		return ;
	if (num > 0)
	{
		out = (char *)malloc(sizeof(char) * (floor * 3 + 2));
		out[0] = '1';
		out[floor * 3 + 1] = '\0';
		i = 1;
		while (i < floor * 3 + 1)
		{
			out[i] = '0';
			i++;
		}
		write(1, " ", 1);
		ft_print(out, key, val);
		free(out);
	}
}

void	ft_floor_space(int *apt, int j, int floor)
{
	while (j < floor)
	{
		if (apt[j])
		{
			write(1, ", ", 2);
			break ;
		}
		j++;
	}
}

void	convert_to_str(char *input, char **key, char **val)
{
	int		*apt;
	int		floor;
	int		i;

	floor = 0;
	apt = ft_build_apt(input, &floor);
	i = 0;
	while (i < floor)
	{
		ft_print_num(apt[i], key, val);
		ft_print_floor(apt[i], floor - i - 1, key, val);
		if (apt[i])
			ft_floor_space(apt, i + 1, floor);
		i++;
	}
	free(apt);
	write(1, "\n", 1);
}
