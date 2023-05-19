/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:09:47 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/17 10:44:41 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isint(char *n)
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
