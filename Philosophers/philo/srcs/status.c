/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 03:32:03 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/07 20:32:32 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	pickup_fork(t_philo *philo)
{
	int	left;
	int	right;

	left = (philo->i + philo->info->n - 1) % philo->info->n;
	right = philo->i;
	pthread_mutex_lock(&philo->info->fork_mutex[left]);
	if (philo->left == 0 && philo->info->fork[left] == 0)
	{
		philo->info->fork[left] = 1;
		philo->left = 1;
		print_msg(philo, "has taken a fork\n");
	}
	pthread_mutex_unlock(&philo->info->fork_mutex[left]);
	pthread_mutex_lock(&philo->info->fork_mutex[right]);
	if (philo->right == 0 && philo->info->fork[right] == 0)
	{
		philo->info->fork[right] = 1;
		philo->right = 1;
		print_msg(philo, "has taken a fork\n");
	}
	pthread_mutex_unlock(&philo->info->fork_mutex[right]);
}

static void	putdown_fork(t_philo *philo)
{
	int	left;
	int	right;

	left = (philo->i + philo->info->n - 1) % philo->info->n;
	right = philo->i;
	pthread_mutex_lock(&philo->info->fork_mutex[left]);
	philo->info->fork[left] = 0;
	philo->left = 0;
	pthread_mutex_unlock(&philo->info->fork_mutex[left]);
	pthread_mutex_lock(&philo->info->fork_mutex[right]);
	philo->info->fork[philo->i] = 0;
	philo->right = 0;
	pthread_mutex_unlock(&philo->info->fork_mutex[right]);
}

void	eat_philo(t_philo *philo)
{
	pickup_fork(philo);
	if (get_time_ms() - philo->starving >= philo->info->time_to_die)
	{
		print_msg(philo, "died\n");
		pthread_mutex_lock(&philo->info->died_mutex);
		philo->info->died = 1;
		pthread_mutex_unlock(&philo->info->died_mutex);
		return ;
	}
	if (!(philo->left && philo->right))
		return ;
	philo->eat_count++;
	usleep(BREAK);
	print_msg(philo, "is eating\n");
	philo->starving = get_time_ms();
	my_msleep(philo->info->time_to_eat);
	putdown_fork(philo);
	philo->status = SLEEP;
}

void	sleep_philo(t_philo *philo)
{
	print_msg(philo, "is sleeping\n");
	my_msleep(philo->info->time_to_sleep);
	philo->status = THINK;
}

void	think_philo(t_philo *philo)
{
	print_msg(philo, "is thinking\n");
	philo->status = EAT;
}
