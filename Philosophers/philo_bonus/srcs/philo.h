/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:08:18 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/09 07:04:46 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define EAT 0
# define SLEEP 1
# define THINK 2

# define BREAK 200

# define SEMFORK "/my_semaphore"
# define SEMMSG "/my_semaphore2"
# define SEMSTARVING "/my_semaphore3"

typedef struct s_info
{
	int			n;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	sem_t		*fork;
	sem_t		*msg;
	sem_t		*starving;
	long		starttime;
}				t_info;

typedef struct s_philo
{
	int			i;
	pid_t		pid;
	int			get_fork;
	int			status;
	int			eat_count;
	long		starving;
	pthread_t	threads;
	t_info		*info;
}				t_philo;

// ft_atoi
int				ft_atoi(const char *str);
int				ft_numlen(long long n);

// utils
int				ft_isdigit(int c);
long			get_time_ms(void);
void			print_msg(t_philo *philo, char *msg);
void			my_msleep(int time);
int				print_error(char *str);

// Philosophers
void			child_process(t_philo *philo);
int				wait_kill_process(t_philo *philo);

// input_valid.c
int				ft_is_valid(int ac, char **av);

// init.c
int				info_init(t_info *info, int ac, char **av);
int				philo_init(t_info *info, t_philo **philo);
int				open_sem(t_info *info);
int				sem_close_unlink(t_info *info);

#endif
