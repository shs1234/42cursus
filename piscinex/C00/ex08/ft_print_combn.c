/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:28:18 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/15 17:46:12 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab(int n, int tab[])
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (tab[0] != 10 - n)
		write(1, ", ", 2);
}

void	ft_set_tab(int n, int tab[])
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (tab[n - 1 - i] >= 9 - i)
			i++;
		else
		{
			tab[n - 1 - i] += 1;
			while (i > 0)
			{
				tab[n - i] = tab[n - 1 - i] + 1;
				i--;
			}
			return ;
		}
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];
	int	i;

	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	while (tab[0] < 10 - n)
	{
		ft_print_tab(n, tab);
		tab[n - 1] += 1;
		if (tab[n - 1] == 10)
			ft_set_tab(n, tab);
	}
	ft_print_tab(n, tab);
}

// int	main(void)
// {
// 	ft_print_combn(3);
// }
