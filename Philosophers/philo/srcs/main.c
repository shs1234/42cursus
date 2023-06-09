/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:08:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/09 15:39:38 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	info->starttime = get_time_ms();
	info->fork = malloc(sizeof(pthread_mutex_t) * info->n);
	info->threads = malloc(sizeof(pthread_t) * info->n);
	if (!info->fork || !info->threads)
		return (0);
	i = -1;
	while (++i < info->n)
		pthread_mutex_init(&info->fork[i], NULL);
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

	if (!(ac == 5 || ac == 6))
	{
		printf("Error : ac == 5 || ac == 6\n");
		return (0);
	}
	if (!ft_is_valid(ac, av) || !info_init(&info, ac, av) || !philo_init(&info,
			&philo) || !philosophers(philo))
		printf("Error\n");
	return (0);
}

// 죽은다음 다른  스레드  문구가  출력되는거. 출력 함수에서 죽었을 경우 작동 안하게.
// 출력함수에서 조건문 걸어도 계속 출력됨.