/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:14:47 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/26 07:26:02 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	ft_isint(char *n)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (!*n)
		return (0);
	if (*n == '+' || *n == '-')
	{
		if (*n == '-')
			sign *= -1;
		n++;
	}
	while (*n)
	{
		if (!ft_isdigit(*n))
			return (0);
		if (sign == 1)
		{
			if (res*sign < 0)
				return (0);
		}
		else
		{
			if (res*sign > 0)
				return (0);
		}
		if (res * sign > INT_MAX || res * sign < INT_MIN || !ft_isdigit(*n))
			return (0);
		res = (res * 10) + (*n - '0');
		n++;
	}
	return (1);
}

static int	ft_isdouble(char **av, int i)
{
	char	*n;

	n = av[i];
	while (--i >= 0)
	{
		if (!ft_strcmp(n, av[i]))
			return (1);
	}
	return (0);
}

int	ft_is_valid(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (!ft_isint(av[i]) || ft_isdouble(av, i))
			return (0);
		i++;
	}
	return (1);
}
