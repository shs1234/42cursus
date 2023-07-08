/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 05:41:40 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/09 07:02:55 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	info_init(t_info *info, int ac, char **av)
{
	memset(info, 0, sizeof(t_info));
	info->n = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = -1;
	info->starttime = get_time_ms();
	return (1);
}

int	philo_init(t_info *info, t_philo **philo)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * info->n);
	if (!*philo)
		return (0);
	i = -1;
	while (++i < info->n)
	{
		(*philo)[i].i = i;
		(*philo)[i].get_fork = 0;
		(*philo)[i].status = 0;
		(*philo)[i].eat_count = 0;
		(*philo)[i].info = info;
	}
	return (1);
}

int	open_sem(t_info *info)
{
	info->fork = sem_open(SEMFORK, O_CREAT | O_TRUNC, 0644, info->n);
	info->msg = sem_open(SEMMSG, O_CREAT | O_TRUNC, 0644, 1);
	info->starving = sem_open(SEMSTARVING, O_CREAT | O_TRUNC, 0644, 1);
	if (!info->fork || !info->msg || !info->starving)
		return (0);
	return (1);
}

int	sem_close_unlink(t_info *info)
{
	if (sem_close(info->fork) == -1 || sem_close(info->msg) == -1
		|| sem_unlink(SEMFORK) == -1 || sem_unlink(SEMMSG) == -1
		|| sem_close(info->starving) == -1 || sem_unlink(SEMSTARVING) == -1)
		return (0);
	return (1);
}
