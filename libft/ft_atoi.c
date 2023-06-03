/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:26:54 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/03 06:59:43 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
		if (ft_isdigit(*(str + 1)) && (res > cutlim || (res == cutlim && *(str
						+ 1) - '0' >= cutoff) || (len == longlen - 1
					&& res < cutlim && ft_isdigit(*(str + 2)))))
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

int	ft_atoi(const char *str)
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
