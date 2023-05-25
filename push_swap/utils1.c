/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 03:40:41 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/26 05:15:04 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	flag;

	flag = 1;
	while (flag)
	{
		i = 0;
		flag = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				flag = 1;
			}
			i++;
		}
	}
}

void	ft_pivot(t_stack *stack, int n, int *pivot)
{
	t_node	*node;
	int		i;
	int		*tab;

	node = stack->head;
	tab = malloc(sizeof(int) * n);
	if (!tab)
		ft_error();
	i = 0;
	while (node && i < n)
	{
		tab[i] = node->n;
		node = node->next;
		i++;
	}
	ft_sort_int_tab(tab, n);
	pivot[0] = tab[n / 3];
	pivot[1] = tab[(n / 3) * 2];
	free(tab);
}

int	ft_3rd_5(t_node *node)
{
	int	i;
	int	*tab;
	int	ret;

	tab = malloc(sizeof(int) * 5);
	if (!tab)
		ft_error();
	i = 0;
	while (i < 5)
	{
		tab[i] = node->n;
		node = node->next;
		i++;
	}
	ft_sort_int_tab(tab, 5);
	ret = tab[2];
	free(tab);
	return (ret);
}
