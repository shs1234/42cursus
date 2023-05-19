/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:08:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/19 22:49:34 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*philosopher(void *arg)
{
	t_philo	*philo;
	long	now;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->status == START)
			philo->status = EAT;
		if (philo->status == EAT)
		{
			// pthread_mutex_lock(&philo->info->mutex);
			// 포크 잡기
			// 왼 오 손 확인
			// 손에 맞는 포크 있는지 확인
			// 포크 1 손 1 만들기
			// has taken a fork 출력
			// pthread_mutex_unlock(&philo->info->mutex);
			// 양손에 포크 있다면 먹기
			// 양손에 포크 없다면 continue ;
			now = get_time_ms();
			printf("%ld", now - philo->info->starttime);
			printf(" %d ", philo->i);
			philo->eat_count++;
			printf("is eating : %d\n", philo->eat_count);
			philo->status = SLEEP;
			usleep(philo->info->time_to_eat * 1000);
			// 포크 놓기
		}
		else if (philo->status == SLEEP)
		{
			now = get_time_ms();
			printf("%ld", now - philo->info->starttime);
			printf(" %d ", philo->i);
			printf("is sleeping\n");
			philo->status = THINK;
			usleep(philo->info->time_to_sleep * 1000);
		}
		else if (philo->status == THINK)
		{
			now = get_time_ms();
			printf("%ld", now - philo->info->starttime);
			printf(" %d ", philo->i);
			printf("is thinking\n");
			philo->status = EAT;
		}
		else if (philo->status == DIED)
		{
			printf("died\n");
			break ;
		}
		if (philo->eat_count == philo->info->must_eat)
			break ;
	}
	return (arg);
}
int	philosophers(t_philo *philo)
{
	pthread_t	*threads;
	int			i;

	pthread_mutex_init(&philo->info->mutex, NULL);
	threads = malloc(sizeof(pthread_t) * philo->info->n);
	if (!threads)
		return (0);
	philo->info->starttime = get_time_ms();
	i = 0;
	while (i < philo->info->n)
	{
		pthread_create(&threads[i], NULL, philosopher, &philo[i]);
		i++;
	}
	i = 0;
	while (i < philo->info->n)
	{
		pthread_join(threads[i], NULL);
		printf("%d\n", philo[i].eat_count);
		// printf("%d\n", philo[i].right);
		// printf("%d\n", philo[i].left);
		// printf("%d\n", philo[i].status);
		i++;
	}
	// printf("%d\n", philo->info->n);
	// printf("%d\n", philo->info->time_to_die);
	// printf("%d\n", philo->info->time_to_eat);
	// printf("%d\n", philo->info->time_to_sleep);
	// printf("%d\n", philo->info->must_eat);
	// printf("%d\n", philo->info->fork[0]);
	// printf("%d\n", philo->info->fork[1]);
	// printf("%d\n", philo->info->fork[2]);
	// printf("%d\n", philo->info->fork[3]);
	// printf("%d\n", philo->info->fork[4]);
	// printf("%d\n", philo->info->fork[5]);
	// printf("%p\n", &philo->info->mutex);
}

int	info_init(t_info *info, t_philo **philo, int ac, char **av)
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
	*philo = malloc(sizeof(t_philo) * info->n);
	info->fork = malloc(sizeof(int) * info->n);
	if (!*philo || !info->fork)
		return (0);
	i = -1;
	while (++i < info->n)
	{
		(*philo)[i].i = i + 1;
		(*philo)[i].left = 0;
		(*philo)[i].right = 0;
		(*philo)[i].status = 0;
		(*philo)[i].eat_count = 0;
		(*philo)[i].info = info;
		info->fork[i] = 0;
	}
	return (1);
}
int	valid_args(int ac, char **av)
{
	if (ac == 5 || ac == 6)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	if (valid_args(ac, av))
	{
		if (info_init(&info, &philo, ac, av))
			philosophers(philo);
	}
	else
		exit(EXIT_FAILURE);
	return (0);
}

// 인풋값 음수 유효성, 최대값 설정 등 검사