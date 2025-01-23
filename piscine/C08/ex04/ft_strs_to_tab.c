/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:21:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/28 09:09:37 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (!dup)
		return (0);
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stock;

	i = 0;
	stock = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock)
		return (0);
	while (i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i]);
		i++;
	}
	stock[i].str = 0;
	return (stock);
}

// #include <unistd.h>
// void	ft_putstr(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// }

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// void	ft_except(int nb)
// {
// 	if (nb == 0)
// 		ft_putchar('0');
// 	else if (nb == -2147483648)
// 		write(1, "-2147483648", 11);
// 	return ;
// }

// void	ft_putnbr(int nb)
// {
// 	int	i;
// 	int	tab[20];

// 	i = 0;
// 	if (nb == 0 || nb == -2147483648)
// 	{
// 		ft_except(nb);
// 		return ;
// 	}
// 	if (nb < 0)
// 	{
// 		ft_putchar('-');
// 		nb *= -1;
// 	}
// 	while (nb)
// 	{
// 		tab[i++] = nb % 10;
// 		nb /= 10;
// 	}
// 	while (--i >= 0)
// 		ft_putchar(tab[i] + '0');
// }

// void	ft_show_tab(struct s_stock_str *par)
// {
// 	int	i;

// 	i = 0;
// 	while (par[i].str)
// 	{
// 		ft_putstr(par[i].str);
// 		ft_putchar('\n');
// 		ft_putnbr(par[i].size);
// 		ft_putchar('\n');
// 		ft_putstr(par[i].copy);
// 		ft_putchar('\n');
// 		i++;
// 	}
// }

// int main(int ac, char **av)
// {
// 	ft_show_tab(ft_strs_to_tab(ac, av));
// }