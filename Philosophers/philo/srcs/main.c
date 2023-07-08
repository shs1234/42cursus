/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:08:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/07 22:34:44 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	if (!(ac == 5 || ac == 6))
	{
		printf("Error : ac == 5 || ac == 6\n");
		return (1);
	}
	if (!ft_is_valid(ac, av) || !info_init(&info, ac, av) || !philo_init(&info,
			&philo) || !philosophers(philo))
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
