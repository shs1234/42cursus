/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoa_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:39:57 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/28 17:38:26 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_btoa_2(t_stack *a, t_stack *b)
{
	if (b->head->n < b->head->next->n)
		ft_sb(b);
	ft_pa(a, b);
	ft_pa(a, b);
}

static void	ft_btoa_3(t_stack *a, t_stack *b)
{
	int	i;

	i = ft_whereisbig(b->head, 3);
	if (i == 3)
	{
		ft_rb(b);
		ft_rb(b);
		ft_pa(a, b);
		ft_rrb(b);
		ft_rrb(b);
	}
	else if (i == 2)
	{
		ft_rb(b);
		ft_pa(a, b);
		ft_rrb(b);
	}
	else if (i == 1)
		ft_pa(a, b);
	ft_btoa_2(a, b);
}

static void	ft_btoa_5(t_stack *a, t_stack *b)
{
	int	mid;
	int	i;
	int	rb;

	i = 0;
	rb = 0;
	mid = ft_3rd_5(a->head);
	while (i < 3)
	{
		if (a->head->n >= mid)
		{
			ft_pa(a, b);
			i++;
		}
		else
		{
			ft_rb(b);
			rb++;
		}
	}
	while (rb--)
		ft_rrb(b);
	ft_atob_3(a, b);
	ft_btoa_2(a, b);
}

static void	ft_btoa_divide(t_stack *a, t_stack *b, int n, int *count)
{
	int	pivot[2];

	count[0] = 0;
	count[1] = 0;
	ft_pivot(b, n, pivot);
	while (n--)
	{
		if (b->head->n < pivot[0])
		{
			ft_rb(b);
			count[0]++;
		}
		else
		{
			ft_pa(a, b);
			if (a->head->n < pivot[1])
			{
				ft_ra(a);
				count[1]++;
			}
		}
	}
}

void	ft_btoa(t_stack *a, t_stack *b, int n)
{
	int	count[2];

	if (n == 5)
		return (ft_btoa_5(a, b));
	else if (n == 3)
		return (ft_btoa_3(a, b));
	else if (n == 2)
		return (ft_btoa_2(a, b));
	else if (n == 0)
		return ;
	ft_btoa_divide(a, b, n, count);
	if (!ft_issorted(a->head, n - count[0] - count[1]))
		ft_atob(a, b, n - count[0] - count[1]);
	ft_rrab(a, b, count);
	if (!ft_issorted(a->head, count[1]))
		ft_atob(a, b, count[1]);
	if (!ft_issorted_rev(a, b, count[0]))
		ft_btoa(a, b, count[0]);
}
