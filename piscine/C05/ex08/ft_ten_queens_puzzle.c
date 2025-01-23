/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 03:41:35 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/23 04:48:45 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_tab(int *tab)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_condition(int *tab, int index, int n)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (tab[i] == n || ft_abs(index - i) == ft_abs(tab[i] - n))
			return (0);
		i++;
	}
	return (1);
}

void	ft_put_q(int *tab, int index, int n)
{
	if (index == 10)
	{
		tab[10]++;
		ft_print_tab(tab);
	}
	else
	{
		if (ft_condition(tab, index, n))
		{
			tab[index] = n;
			ft_put_q(tab, index + 1, 0);
		}
		if (n < 9)
			ft_put_q(tab, index, n + 1);
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	tab[11];

	tab[10] = 0;
	ft_put_q(tab, 0, 0);
	return (tab[10]);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d", ft_ten_queens_puzzle());
// }