/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:27:44 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/07 10:28:23 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	mutex_init(t_info *info)
{
	int	i;

	info->fork_mutex = malloc(sizeof(pthread_mutex_t) * info->n);
	if (!info->fork_mutex)
		return (0);
	i = -1;
	while (++i < info->n)
		if (pthread_mutex_init(&info->fork_mutex[i], NULL) == -1)
			return (0);
	if (pthread_mutex_init(&info->died_mutex, NULL) == -1)
		return (0);
	if (pthread_mutex_init(&info->start_mutex, NULL) == -1)
		return (0);
	if (pthread_mutex_init(&info->im_full_mutex, NULL) == -1)
		return (0);
	return (1);
}

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
	info->fork = malloc(sizeof(int) * info->n);
	info->threads = malloc(sizeof(pthread_t) * info->n);
	if (!info->fork || !info->threads)
		return (0);
	memset(info->fork, 0, sizeof(int) * info->n);
	if (!mutex_init(info))
		return (0);
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
		(*philo)[i].left = 0;
		(*philo)[i].right = 0;
		(*philo)[i].status = 0;
		(*philo)[i].eat_count = 0;
		(*philo)[i].info = info;
	}
	return (1);
}
