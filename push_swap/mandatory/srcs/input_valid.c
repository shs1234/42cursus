/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:14:47 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/02 21:13:48 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// int	ft_isint(char *n)
// {
// 	int	res;
// 	int	sign;

// 	res = 0;
// 	sign = 1;
// 	if (!*n)
// 		return (0);
// 	if (*n == '+' || *n == '-')
// 	{
// 		if (*n == '-')
// 			sign *= -1;
// 		n++;
// 		if (!*n)
// 			return (0);
// 	}
// 	while (*n)
// 	{
// 		if (!ft_isdigit(*n))
// 			return (0);
// 		res = (res * 10) + (*n - '0');
// 		if ((sign == 1 && res * sign < 0) || (sign == -1 && res * sign > 0))
// 			return (0);
// 		n++;
// 	}
// 	return (1);
// }

static int	ft_numlen(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_makei(const char *str, int sign, int cutoff, long long cutlim)
{
	long long	res;
	int			len;
	int			longlen;

	res = 0;
	len = 0;
	longlen = ft_numlen(__LONG_MAX__);
	while (ft_isdigit(*str))
	{
		res = (10 * res) + (*str - '0');
		len++;
		if ((res > cutlim && ft_isdigit(*(str + 1))) || (res == cutlim
				&& ft_isdigit(*(str + 1)) && *(str + 1) - '0' >= cutoff)
			|| (len == longlen - 1 && res < cutlim && ft_isdigit(*(str + 1))
				&& ft_isdigit(*(str + 2))))
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		str++;
	}
	return (res * sign);
}

int	ft_isint(const char *str)
{
	int			sign;
	long long	cutlim;
	int			cutoff;

	cutlim = __LONG_MAX__ / 10;
	cutoff = __LONG_MAX__ % 10;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	if (sign == -1)
		cutoff++;
	return (ft_makei(str, sign, cutoff, cutlim));
}

// atoi 함수로 값 받아온 다음에 -1 0(오버플로)값이 진짜 -1 0 인지 확인하면 될듯.

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
