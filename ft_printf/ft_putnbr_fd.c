/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:28:56 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/05 13:15:56 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long long	lln;
	int			tab[10];
	int			i;
	int			len;

	lln = n;
	i = 0;
	len = 0;
	if (lln == 0)
		len += ft_putchar_fd(0 + '0', fd);
	if (lln < 0)
	{
		len += ft_putchar_fd('-', fd);
		lln *= -1;
	}
	while (lln)
	{
		tab[i++] = lln % 10;
		lln /= 10;
	}
	len += i;
	while (i--)
		ft_putchar_fd(tab[i] + '0', fd);
	return (len);
}
