/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 00:54:14 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/31 06:33:06 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->starving = get_time_ms();
	if (philo->i % 2 == 1)
		usleep(200);
	while (philo->eat_count != philo->info->must_eat)
	{
		if (philo->info->died == 1)
			break ;
		if (philo->status == EAT)
			eat_philo(philo);
		else if (philo->status == SLEEP)
			sleep_philo(philo);
		else if (philo->status == THINK)
			think_philo(philo);
	}
	return (arg);
}

int	philosophers(t_philo *philo)
{
	int	i;
	int	status;

	i = 0;
	while (i < philo->info->n)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
			return (0);
		else if (philo[i].pid == 0)
		{
			philosopher(&philo[i]);
			exit(0);
		}
		i++;
	}
	wait(&status);
	kill(0, SIGKILL);
}
