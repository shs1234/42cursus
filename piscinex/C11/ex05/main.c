/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:32:19 by hoseoson          #+#    #+#             */
/*   Updated: 2023/02/01 16:07:20 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_set_opers(void (**f)(int, int))
{
	f[0] = ft_plus;
	f[1] = ft_minus;
	f[2] = ft_mul;
	f[3] = ft_div;
	f[4] = ft_mod;
}

int	main(int ac, char **av)
{
	void	(*ft_oper[5])(int, int);

	ft_set_opers(ft_oper);
	if (ac == 4)
	{
		if (av[2][1] == '\0'
		&& (av[2][0] == '+' || av[2][0] == '-'
		|| av[2][0] == '*' || av[2][0] == '/' || av[2][0] == '%'))
		{
			if (av[2][0] == '+')
				ft_oper[0](ft_atoi(av[1]), ft_atoi(av[3]));
			else if (av[2][0] == '-')
				ft_oper[1](ft_atoi(av[1]), ft_atoi(av[3]));
			else if (av[2][0] == '*')
				ft_oper[2](ft_atoi(av[1]), ft_atoi(av[3]));
			else if (av[2][0] == '/')
				ft_oper[3](ft_atoi(av[1]), ft_atoi(av[3]));
			else if (av[2][0] == '%')
				ft_oper[4](ft_atoi(av[1]), ft_atoi(av[3]));
			write(1, "\n", 1);
		}
		else
			write(1, "0\n", 2);
	}
	return (0);
}
