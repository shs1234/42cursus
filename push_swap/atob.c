/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:36:36 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/18 00:10:23 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atob_3(t_stack *a, t_stack *b)
{
	int	i;

	i = ft_whereisbig(a->head, 3);
	if (i == 2)
	{
		ft_ra(a);
		ft_sa(a);
		ft_rra(a);
	}
	else if (i == 1)
	{
		ft_ra(a);
		ft_pb(a, b);
		ft_pb(a, b);
		ft_rra(a);
		ft_pa(a, b);
		ft_pa(a, b);
	}
	if (a->head->n > a->head->next->n)
		ft_sa(a);
}

static void	ft_atob_5(t_stack *a, t_stack *b)
{
	int	mid;
	int	i;
	int	ra;

	i = 0;
	ra = 0;
	mid = ft_3rd_5(a->head);
	while (i < 2)
	{
		if (a->head->n < mid)
		{
			ft_pb(a, b);
			i++;
		}
		else
		{
			ft_ra(a);
			ra++;
		}
	}
	while (ra--)
		ft_rra(a);
	ft_atob_3(a, b);
	ft_btoa_2(a, b);
}

static void	ft_atob_divide(t_stack *a, t_stack *b, int n, int *count)
{
	int	pivot[2];

	count[0] = 0;
	count[1] = 0;
	ft_pivot(a, n, pivot);
	while (n--)
	{
		if (a->head->n >= pivot[1])
		{
			ft_ra(a);
			count[0]++;
		}
		else
		{
			ft_pb(a, b);
			if (b->head->n >= pivot[0])
			{
				ft_rb(b);
				count[1]++;
			}
		}
	}
}

static void	ft_atob_divide_first(t_stack *a, t_stack *b, int n, int *count)
{
	int	pivot[2];

	count[0] = 0;
	count[1] = 0;
	ft_pivot(a, n, pivot);
	while (n--)
	{
		if (a->head->n >= pivot[1])
		{
			ft_ra(a);
			count[0]++;
		}
		else
		{
			ft_pb(a, b);
			if (b->head->n < pivot[0])
			{
				ft_rb(b);
				count[1]++;
			}
		}
	}
}
void	ft_atob(t_stack *a, t_stack *b, int n)
{
	int	count[2];

	if (n == 5)
		return (ft_atob_5(a, b));
	else if (n == 3)
		return (ft_atob_3(a, b));
	else if (n == 2)
	{
		if (a->head->n > a->head->next->n)
			ft_sa(a);
		return ;
	}
	if (b->count == 0)
		ft_atob_divide_first(a, b, n, count);
	else
	{
		ft_atob_divide(a, b, n, count);
		ft_rrab(a, b, count);
	}
	if (!ft_issorted(a->head, count[0]))
		ft_atob(a, b, count[0]);
	if (!ft_issorted_rev(a, b, count[1]))
		ft_btoa(a, b, count[1]);
	if (!ft_issorted_rev(a, b, n - count[0] - count[1]))
		ft_btoa(a, b, n - count[0] - count[1]);
}
