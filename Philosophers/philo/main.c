/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:08:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/01 06:25:32 by hoseoson         ###   ########.fr       */
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

static int	info_init(t_info *info, int ac, char **av)
{
	int	i;

	info->n = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = -1;
	info->died = 0;
	pthread_mutex_init(&info->mutex, NULL);
	info->starttime = get_time_ms();
	info->fork = malloc(sizeof(int) * info->n);
	if (!info->fork)
		return (0);
	i = -1;
	while (++i < info->n)
		info->fork[i] = 0;
	return (1);
}

static int	philo_init(t_info *info, t_philo **philo)
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

	if (valid_args(ac, av) && info_init(&info, ac, av) && philo_init(&info,
			&philo))
		philosophers(philo);
	else
		write(2, "Error\n", 6);
	return (0);
}

// 죽은다음 다다른  스스레레드  문문구구가  출출력력되되는는거.
// 출력시간을 단단순순히  av2 av3을 더해주는 방식.