/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:08:18 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/21 09:23:19 by hoseoson         ###   ########.fr       */
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
	long			starving;
	t_info			*info;
}					t_philo;

// ft_atoi
int					ft_atoi(const char *str);

// utils
int					ft_isdigit(int c);
int					ft_isint(char *n);

#endif