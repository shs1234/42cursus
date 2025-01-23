/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:48:23 by hoseoson          #+#    #+#             */
/*   Updated: 2023/02/02 10:56:17 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int ac, char **av)
{
	int			i;
	char		**map;
	int			**int_map;
	t_map_data	map_data;

	map = 0;
	int_map = 0;
	i = 0;
	if (ac == 1)
		ft_argc_1(map, int_map, &map_data);
	while (++i < ac)
	{
		if (ft_make_map(av[i], &map, &map_data))
		{
			if (ft_valid_map(map, &map_data))
				ft_calc_map(map, int_map, map_data);
			else
				write(1, "map error\n", 10);
		}
		else
			write(1, "map error\n", 10);
		if (i != ac - 1)
			write(1, "\n", 1);
	}
	return (0);
}
