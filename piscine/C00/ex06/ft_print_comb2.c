/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:21:34 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/12 22:04:09 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_nums(int n1, int n2)
{
	if (n1 > 9)
	{
		ft_putchar(n1 / 10 + '0');
		ft_putchar(n1 % 10 + '0');
	}
	else
	{
		ft_putchar('0');
		ft_putchar(n1 % 10 + '0');
	}
	ft_putchar(' ');
	if (n2 > 9)
	{
		ft_putchar(n2 / 10 + '0');
		ft_putchar(n2 % 10 + '0');
	}
	else
	{
		ft_putchar('0');
		ft_putchar(n2 % 10 + '0');
	}
}

void	ft_print_comb2(void)
{
	int	n1;
	int	n2;

	n1 = 0;
	while (n1 <= 98)
	{
		n2 = n1 + 1;
		while (n2 <= 99)
		{
			print_nums(n1, n2);
			if (!(n1 == 98 && n2 == 99))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			n2++;
		}
		n1++;
	}
}

// int	main(void)
// {
// 	ft_print_comb2();
// }
