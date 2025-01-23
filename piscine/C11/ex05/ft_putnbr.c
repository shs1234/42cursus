/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 00:43:09 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/31 16:07:10 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_except(int nb)
{
	if (nb == 0)
		ft_putchar('0');
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	return ;
}

void	ft_putnbr(int nb)
{
	int	i;
	int	tab[20];

	i = 0;
	if (nb == 0 || nb == -2147483648)
	{
		ft_except(nb);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	while (nb)
	{
		tab[i++] = nb % 10;
		nb /= 10;
	}
	while (--i >= 0)
		ft_putchar(tab[i] + '0');
}
