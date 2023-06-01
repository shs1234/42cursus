/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:14:47 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/28 07:42:18 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_isint(char *n)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (!*n)
		return (0);
	if (*n == '+' || *n == '-')
	{
		if (*n == '-')
			sign *= -1;
		n++;
		if (!*n)
			return (0);
	}
	while (*n)
	{
		if (!ft_isdigit(*n))
			return (0);
		res = (res * 10) + (*n - '0');
		if ((sign == 1 && res * sign < 0) || (sign == -1 && res * sign > 0))
			return (0);
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
