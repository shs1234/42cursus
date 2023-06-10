/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 00:54:14 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/10 16:24:07 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->starving = get_time_ms();
	while (!philo->info->start)
		;
	if (philo->i % 2 == 1)
		usleep(100);
	while (!philo->info->died && philo->eat_count != philo->info->must_eat)
	{
		if (philo->status == EAT)
			eat_philo(philo);
		else if (philo->status == SLEEP)
			sleep_philo(philo);
		else if (philo->status == THINK)
			think_philo(philo);
	}
	if (philo->eat_count == philo->info->must_eat)
		philo->info->im_full++;
	return (arg);
}

int	philosophers(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->n)
	{
		if (pthread_create(&philo->info->threads[i], NULL, philosopher,
				&philo[i]))
			return (0);
	}
	philo->info->start = 1;
	while (!philo->info->died && philo->info->im_full != philo->info->n)
		;
	return (1);
}
