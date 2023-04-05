/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:28:56 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/05 23:04:07 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_nbr(long long lln, int fd, int *len)
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
		if (ft_putchar_fd(tab[i] + '0', fd) == -1)
			return (0);
		(*len)++;
	}
	return (1);
}

int	ft_putnbr_fd(int n, int fd)
{
	long long	lln;
	int			len;

	lln = n;
	len = 0;
	if (lln == 0)
	{
		if (ft_putchar_fd(0 + '0', fd) == -1)
			return (-1);
		len++;
	}
	if (lln < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		lln *= -1;
		len++;
	}
	if (!ft_print_nbr(lln, fd, &len))
		return (-1);
	return (len);
}
