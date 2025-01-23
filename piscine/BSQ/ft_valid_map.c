/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:52:03 by hoseoson          #+#    #+#             */
/*   Updated: 2023/02/02 07:22:56 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_data_in_str(char *str, t_map_data *map_data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == map_data->emp || str[i] == map_data->obs))
			return (0);
		i++;
	}
	return (1);
}

int	ft_valid_row(char **map, t_map_data *map_data)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != map_data->col)
			return (0);
		if (!ft_data_in_str(map[i], map_data))
			return (0);
		i++;
	}
	if (i - 1 != map_data->row || i - 1 != map_data->lb - 1)
		return (0);
	return (1);
}

int	ft_valid_data(t_map_data *map_data)
{
	if (map_data->fill == map_data->obs)
		return (0);
	if (map_data->emp == map_data->obs)
		return (0);
	if (map_data->fill == map_data->obs)
		return (0);
	if (map_data->row < 1)
		return (0);
	return (1);
}

int	ft_map_data(char **map, t_map_data *map_data)
{
	char	*map_0;
	int		map_0_len;

	map_0 = map[0];
	map_0_len = ft_strlen(map_0);
	if (map_0_len < 4)
		return (0);
	if (!ft_str_is_printable(map_0))
		return (0);
	map_data->col = ft_strlen(map[1]);
	map_data->fill = map_0[map_0_len - 1];
	map_data->obs = map_0[map_0_len - 2];
	map_data->emp = map_0[map_0_len - 3];
	map_0[map_0_len - 3] = '\0';
	map_data->row = ft_atoi(map_0);
	if (!ft_valid_data(map_data))
		return (0);
	return (1);
}

int	ft_valid_map(char **map, t_map_data *map_data)
{
	if (map[0] == 0 || map[1] == 0)
		return (0);
	if (!ft_map_data(map, map_data))
		return (0);
	if (!ft_valid_row(map, map_data))
		return (0);
	return (1);
}
