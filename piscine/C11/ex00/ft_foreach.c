/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:43:43 by hoseoson          #+#    #+#             */
/*   Updated: 2023/02/01 15:20:17 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

// #include <unistd.h>

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

// int main()
// {
// 	int tab[100];

// 	for(int i=0;i < 100;i++)
// 		tab[i] = i;
// 	ft_foreach(tab, 100, &ft_putnbr);
// }