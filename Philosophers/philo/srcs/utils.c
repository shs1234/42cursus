/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:09:47 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/28 19:43:46 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	printf("%ld %d %s", get_time_ms() - philo->info->starttime, philo->i + 1,
			msg);
	pthread_mutex_unlock(&philo->info->print_mutex);
}

void	my_msleep(int time)
{
	long	start;

	start = get_time_ms();
	while (get_time_ms() - start < time)
		usleep(100);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*uc_s;

	uc_s = s;
	while (n--)
		*uc_s++ = 0;
}

// 바쁜대기