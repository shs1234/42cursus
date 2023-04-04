/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:26:54 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/05 05:36:38 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int			sign;
	long long	res;
	int			cutlim;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	cutlim = __LONG_MAX__ % 10;
	// printf("cutlim : %d ", cutlim);
	while (ft_isdigit(*str))
	{
		res = (10 * res) + (*str - '0');
		if (res >= __LONG_MAX__ / 10)
		{
			printf("%lld\n", res);
			str++;
			if (ft_isdigit(*str))
			{
				if (sign == 1 && (*str - '0') >= cutlim)
					return ((int)__LONG_MAX__);
				else if (sign == -1 && (*str - '0') >= cutlim + 1)
					return ((int)((__LONG_MAX__ * -1) - 1));
				else
					return (((res) + (*str - '0')) * sign);
			}
			else
				return (res * sign);
		}
		str++;
	}
	return (res * sign);
}
