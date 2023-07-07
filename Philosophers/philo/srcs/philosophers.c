/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 00:54:14 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/07 10:35:10 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	break_condition(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->died_mutex);
	if (philo->info->died)
	{
		pthread_mutex_unlock(&philo->info->died_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->died_mutex);
	if (philo->eat_count == philo->info->must_eat)
		return (1);
	return (0);
}

static void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&philo->info->start_mutex);
	pthread_mutex_unlock(&philo->info->start_mutex);
	philo->starving = get_time_ms();
	if (philo->i % 2 == 1)
		my_msleep(100);
	while (!break_condition(philo))
	{
		if (philo->status == EAT)
			eat_philo(philo);
		else if (philo->status == SLEEP)
			sleep_philo(philo);
		else if (philo->status == THINK)
			think_philo(philo);
	}
	if (philo->eat_count == philo->info->must_eat)
	{
		pthread_mutex_lock(&philo->info->im_full_mutex);
		philo->info->im_full++;
		pthread_mutex_unlock(&philo->info->im_full_mutex);
	}
	return (arg);
}

static int	monitoring(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->died_mutex);
	if (philo->info->died)
	{
		pthread_mutex_unlock(&philo->info->died_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->info->died_mutex);
	pthread_mutex_lock(&philo->info->im_full_mutex);
	if (philo->info->im_full == philo->info->n)
		return (0);
	pthread_mutex_unlock(&philo->info->im_full_mutex);
	return (1);
}

int	philosophers(t_philo *philo)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&philo->info->start_mutex);
	while (++i < philo->info->n)
		if (pthread_create(&philo->info->threads[i], NULL,
				philosopher, &philo[i]))
			return (0);
	philo->info->starttime = get_time_ms();
	pthread_mutex_unlock(&philo->info->start_mutex);
	while (monitoring(philo))
		my_msleep(1000);
	my_msleep(100);
	i = -1;
	while (++i < philo->info->n)
		if (pthread_join(philo->info->threads[i], NULL) == -1)
			return (0);
	return (1);
}
