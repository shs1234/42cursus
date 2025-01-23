/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:12:54 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/28 03:19:17 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_sa(t_stack *a)
{
	if (a->count > 1)
		ft_swap(&a->head->n, &a->head->next->n);
}

void	ft_sb(t_stack *b)
{
	if (b->count > 1)
		ft_swap(&b->head->n, &b->head->next->n);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	if (a->count > 1)
		ft_swap(&a->head->n, &a->head->next->n);
	if (b->count > 1)
		ft_swap(&b->head->n, &b->head->next->n);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (b->count > 0)
	{
		temp = b->head;
		if (b->head->next)
		{
			b->head = b->head->next;
			b->head->prev = NULL;
		}
		else
		{
			b->head = NULL;
			b->tail = NULL;
		}
		temp->next = a->head;
		a->head = temp;
		if (a->head->next)
			a->head->next->prev = temp;
		else
			a->tail = a->head;
		a->count++;
		b->count--;
	}
}

void	ft_pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (a->count > 0)
	{
		temp = a->head;
		if (a->head->next)
		{
			a->head = a->head->next;
			a->head->prev = NULL;
		}
		else
		{
			a->head = NULL;
			a->tail = NULL;
		}
		temp->next = b->head;
		b->head = temp;
		if (b->head->next)
			b->head->next->prev = temp;
		else
			b->tail = b->head;
		b->count++;
		a->count--;
	}
}
