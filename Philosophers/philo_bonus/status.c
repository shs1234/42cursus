/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 03:32:03 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/31 01:51:39 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	pickup_fork(t_philo *philo)
{
	if (philo->left == 0)
	{
		sem_wait(philo->info->fork);
		philo->left = 1;
		print_msg(philo, "has taken a fork\n");
	}
	if (philo->right == 0)
	{
		sem_wait(philo->info->fork);
		philo->right = 1;
		print_msg(philo, "has taken a fork\n");
	}
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
	print_msg(philo, "is eating\n");
	philo->eat_count++;
	philo->starving = get_time_ms();
	usleep(philo->info->time_to_eat * 1000);
	sem_post(philo->info->fork);
	sem_post(philo->info->fork);
	philo->left = 0;
	philo->right = 0;
	philo->status = SLEEP;
}

void	sleep_philo(t_philo *philo)
{
	print_msg(philo, "is sleeping\n");
	usleep(philo->info->time_to_sleep * 1000);
	philo->status = THINK;
}

void	think_philo(t_philo *philo)
{
	print_msg(philo, "is thinking\n");
	philo->status = EAT;
}
