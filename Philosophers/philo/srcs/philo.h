/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:08:18 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/09 15:30:51 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define EAT 0
# define SLEEP 1
# define THINK 2

typedef struct s_info
{
	int				n;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	pthread_mutex_t	*fork;
	long			starttime;
	int				died;
	pthread_t		*threads;
}					t_info;

typedef struct s_philo
{
	int				i;
	int				left;
	int				right;
	int				status;
	int				eat_count;
	long			starving;
	t_info			*info;
}					t_philo;

// ft_atoi
int					ft_atoi(const char *str);
int					ft_numlen(long long n);

// input_valid
int					ft_is_valid(int ac, char **av);

// utils
int					ft_isdigit(int c);
long				get_time_ms(void);
void				print_msg(t_philo *philo, char *msg);

// Philosophers
int					philosophers(t_philo *philo);

// status
void				eat_philo(t_philo *philo);
void				sleep_philo(t_philo *philo);
void				think_philo(t_philo *philo);

#endif