/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 02:56:54 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/03 09:08:21 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrab(t_stack *a, t_stack *b, int *count)
{
	int	i;
	int	count0_copy;

	i = 0;
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
	int		n_copy;
	t_node	*node;

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
