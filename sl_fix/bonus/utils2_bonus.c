/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:06:49 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/23 22:11:12 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(EXIT_FAILURE);
}

int	ft_close(void)
{
	exit(0);
}
