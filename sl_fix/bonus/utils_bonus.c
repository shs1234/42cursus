/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:52:35 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/23 22:07:15 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	return_index(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			return (i);
		i++;
		str++;
	}
	return (i);
}

int	line_count(char *filename)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd > 0)
		while (get_next_line(fd))
			i++;
	else
		error("Error\nfd");
	close(fd);
	return (i);
}

int	map_error(char *cep, t_vars *vars)
{
	if (!(cep[0] > 0 && cep[1] == 1 && cep[2] == 1))
		error("Error\ncomponent count");
	if (!valid_path(vars))
		error("Error\nno path");
	return (0);
}

void	map_clear(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
