/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:33:27 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/28 04:21:14 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_inst(t_stack *a)
{
	t_list	*tmp;

	while (*a->list_head)
	{
		ft_putstr_fd((*a->list_head)->content, STDOUT_FILENO);
		tmp = *a->list_head;
		*a->list_head = (*a->list_head)->next;
		free(tmp);
	}
}

static void	ft_ac3(t_stack *a)
{
	int	i;

	i = ft_whereisbig(a->head, 3);
	if (i == 2)
		ft_rra(a);
	else if (i == 1)
		ft_ra(a);
	if (a->head->n > a->head->next->n)
		ft_sa(a);
}

static void	ft_ac5(t_stack *a, t_stack *b)
{
	int	i;
	int	mid;

	i = 0;
	mid = ft_3rd_5(a->head);
	while (i < 2)
	{
		if (a->head->n < mid)
		{
			ft_pb(a, b);
			i++;
		}
		else
			ft_ra(a);
	}
	ft_ac3(a);
	ft_pa(a, b);
	ft_pa(a, b);
	if (a->head->n > a->head->next->n)
		ft_sa(a);
}

void	ft_sorting(t_stack *a, t_stack *b)
{
	if (a->count == 3)
		ft_ac3(a);
	else if (a->count == 5)
		ft_ac5(a, b);
	else
		ft_atob(a, b, a->count);
	ft_print_inst(a);
}
