/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 00:54:14 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/01 10:26:30 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->starving = get_time_ms();
	if (philo->i % 2 == 1)
		usleep(1000);
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
	pthread_t	*threads;
	int			i;

	threads = malloc(sizeof(pthread_t) * philo->info->n);
	if (!threads)
		return (0);
	i = -1;
	while (++i < philo->info->n)
		pthread_create(&threads[i], NULL, philosopher, &philo[i]);
	i = -1;
	while (++i < philo->info->n)
		pthread_join(threads[i], NULL);
	pthread_mutex_destroy(&philo->info->mutex);
	free(threads);
	return (0);
}
