/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:14:47 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/03 08:55:54 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

static int	ft_intornot(const char *str, int cutoff, int cutlim)
{
	int	num;
	int	len;
	int	intlen;

	num = 0;
	len = 0;
	intlen = ft_numlen(__INT_MAX__);
	while (ft_isdigit(*str))
	{
		num = (10 * num) + (*str - '0');
		len++;
		if (ft_isdigit(*(str + 1)) && (num > cutlim || (num == cutlim && *(str
						+ 1) - '0' > cutoff) || (len == intlen - 1
					&& num < cutlim && ft_isdigit(*(str + 2)))))
			return (0);
		str++;
	}
	return (1);
}

int	ft_isint(const char *str)
{
	int	cutlim;
	int	cutoff;

	cutlim = __INT_MAX__ / 10;
	cutoff = __INT_MAX__ % 10;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			cutoff++;
		str++;
		if (!ft_isdigit(*str))
			return (0);
	}
	while (*str == '0')
		str++;
	return (ft_intornot(str, cutoff, cutlim));
}

static int	ft_isdouble(char **av, int i)
{
	char	*n;

	n = av[i];
	while (--i >= 0)
	{
		if (ft_atoi(av[i]) == ft_atoi(n))
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
