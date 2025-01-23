/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:08:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/09 07:02:11 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	if (!(ac == 5 || ac == 6))
		return (print_error("Error : ac == 5 || ac == 6\n"));
	if (!(ft_is_valid(ac, av) && info_init(&info, ac, av) && philo_init(&info,
				&philo) && open_sem(&info)))
		return (print_error("Error\n"));
	child_process(philo);
	if (!wait_kill_process(philo))
		return (print_error("Error\n"));
	return (0);
}
