/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:09:47 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/09 07:24:46 by hoseoson         ###   ########.fr       */
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
	if (philo->eat_count == philo->info->must_eat)
		return ;
	if (sem_wait(philo->info->msg) == -1)
		exit(1);
	printf("%ld %d %s", get_time_ms() - philo->info->starttime, philo->i + 1,
			msg);
	if (*msg == 'd')
		exit(2);
	if (sem_post(philo->info->msg) == -1)
		exit(1);
}

void	my_msleep(int time)
{
	long	start;

	start = get_time_ms();
	while (get_time_ms() - start < time)
		usleep(BREAK);
}

int	print_error(char *str)
{
	if (str)
		printf("%s", str);
	return (1);
}
