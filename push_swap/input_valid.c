/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:14:47 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/18 00:27:14 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isint(char *n)
{
	long long	res;
	int			len;
	int			sign;

	res = 0;
	len = 0;
	sign = 1;
	if (!*n)
		return (0);
	if (*n == '+' || *n == '-')
	{
		if (*n == '-')
			sign *= -1;
	}
	while (*++n)
	{
		if (len > 9 || !ft_isdigit(*n))
			return (0);
		res = (res * 10) + (*n - '0');
		len++;
	}
	if (res * sign > INT_MAX || res * sign < INT_MIN)
		return (0);
	return (1);
}
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
	return (*s1 - *s2);
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
