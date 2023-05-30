/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 03:32:03 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/30 04:25:44 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex);
	if (philo->left == 0 && philo->info->fork[(philo->i + philo->info->n - 1)
		% philo->info->n] == 0)
	{
		philo->info->fork[(philo->i + philo->info->n - 1) % philo->info->n] = 1;
		philo->left = 1;
		print_msg(philo, "has taken a fork\n");
	}
	if (philo->right == 0 && philo->info->fork[philo->i] == 0)
	{
		philo->info->fork[philo->i] = 1;
		philo->right = 1;
		print_msg(philo, "has taken a fork\n");
	}
	pthread_mutex_unlock(&philo->info->mutex);
}

void	eat_philo(t_philo *philo)
{
	pickup_fork(philo);
	if (get_time_ms() - philo->starving >= philo->info->time_to_die)
	{
		philo->info->died = 1;
		print_msg(philo, "died\n");
		return ;
	}
	if (philo->right == 0 || philo->left == 0)
		return ;
	philo->starving = get_time_ms();
	print_msg(philo, "is eating\n");
	philo->eat_count++;
	usleep(philo->info->time_to_eat * 1000);
	philo->info->fork[(philo->i + philo->info->n - 1) % philo->info->n] = 0;
	philo->info->fork[philo->i] = 0;
	philo->left = 0;
	philo->right = 0;
	philo->status = SLEEP;
}

void	sleep_philo(t_philo *philo)
{
	print_msg(philo, "is sleeping\n");
	philo->status = THINK;
	usleep(philo->info->time_to_sleep * 1000);
}

void	think_philo(t_philo *philo)
{
	print_msg(philo, "is thinking\n");
	philo->status = EAT;
}
