/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:37:57 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/26 16:20:12 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (ac == 2)
		{
			av = ft_split(av[1], ' ', &ac);
			if (ac == 1)
				ft_error();
		}
		else
		{
			ac--;
			av++;
		}
		if (ft_is_valid(ac, av))
			ft_sorting(ac, av);
		else
			ft_error();
	}
	return (0);
}
