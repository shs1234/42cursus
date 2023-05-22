/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:08:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/22 13:05:26 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_msg(t_philo *philo, char *msg)
{
	printf("%ld %d %s", get_time_ms() - philo->info->starttime, philo->i + 1,
			msg);
}

void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->starving = get_time_ms();
	if (philo->i % 2 == 1)
		usleep(100);
	while (philo->eat_count != philo->info->must_eat)
	{
		if (philo->info->died == 1)
			break ;
		if (philo->status == EAT)
		{
			pthread_mutex_lock(&philo->info->mutex);
			if (philo->right == 0)
			{
				if (philo->info->fork[philo->i] == 0)
				{
					philo->right = 1;
					philo->info->fork[philo->i] = 1;
					print_msg(philo, "has taken a fork\n");
				}
			}
			if (philo->left == 0)
			{
				if (philo->info->fork[(philo->i + philo->info->n - 1)
					% philo->info->n] == 0)
				{
					philo->left = 1;
					philo->info->fork[(philo->i + philo->info->n - 1)
						% philo->info->n] = 1;
					print_msg(philo, "has taken a fork\n");
				}
			}
			pthread_mutex_unlock(&philo->info->mutex);
			if (get_time_ms() - philo->starving >= philo->info->time_to_die)
			{
				philo->info->died = 1;
				print_msg(philo, "died\n");
				break ;
			}
			if (philo->right == 0 || philo->left == 0)
				continue ;
			philo->starving = get_time_ms();
			print_msg(philo, "is eating\n");
			philo->eat_count++;
			usleep(philo->info->time_to_eat * 1000);
			philo->right = 0;
			philo->left = 0;
			// 포크 놓을때도 뮤텍스? 해야할듯.
			philo->info->fork[philo->i] = 0;
			philo->info->fork[(philo->i + philo->info->n - 1)
				% philo->info->n] = 0;
			philo->status = SLEEP;
		}
		else if (philo->status == SLEEP)
		{
			print_msg(philo, "is sleeping\n");
			philo->status = THINK;
			usleep(philo->info->time_to_sleep * 1000);
		}
		else if (philo->status == THINK)
		{
			print_msg(philo, "is thinking\n");
			philo->status = EAT;
		}
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
		i++;
	}
	pthread_mutex_destroy(&philo->info->mutex);
	return (0);
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
	info->died = 0;
	*philo = malloc(sizeof(t_philo) * info->n);
	info->fork = malloc(sizeof(int) * info->n);
	if (!*philo || !info->fork)
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
	return (0);
}

// 인풋값 음수 유효성, 최대값 설정 등 검사