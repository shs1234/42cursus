/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:09:47 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/01 07:05:33 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isposint(char *n)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (!*n)
		return (0);
	if (*n == '+' || *n == '-')
	{
		if (*n == '-')
			return (0);
		n++;
		if (!*n)
			return (0);
	}
	while (*n)
	{
		if (!ft_isdigit(*n))
			return (0);
		res = (res * 10) + (*n - '0');
		if ((sign == 1 && res * sign < 0) || (sign == -1 && res * sign > 0))
			return (0);
		n++;
	}
	return (1);
}

long	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_msg(t_philo *philo, char *msg)
{
	printf("%ld %d %s", get_time_ms() - philo->info->starttime, philo->i + 1,
			msg);
}
