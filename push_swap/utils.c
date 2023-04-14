/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 03:40:41 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/15 04:31:59 by hoseoson         ###   ########.fr       */
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

int	ft_3rd_5(t_node *node)
{
	int	i;
	int	*tab;
	int	ret;

	tab = (int *)malloc(sizeof(int) * 5);
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

void	ft_rrab(t_stack *a, t_stack *b, int *count)
{
	int	i;
	int	count0_copy;

	i = 0;
	if (a->first_iter)
		count0_copy = 0;
	else
		count0_copy = count[0];
	while (i < count0_copy && i < count[1])
	{
		ft_rrr(a, b);
		i++;
	}
	while (i < count0_copy)
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
	int	i;
	int	big;
	int	big_index;

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
int	ft_issorted(t_node *node, int n)
{
	while (--n)
	{
		if (node->n > node->next->n)
			return (0);
		node = node->next;
	}
	return (1);
}

int	ft_issorted_rev(t_stack *a, t_stack *b, int n)
{
	int n_copy;
	t_node *node;

	node = b->head;
	n_copy = n;
	while (--n)
	{
		if (node->n < node->next->n)
			return (0);
		node = node->next;
	}
	while (n_copy--)
		ft_pa(a, b);
	return (1);
}