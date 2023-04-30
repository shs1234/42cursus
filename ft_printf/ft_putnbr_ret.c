/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:28:56 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/29 23:23:04 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_nbr(long long lln, int *len)
{
	int	tab[10];
	int	i;

	i = 0;
	while (lln)
	{
		tab[i++] = lln % 10;
		lln /= 10;
	}
	while (i--)
	{
		if (ft_putchar_ret(tab[i] + '0') == -1)
			return (0);
		(*len)++;
	}
	return (1);
}

int	ft_putnbr_ret(int n)
{
	long long	lln;
	int			len;

	if (n == 0)
		return (ft_putchar_ret('0'));
	len = 0;
	lln = n;
	if (lln < 0)
	{
		if (ft_putchar_ret('-') == -1)
			return (-1);
		lln *= -1;
		len++;
	}
	if (!ft_print_nbr(lln, &len))
		return (-1);
	return (len);
}
