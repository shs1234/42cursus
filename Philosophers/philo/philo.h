/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:08:18 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/19 20:42:47 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define START 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIED 4

typedef struct s_info
{
	int				n;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				*fork;
	long			starttime;
	pthread_mutex_t	mutex;
}					t_info;

typedef struct s_philo
{
	int				i;
	int				right;
	int				left;
	int				status;
	int				eat_count;
	t_info			*info;
}					t_philo;

// ft_atoi
int					ft_atoi(const char *str);

// utils
int					ft_isdigit(int c);
int					ft_isint(char *n);

#endif