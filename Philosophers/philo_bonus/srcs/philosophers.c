/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 00:54:14 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/10 13:23:21 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philosopher(t_philo *philo)
{
	while (philo->get_fork < 2)
	{
		if (sem_wait(philo->info->fork) == -1)
			exit(1);
		philo->get_fork++;
		print_msg(philo, "has taken a fork\n");
	}
	print_msg(philo, "is eating\n");
	philo->eat_count++;
	if (sem_wait(philo->info->sem_starving) == -1)
		exit(1);
	philo->starving = get_time_ms();
	if (sem_post(philo->info->sem_starving) == -1)
		exit(1);
	my_msleep(philo->info->time_to_eat);
	if (sem_post(philo->info->fork) == -1 || sem_post(philo->info->fork) == -1)
		exit(1);
	philo->get_fork = 0;
	print_msg(philo, "is sleeping\n");
	my_msleep(philo->info->time_to_sleep);
	print_msg(philo, "is thinking\n");
}

static void	*monitoring(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (sem_wait(philo->info->sem_starving) == -1)
			exit(1);
		if (get_time_ms() - philo->starving >= philo->info->time_to_die)
			print_msg(philo, "died\n");
		if (sem_post(philo->info->sem_starving) == -1)
			exit(1);
		usleep(BREAK);
	}
	return (arg);
}

void	child_process(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->n)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
			return ;
		else if (philo[i].pid == 0)
		{
			if (sem_wait(philo->info->sem_starving) == -1)
				exit(1);
			philo[i].starving = get_time_ms();
			if (sem_post(philo->info->sem_starving) == -1)
				exit(1);
			if (pthread_create(&philo[i].threads, NULL, &monitoring, &philo[i]))
				exit(1);
			while (philo[i].eat_count != philo[i].info->must_eat)
				philosopher(&philo[i]);
			exit(0);
		}
		usleep(BREAK);
	}
	sem_close_unlink(philo->info);
}

int	wait_kill_process(t_philo *philo)
{
	int	i;
	int	j;
	int	status;
	int	error_exit;

	i = -1;
	error_exit = 0;
	while (++i < philo->info->n)
	{
		if (waitpid(0, &status, 0) == -1)
			return (0);
		if (WEXITSTATUS(status) == 1)
			error_exit = 1;
		j = -1;
		while (WEXITSTATUS(status) && ++j < philo->info->n)
			if (kill(philo[j].pid, SIGKILL) == -1 && errno != ESRCH)
				return (0);
	}
	if (error_exit)
		return (0);
	return (1);
}
