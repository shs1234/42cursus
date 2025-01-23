/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 08:08:46 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/30 00:09:56 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}
