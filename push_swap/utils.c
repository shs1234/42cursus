/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 03:40:41 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/14 08:36:21 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
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

void	ft_print_stack(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = a->head;
	printf("a : ");
	while (node)
	{
		printf("%d ", node->n);
		node = node->next;
	}
	printf("\n");
	printf("b : ");
	node = b->head;
	while (node)
	{
		printf("%d ", node->n);
		node = node->next;
	}
	printf("\n");
}

void	ft_pivot(t_stack *stack, int n, int *pivot)
{
	t_node	*node;
	int		i;
	int		*tab;

	node = stack->head;
	tab = (int *)malloc(sizeof(int) * n);
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

void	ft_rrab(t_stack *a, t_stack *b, int *count)
{
	int	i;

	i = 0;
	while (i < count[0] && i < count[1])
	{
		ft_rrr(a, b);
		i++;
	}
	while (i < count[0])
	{
		ft_rra(a);
		i++;
	}
	while (i < count[1])
	{
		ft_rrb(b);
		i++;
	}
}

int	ft_whereisbig(t_node *node, int n)
{
	int		i;
	int		big;
	int		big_index;

	big = node->n;
	i = 0;
	while (i < n)
	{
		if (big <= node->n)
		{
			big = node->n;
			big_index = i;
		}
		node = node->next;
		i++;
	}
	return (big_index + 1);
}
