/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:37:57 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/07 19:21:33 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (ft_is_valid(ac, av))
		{
			write(1, "ok\n", 3);
			ft_sorting(ac, av);
		}
		else
			ft_error();
	}
	write(1, "\n", 1);
	return (0);
}
