/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:08:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/31 06:34:01 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	valid_args(int ac, char **av)
{
	int	i;

	if (!(ac == 5 || ac == 6))
		return (0);
	i = 0;
	while (++i < ac)
	{
		if (!ft_isposint(av[i]))
			return (0);
	}
	return (1);
}

static int	info_init(t_info *info, t_philo **philo, int ac, char **av)
{
	info->n = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = -1;
	info->died = 0;
	info->starttime = get_time_ms();
	return (1);
}

static int	philo_init(t_info *info, t_philo **philo, int ac, char **av)
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

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	if (valid_args(ac, av) && info_init(&info, &philo, ac, av)
		&& philo_init(&info, &philo, ac, av))
	{
		info.fork = sem_open("/my_semaphore", O_CREAT | O_TRUNC, 0644, info.n);
		if (!info.fork)
		{
			perror("sem_open");
			return (0);
		}
		philosophers(philo);
		sem_close(info.fork);
		sem_unlink("/my_semaphore");
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
