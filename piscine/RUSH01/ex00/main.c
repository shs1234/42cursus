/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:02:06 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/22 20:33:19 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_condition(char *str, int *tab, int index, int n);
int	ft_input_check(char **av);

void	ft_print_tab(int *tab)
{
	int		i;
	char	c;

	i = 0;
	while (i < 16)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		if (i % 4 != 3)
			write(1, " ", 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
		i++;
	}
}

void	ft_put(char *str, int *tab, int index, int n)
{
	if (index == 16 && tab[16] == 0)
	{
		tab[16] = 1;
		ft_print_tab(tab);
	}
	else
	{
		if (ft_condition(str, tab, index, n))
		{
			tab[index] = n;
			ft_put(str, tab, index + 1, 1);
		}
		if (n < 4)
			ft_put(str, tab, index, n + 1);
	}
}

int	main(int ac, char **av)
{
	int	tab[17];

	tab[16] = 0;
	if (ac == 2)
	{
		if (ft_input_check(av))
		{
			ft_put(av[1], tab, 0, 1);
			if (tab[16] == 0)
				write(1, "Error\n", 6);
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
