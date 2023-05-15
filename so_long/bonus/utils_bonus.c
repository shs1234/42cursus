/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:52:35 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/15 18:43:57 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(EXIT_FAILURE);
}

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
	return (-1);
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
		error("fd");
	close(fd);
	return (i);
}
